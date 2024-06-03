#ifndef Y0_ENGINE_INCLUDE_Y0_CORE_LOG_LOGGER_H
#define Y0_ENGINE_INCLUDE_Y0_CORE_LOG_LOGGER_H

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <memory>
#include <cstdlib>

#define LOG_INFO(msg) Logger::GetInstance().log(boost::log::trivial::info, msg)
#define LOG_ERROR(msg) Logger::GetInstance().log(boost::log::trivial::error, msg)
#define LOG_WARNING(msg) Logger::GetInstance().log(boost::log::trivial::warning, msg)
#define LOG_DEBUG(msg) Logger::GetInstance().log(boost::log::trivial::debug, msg)

namespace y0_engine {
  /*
   * singleton object for to output log to file
   * usage examle:
   *   std::string logDir = "logs";
   *   Logger::getInstance().init(logDir);
   *   LOG_INFO("This is an informational message.");
   *   LOG_WARNING("This is a warning message.");
   *   LOG_ERROR("This is an error message.");
   *   LOG_DEBUG("This is a debug message.");
   *
   *   able to set log level from environment variable
   *   example: export LOG_LEVEL=warning
   */
  class Logger {
    public:
      /*
       * get singleton object
       */
      static Logger &GetInstance() {
        static Logger instance;
        return instance;
      }
      /*
       * let init the class
       */
      void init(const std::string& logDir, 
                const std::string& logFormat = "[%TimeStamp%] [%Severity%]: %Message%");
      /*
       * output log
       */
      template <typename T>
        void log(boost::log::trivial::severity_level level, const T &message) {
          BOOST_LOG_SEV(logger_, level) << message;
        }
    private:
      void SetLogLevel(const std::string &level);
      /*
       * constructor
       */
      Logger()
        : is_initialized(false),
          logger_(boost::log::keywords::severity = boost::log::trivial::info) {}

      bool is_initialized;
      boost::log::sources::severity_logger<boost::log::trivial::severity_level> logger_;
  };
} // namespace y0_engine

#endif
