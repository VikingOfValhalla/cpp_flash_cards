#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

std::string file_to_string(std::string file_location) {
    std::fstream file_handle;
    std::string line;
    std::stringstream buffer;
    
    file_handle.open(file_location);
    uint32_t line_number = 0;
    if (file_handle.is_open()) {
        while(getline(file_handle, line)) {
            // std::cout << line_number++ << " " << line << '\n';
            buffer << line_number++ << " " << line << '\n';
        }
    }
    return buffer.str();
}

void string_to_file(std::string file_location, 
                    std::string input_value) {
    std::ofstream file_name;
    file_name.open(file_location, std::ios_base::app);
    file_name << std::endl << input_value;
    file_name.close();
}

void delete_from_file(std::string file_location, int line_number) {
    // do something

}
