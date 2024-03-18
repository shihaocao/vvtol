#pragma once

#include <chrono>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

class StatsResult {
  public:

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
  using SysClock = std::chrono::system_clock;
  using SysTimePoint = std::chrono::time_point<SysClock>;
  using SysTimePointVec = std::vector<SysTimePoint>;

  std::vector<std::string> set_keys_;

  std::unordered_map<std::string, SysTimePointVec> set_starts_;
  std::unordered_map<std::string, SysTimePointVec> set_ends_;
  std::unordered_map<std::string, StatsResult> set_results_;

  bool calculated = false;
  void calculate();

  void hist_s( const std::string &mark_name );
  void hist_e( const std::string &mark_name );

  StatsResult calculate_result(std::vector<std::chrono::nanoseconds>& deltas);

  std::string to_string();
};