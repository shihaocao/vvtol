#include <common/stats.hpp>
#include <algorithm>
#include <numeric>
#include <cmath>

#include <sstream>
#include <iomanip> // For std::fixed and std::setprecision

// StatsResult::StatsResult(std::vector<std::chrono::nanoseconds> deltas) : deltas_(deltas) {};

std::string StatsResult::to_string() {
    if (deltas_.size() == 0) {
        return "No Data";
    }

    std::stringstream ss;
    // Convert nanoseconds to milliseconds for display, fixed to 3 decimal places
    ss << std::fixed << std::setprecision(3);

    // Format the statistics
    ss << "[Min, Max: " << std::setw(7) << mins_ns_.count() / 1e6 << ", " << std::setw(7) << maxs_ns_.count() / 1e6 << "], "
       << "Tot:" << std::setw(9) << total_ns_.count() / 1e6 << ", "
       << "Avg:" << std::setw(7) << avgs_ns_.count() / 1e6 << ", "
       << "Percs:";

    for (auto& p : percentiles_ns_) {
        ss << " " << std::setw(7) << std::get<1>(p).count() / 1e6;
    }

    return ss.str();
}

// Stats method implementations
void Stats::calculate() {
    for (const auto& key : set_keys_) {
        auto& starts = set_starts_[key];
        auto& ends = set_ends_[key];
        std::vector<std::chrono::nanoseconds> deltas{};

        if (starts.size() > 0 && ends.size() > 0) {
        for (size_t i = 0; i < starts.size(); ++i) {
            deltas.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(ends[i] - starts[i]));
        }
        }

        set_results_[key] = std::move(Stats::calculate_result(key, deltas));
    }
}

void Stats::hist_s(const std::string &mark_name) {
    if (set_starts_.find(mark_name) == set_starts_.end()) {
        set_keys_.push_back(mark_name);
        set_starts_[mark_name] = StatsTimePointVec();
        set_ends_[mark_name] = StatsTimePointVec();
    }
    set_starts_[mark_name].push_back(StatsClock::now());
}

void Stats::hist_e(const std::string &mark_name) {
    set_ends_[mark_name].push_back(StatsClock::now());
}

std::string Stats::to_string() {
    calculate();
    std::stringstream ss;

    // Calculate the max key length
    int max_key_length = 0;
    for (const auto& pair : set_results_) {
        max_key_length = std::max(max_key_length, static_cast<int>(pair.first.length()));
    }

    // Iterate through the results and print
    for (const auto& key : set_keys_) {
        // Calculate padding for the current key
        int padding = max_key_length - key.length();
        ss << "Key: " << key << std::string(padding, ' ') << ", " << set_results_[key].to_string() << std::endl;
    }
    return ss.str();
}

// Assuming calculateSetResult becomes a private static method in Stats, here is its definition:
StatsResult Stats::calculate_result(const std::string& key, std::vector<std::chrono::nanoseconds>& deltas) {
    StatsResult result;
    result.deltas_ = deltas;
    result.key = key;
    if (deltas.empty()) {
        return result;
    }

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
