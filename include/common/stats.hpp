#pragma once

#include <unordered_map>
#include <vector>
#include <chrono>
#include <iostream>
#include <sstream>
#include <iomanip>

class Stats
{
private:
  using SysClock = std::chrono::system_clock;
  using SysTimePoint = std::chrono::time_point<SysClock>;

  std::unordered_map<std::string, size_t> stats_;
  std::unordered_map<std::string, SysTimePoint> start_marks_;
  std::unordered_map<std::string, SysTimePoint> end_marks_;
  std::vector<std::string> mark_keys_;
  std::vector<std::string> stat_keys_;
  static constexpr size_t stats_width_ = 32;
  static constexpr bool print_mark_sf_ = false;

public:
  ~Stats();

  static Stats& instance();
  void set_stat(const std::string &stat_name, size_t value);
  void start_mark(const std::string &mark_name);
  void end_mark(const std::string &mark_name);
  std::string to_string();
};

inline Stats& stats() {
    return Stats::instance();
}
