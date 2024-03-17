#include <common/stats.hpp>
#include <log.hpp>

Stats::~Stats() {
    log() << this->to_string() << '\n';
};

Stats& Stats::instance() {
    static Stats instance;
    return instance;
}

void Stats::set_stat(const std::string &stat_name, size_t value)
{
  stat_keys_.push_back(stat_name);
  stats_[stat_name] = value;
};

void Stats::start_mark(const std::string &mark_name)
{
  mark_keys_.push_back(mark_name);
  start_marks_[mark_name] = std::chrono::system_clock::now();
  if (print_mark_sf_)
    log() << "Starting: " << mark_name << '\n';
};

void Stats::end_mark(const std::string &mark_name)
{
  end_marks_[mark_name] = std::chrono::system_clock::now();
  if (print_mark_sf_)
    log() << "Finished: " << mark_name << '\n';
};

std::string Stats::to_string()
{
  std::stringstream ret_stream;
  ret_stream << "STATISTICS:"  << '\n';

  for (const auto &stat_name : stat_keys_)
  {
    size_t &val = stats_.at(stat_name);
    ret_stream << std::setw(stats_width_) << stat_name << " : " << val << '\n';
  }

  ret_stream << "-----"  << '\n';

  for (const auto &mark_name : mark_keys_)
  {
    const auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
        end_marks_.at(mark_name) - start_marks_.at(mark_name));

    ret_stream << std::setw(stats_width_) << mark_name;
    ret_stream << " : ";
    ret_stream << duration_ms.count() / 1000;
    ret_stream << ".";
    ret_stream << duration_ms.count() % 1000;
    ret_stream << "s" << '\n';
  }

  return ret_stream.str();
};