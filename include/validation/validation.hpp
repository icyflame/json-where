#include <sys/stat.h>
#include <iostream>
#include <string>

void validate_file(std::string file_name) {
  // Ensure that the file exists
  // https://stackoverflow.com/a/12774387/2080089
  struct stat buffer;
  if (stat (file_name.c_str(), &buffer) != 0) {
    std::string error_msg = "File " + file_name + " does not exist";
    throw std::runtime_error(error_msg);
  }
}

int validate_int(std::string int_str) {
  int int_val = std::stoi(int_str);

  if (int_val <= 0) {
    throw std::runtime_error("Line number must be a positive number");
  }

  return int_val;
}

void validate_line_and_column(int line_number, int column) {
  if (line_number <= 0 || column <= 0) {
    throw std::runtime_error("Line number and column number must be >= 1");
  }
}
