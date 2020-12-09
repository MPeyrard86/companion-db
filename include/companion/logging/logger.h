//
// Created by Matthew Peyrard on 12/8/2020.
//

#ifndef COMPANION_DB_LOGGER_H
#define COMPANION_DB_LOGGER_H

#include <string>

namespace companion::logging
{
  enum LogLevel
  {
    Trace,
    Debug,
    Information,
    Warning,
    Error,
    Fatal
  };

  class Logger
  {
  private:
    LogLevel log_level_;

  public:
    Logger(LogLevel level)
      : log_level_(level)
    {
    }

    ~Logger() = default;

  public:
    template <typename... Ts>
    void Log(LogLevel level, const std::string& message, const Ts&... args)
    {
      if (level >= log_level_)
      {

      }
    }

    template <typename... Ts>
    void LogTrace(const std::string& message, const Ts&... args)
    {
      Log(LogLevel::Trace, message, args...);
    }
  };
}

#endif //COMPANION_DB_LOGGER_H
