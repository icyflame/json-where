#include <iostream>
#include <fstream>
#include <string>

#include "validation.hpp"
#include "nested_json/finder.hpp"

#define REQUIRED_ARGUMENTS 4

#define ARG_INDEX_FILE_NAME 1
#define ARG_INDEX_LINE_NUMBER 2
#define ARG_INDEX_COLUMN 3

bool isnewline(char c) {
  switch (c) {
    case '\n':
    case '\r':
      return true;
    default:
      return false;
  }
}

int get_offset(std::string file_contents, int line_number, int column) {
    const char* contents = file_contents.c_str();

    int line_count = 1, column_count = 1, offset = 0;

    for (int i = 0; i < file_contents.length(); i++) {
      // Goes up by one for every single character read from the file
      offset++;

      // If this is the match, break and return the current offset
      if (line_count == line_number && column_count == column) {
        break;
      }

      if (isnewline(contents[i])) {
        // Not enough columns on the line that was specified!
        if (line_count == line_number) {
          break;
        }

        // Start a new line; reset the column count
        line_count++;
        column_count = 1;
      } else {
        column_count++;
      }
    }

    return offset;
}

int main(int argc, char* argv[]) {
    // Ensure that the arguments exist
    if (argc < REQUIRED_ARGUMENTS) {
        printf("Must provide at least %d arguments. Provided only %d arguments\n",
                REQUIRED_ARGUMENTS, argc);
        printf("Example: ./json-where <file-name> <line-number>");
        return 1;
    }

    // Get the arguments
    std::string file_name(argv[ARG_INDEX_FILE_NAME]);
    std::string arg_line_number(argv[ARG_INDEX_LINE_NUMBER]);
    std::string arg_column(argv[ARG_INDEX_COLUMN]);

    int line_number = 0, column = 0;

    // Validate the arguments
    validate_file(file_name);
    line_number = validate_int(arg_line_number);
    column = validate_int(arg_column);
    validate_line_and_column(line_number, column);

    std::ifstream ifs(file_name);
    std::string file_contents {
        std::istreambuf_iterator<char>(ifs),
            std::istreambuf_iterator<char>()
    };

    int offset = get_offset(file_contents, line_number, column);

    printf("%s %d %d; Offset %d", file_name.c_str(), line_number, column, offset);

    const char* json_obj = file_contents.c_str();
    nested_json::finder finder_obj(json_obj, strlen(json_obj)-1, offset);

    std::string want_path = finder_obj.start();

    std::cout << "----------------------------";
    std::cout << want_path << std::endl;

    printf("\n");
}

