#include <iostream>
#include <string>

#include "validation.cpp"

#define REQUIRED_ARGUMENTS 3

#define ARG_INDEX_FILE_NAME 1
#define ARG_INDEX_LINE_NUMBER 2

int main(int argc, char* argv[]) {
    // Ensure that the arguments exist
    if (argc < REQUIRED_ARGUMENTS) {
        printf("Must provide at least %d arguments. Provided only %d arguments",
                REQUIRED_ARGUMENTS, argc);
        printf("Example: ./json-where <file-name> <line-number>");
        return 1;
    }

    // Get the arguments
    std::string file_name(argv[ARG_INDEX_FILE_NAME]);
    std::string line_number(argv[ARG_INDEX_LINE_NUMBER]);

    // Validate the arguments
    try {
        validate_file(file_name);
        validate_line_number(line_number, file_name);
    } catch (std::exception &e) {
        std::cout << "There was an error: " << e.what() << std::endl;
        return 1;
    }

    printf("%s %s", file_name.c_str(), line_number.c_str());

    printf("\n");
}

