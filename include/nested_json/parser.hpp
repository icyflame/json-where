#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

#include "minijson/minijson_reader.hpp"

namespace nested_json {
  enum log_level_type {
    Silent,
    Verbose
  };

  class parser {
    protected:
      const char* m_json_string;
      int m_length;
      std::vector<std::string> m_current_path;
      log_level_type m_log_level;

    protected:
      virtual void handle_value(minijson::const_buffer_context &ctx, minijson::value &v) {
        switch (v.type()) {
          case minijson::String:
          case minijson::Number:
          case minijson::Boolean:
          case minijson::Null:
            handle_final(ctx, v);
            break;
          case minijson::Object:
            handle_object(ctx);
            break;
          case minijson::Array:
            handle_array(ctx);
            break;
        }
      }

      void callback_array_handler(minijson::value v) {
        m_current_path.push_back("[" + std::to_string(index) + "]");
        handle_value(ctx, v);
        m_current_path.pop_back();

        index++;
      }

      void handle_array(minijson::const_buffer_context &ctx) {
        int index = 0;
        minijson::parse_array(ctx, this.callback_array_handler);
      }

      void callback_object_handler(const char *k, minijson::value v) {
        m_current_path.push_back("." + std::string(k));
        handle_value(ctx, v);
        m_current_path.pop_back();
      }

      void handle_object(minijson::const_buffer_context &ctx) {
        minijson::parse_object(ctx, this.callback_object_handler);
      }

      void handle_final(minijson::const_buffer_context &ctx, minijson::value &v) {
        std::ostringstream stringStream;
        stringStream << join(m_current_path, "")
          << " = "
          << v.as_string()
          << " ("
          << minijson::value_type_string(v.type()).to_string()
          << ")";
        log(stringStream);
      }

      std::string join(std::vector<std::string> arr, std::string joining_string) {
        std::string output;
        for (int i = 0; i < (arr.size()-1); i++) {
          output += arr[i];
          output += joining_string;
        }

        output += arr[arr.size()-1];
        return output;
      }

      void log(std::ostringstream& ss) {
        if (m_log_level == Verbose) {
          std::cout << ss.str() << std::endl;
        }
      }

    public:
      explicit parser(const char* json_string, int length, log_level_type log_level = Verbose) :
        m_json_string(json_string),
        m_length(length),
        m_log_level(log_level) {
        }

      void start() {
        minijson::const_buffer_context ctx(m_json_string, m_length);

        switch (ctx.toplevel_type()) {
          case minijson::Array:
            m_current_path.push_back(".");
            handle_array(ctx);
            m_current_path.pop_back();
            break;
          case minijson::Object:
            m_current_path.push_back("");
            handle_object(ctx);
            m_current_path.pop_back();
            break;
          default:
            throw std::runtime_error("Invalid JSON");
        }

        if (m_current_path.size() != 0) {
          std::cerr << "Final path size is not 0 => something went wrong while parsing that file" << std::endl;
        }
      }
  }; // class parser
} // namespace nested_json
