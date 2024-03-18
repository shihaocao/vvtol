#pragma once

#include <chrono>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <optional>

class StatsResult {
  public:
    // StatsResult(std::vector<std::chrono::nanoseconds> deltas);
    // StatsResult(StatsResult&) = delete;
    // StatsResult& operator=(StatsResult&) = delete;
    // StatsResult(StatsResult&&) = default;
    // StatsResult& operator=(StatsResult&&) = default;

    std::vector<std::chrono::nanoseconds> deltas_;
    bool is_empty = false;
    std::string key;
    std::chrono::nanoseconds total_ns_;
    std::chrono::nanoseconds avgs_ns_;
    std::chrono::nanoseconds mins_ns_;
    std::chrono::nanoseconds maxs_ns_;
    std::vector<std::tuple<float, std::chrono::nanoseconds>> percentiles_ns_;
    std::string to_string();
};

class Stats {
private:
public:
  using StatsClock = std::chrono::steady_clock;
  using StatsTimePoint = std::chrono::time_point<StatsClock>;
  using StatsTimePointVec = std::vector<StatsTimePoint>;

  std::vector<std::string> set_keys_;

  std::unordered_map<std::string, StatsTimePointVec> set_starts_;
  std::unordered_map<std::string, StatsTimePointVec> set_ends_;
  std::unordered_map<std::string, StatsResult> set_results_;

  bool calculated = false;
  void calculate();

  void hist_s( const std::string &mark_name );
  void hist_e( const std::string &mark_name );

  StatsResult calculate_result(const std::string& key, std::vector<std::chrono::nanoseconds>& deltas);

  std::string to_string();
};