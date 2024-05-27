#include "y0_core/Log/Logger.h"

namespace y0_engine {
  Logger::Logger()
    : is_initialized(false),
      logger(boost::log::keywords::severity/* = boost::log::trivial::info*/) {}

  Logger::GetInstance() {
    static Logger instance;
    return instance;
  }

  void Logger::Init(const std::string &log_dir, 
                    const std::string &log_format /* = "[%TimeStamp%] [%Severity%]: %Message%"*/) {
    if (!is_initialized) {
      boost::log::add_common_attributes();

      boost::log::add_file_log(
          boost::log::keywords::file_name = log_dir + "/y0_engine_log_%N.log",
          boost::log::keywords::rotation_size = 10 * 1024 * 1024, // 10MB
          boost::log::keywords::time_based_rotation = boost::log::sinks::file::rotation_at_time_point(0, 0, 0),
          boost::log::keywords::format = (
            boost::log::expressions::stream
            << boost::log::expressions::format_date_time<boost::posix_time::ptime>("TimeStamp", "%Y-%m-%d %H:%M:%S")
            << " [" << boost::log::expressions::attr<boost::log::trivial::severity_level>("Severity")
            << "]: " << boost::log::expressions::smessage
            )
          );

      // get log level from environment variable
      const char *env_log_level = std::getenv("lOG_LEVEL");
      if (env_log_level) {
        SetLogLevel(std::string(env_log_level));
      } else {
        SetLogLevel("info");
      }

      is_initialized = true;
    }
  }

  void Logger::SetLogLevel(const std::string &level) {
    boost::log::trivial::severity_level log_level;

    switch (level) {
      case "trace":
        logLevel = boost::log::trivial::trace;
        break;
      case "debug":
        logLevel = boost::log::trivial::debug;
        break;
      case "info":
        logLevel = boost::log::trivial::info;
        break;
      case "warning":
        logLevel = boost::log::trivial::warning;
        break;
      case "error":
        logLevel = boost::log::trivial::error;
        break;
      case "fatal":
        logLevel = boost::log::trivial::fatal;
        break;
      default:
        logLevel = boost::log::trivial::info;
        break;
    }

    boost::log::core::get()->set_filter(
        boost::log::trivial::severity >= log_level);
  }
} // namespace y0_engine
