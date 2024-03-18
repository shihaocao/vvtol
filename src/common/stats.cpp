#include <common/stats.hpp>
#include <algorithm>
#include <numeric>
#include <cmath>

// Definition of StatsResult::to_string, assuming public or appropriate getters are added
std::string StatsResult::to_string() {
    std::stringstream ss;
    ss << "Total: " << total_ns_.count() << " ns, "
       << "Avg: " << avgs_ns_.count() << " ns, "
       << "Min: " << mins_ns_.count() << " ns, "
       << "Max: " << maxs_ns_.count() << " ns, "
       << "Percentiles: ";
    for (auto& p : percentiles_ns_) {
        ss << std::get<0>(p) << "%: " << std::get<1>(p).count() << " ns, ";
    }
    return ss.str();
}

// Stats method implementations
void Stats::calculate() {
    for (const auto& key : set_keys_) {
        auto& starts = set_starts_[key];
        auto& ends = set_ends_[key];
        std::vector<std::chrono::nanoseconds> deltas;

        for (size_t i = 0; i < starts.size(); ++i) {
            deltas.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(ends[i] - starts[i]));
        }

        set_results_[key] = Stats::calculate_result(deltas);
    }
    calculated = true;
}

void Stats::hist_s(const std::string &mark_name) {
    if (set_starts_.find(mark_name) == set_starts_.end()) {
        set_keys_.push_back(mark_name);
        set_starts_[mark_name] = SysTimePointVec();
        set_ends_[mark_name] = SysTimePointVec();
    }
    set_starts_[mark_name].push_back(SysClock::now());
}

void Stats::hist_e(const std::string &mark_name) {
    set_ends_[mark_name].push_back(SysClock::now());
}

std::string Stats::to_string() {
    if (!calculated) calculate();
    std::stringstream ss;
    for (const auto& key : set_keys_) {
        ss << "Key: " << key << ", " << set_results_[key].to_string() << std::endl;
    }
    return ss.str();
}

// Assuming calculateSetResult becomes a private static method in Stats, here is its definition:
StatsResult Stats::calculate_result(std::vector<std::chrono::nanoseconds>& deltas) {
    StatsResult result;
    if (deltas.empty()) return result;

    auto total = std::accumulate(deltas.begin(), deltas.end(), std::chrono::nanoseconds(0));
    auto avg = total / deltas.size();
    auto min = *std::min_element(deltas.begin(), deltas.end());
    auto max = *std::max_element(deltas.begin(), deltas.end());

    result.total_ns_ = total;
    result.avgs_ns_ = avg;
    result.mins_ns_ = min;
    result.maxs_ns_ = max;

    std::vector<float> percentiles = {25, 50, 75, 95, 99};
    for (float percentile : percentiles) {
        auto idx = static_cast<size_t>(std::ceil(percentile / 100.0 * deltas.size())) - 1;
        std::nth_element(deltas.begin(), deltas.begin() + idx, deltas.end());
        result.percentiles_ns_.emplace_back(percentile, deltas[idx]);
    }

    return result;
}
