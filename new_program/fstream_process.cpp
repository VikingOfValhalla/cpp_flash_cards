#include <string>
#include <fstream>
#include <iostream>

std::string file_to_string(std::string file_location) {
    std::fstream file_handle;
    std::string lines;

    file_handle.open(file_location);
    if (file_handle.is_open()) {
        while(getline(file_handle, lines)) {
            std::string delimiter(",");
            file_handle >> lines;
            std::cout << lines << delimiter << std::endl;;
        }
        file_handle.close();
    }
    return lines;
}

void string_to_file(std::string file_location, 
                           std::string input_value) {
    // do something
}

