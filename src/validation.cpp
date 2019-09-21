#include <sys/stat.h>
#include <iostream>
#include <string>

void validate_file(std::string file_name) {
    struct stat buffer;
    if (stat (file_name.c_str(), &buffer) != 0) {
        std::string error_msg = "File " + file_name + " does not exist";
        throw std::runtime_error(error_msg);
    }
}

void validate_line_number(std::string line_number, std::string file_name) {
    // TODO: line_number > 0
    // TODO: `wc -l file_name <= line_number`
    throw std::runtime_error("Line number is invalid");
}
