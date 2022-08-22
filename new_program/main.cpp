#include "main.h"
#include "syntax_validation.cpp"
#include <fstream>
#include <string>
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



int main () {
        
    std::string test = return_alphanumeric("this is a test");
    bool test_2 = syntax_validator(test);
    std::cout << std::boolalpha  <<  test_2 << '\n';


    /*
    file_to_string("../data/data_structures.txt");
    
    Flash_Card fc;
    std::string q = "this is a question\n";
    fc.set_question(q);
    fc.print_question();

    std::string a = "This is an answer\n";
    fc.set_correct_answer(a);
    fc.print_answer();
    */
    return 0;
}
