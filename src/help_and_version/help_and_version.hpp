#include <sstream>
#include <string>
#include <vector>

#include <ctime>

#define MAX_LEN_TIME 100
std::string get_compile_time() {
  time_t current_time = time(nullptr);
  tm* ct = localtime(&current_time);

  char compile_time[MAX_LEN_TIME];
  strftime(compile_time, MAX_LEN_TIME, "Compiled %b %d %Y %H:%M:%S", ct);

  return std::string(compile_time);
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

std::string get_help_text() {
  std::vector<std::string> help_text {
    "", \
      "json-where --help", \
      "", \
      "Usage:", \
      "  json-where <file> <line> <column>", \
      "  json-where -v or --version", \
      "  json-where -h or --help", \
      "", \
      "Description:", \
      "  json-where is a program which takes a file name and a position in", \
      "  the file as input and prints the JSON path corresponding to that", \
      "  position.", \
      "", \
      "  json-where can be integrated into your editor to print the JSON path", \
      "  corresponding to the cursor position through a keybinding", \
      "", \
      "  Supported editors:", \
      "    - vim: https://github.com/icyflame/json-where#inside-vim", \
      "", \
      "    If you would like to add support for your editor, please make a", \
      "    pull-request on the GitHub repository with the instructions", \
      "    for integrating json-where into your editor.", \
      "", \
      "Example:", \
      "  json-where input_file.json 14 23", \
      "  .k5.a[9]", \
      "", \
      "Documentation:", \
      "  GitHub: https://github.com/icyflame/json-where", \
      ""
  };
  return join(help_text, "\n");
}

std::string get_version_text() {

  std::vector<std::string> version_text {
    "", \
      "json-where --version", \
      "", \
      get_compile_time(),
      ""
  };
  return join(version_text, "\n");
}
