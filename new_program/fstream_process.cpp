#include <string>
#include <fstream>
#include <iostream>

std::string file_to_string(std::string file_location) {
    std::fstream file_handle;
    std::string lines;

    file_handle.open(file_location);
    if (file_handle.is_open()) {
        // no delimiter causes getline() to not work correctly because it assumes spaces are new lines
        while(getline(file_handle, lines, ';')) {
            file_handle >> lines;
            std::cout << lines;
        }
        file_handle.close();
    }
    return lines;
}

void string_to_file(std::string file_location, 
                    std::string input_value) {
    std::ofstream file_name;
    file_name.open(file_location, std::ios_base::app);
    file_name << std::endl << input_value;
    file_name.close();
}

