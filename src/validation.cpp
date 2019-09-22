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

    // TODO: Maybe, we should also make sure that it's a file and not a
    // directory etc
}

void validate_line_number(std::string line_number_str, std::string file_name) {
    int line_number = std::stoi(line_number_str);

    if (line_number <= 0) {
        throw std::runtime_error("Line number must be a positive number");
    }
}
