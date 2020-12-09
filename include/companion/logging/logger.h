//
// Created by Matthew Peyrard on 12/8/2020.
//

#ifndef COMPANION_DB_LOGGER_H
#define COMPANION_DB_LOGGER_H

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>
#include <utility>

#include <fmt/core.h>

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
    std::string name_;

    inline static const std::string TRACE = "TRACE";
    inline static const std::string DEBUG = "DEBUG";
    inline static const std::string INFO = "INFO";
    inline static const std::string WARN = "WARN";
    inline static const std::string ERROR = "ERROR";
    inline static const std::string FATAL = "FATAL";

  public:
    explicit Logger(std::string name, LogLevel level)
      : name_(std::move(name))
      , log_level_(level)
    {
    }

    ~Logger() = default;

  private:
    [[nodiscard]] static std::string current_time_formatted() noexcept
    {
      auto now = std::chrono::system_clock::now();
      auto now_as_time_t = std::chrono::system_clock::to_time_t(now);
      struct tm local_time {};
      localtime_r(&now_as_time_t, &local_time);
      char timestamp_buffer[100];
      std::size_t buffer_used {
        std::strftime(timestamp_buffer, 100, "%Y-%m-%dT%H:%M:%S.%s", &local_time)
      };
      if (buffer_used <= 0)
      {
        return std::string();
      }

      return std::string(timestamp_buffer);
    }

    template <typename... Ts>
    void Log(const std::string& level, const std::string& message, const Ts&... args) const noexcept
    {
      auto timestamp_string = current_time_formatted();
      auto formatted_string = fmt::format(message, args...);
      fmt::print("[{}][{}][{}] {}", timestamp_string, name_, level, formatted_string);
    }

  public:
    template <typename... Ts>
    void LogTrace(const std::string& message, const Ts&... args) const noexcept
    {
      if (log_level_ <= LogLevel::Trace)
      {
        Log(TRACE, message, args...);
      }
    }

    template <typename... Ts>
    void LogDebug(const std::string& message, const Ts&... args) const noexcept
    {
      if (log_level_ <= LogLevel::Debug)
      {
        Log(DEBUG, message, args...);
      }
    }

    template <typename... Ts>
    void LogInformation(const std::string& message, const Ts&... args) const noexcept
    {
      if (log_level_ <= LogLevel::Information)
      {
        Log(INFO, message, args...);
      }
    }

    template <typename... Ts>
    void LogWarning(const std::string& message, const Ts&... args) const noexcept
    {
      if (log_level_ <= LogLevel::Warning)
      {
        Log(WARN, message, args...);
      }
    }

    template <typename... Ts>
    void LogError(const std::string& message, const Ts&... args) const noexcept
    {
      if (log_level_ <= LogLevel::Error)
      {
        Log(ERROR, message, args...);
      }
    }

    template <typename... Ts>
    void LogFatal(const std::string& message, const Ts&... args) const noexcept
    {
      if (log_level_ <= LogLevel::Fatal)
      {
        Log(FATAL, message, args...);
      }
    }
  };
}

#endif //COMPANION_DB_LOGGER_H
