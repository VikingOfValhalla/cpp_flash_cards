#include "main.h"
#include <fstream>
#include <string>
#include <iostream>

std::string file_to_string(std::string file_name) {
    std::fstream file_handle;
    std::string lines;

    file_handle.open(file_name);
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

int main () {


    file_to_string("../data/data_structures.txt");
    
    Flash_Card fc;
    std::string q = "this is a question\n";
    fc.set_question(q);
    fc.print_question();

    std::string a = "This is an answer\n";
    fc.set_correct_answer(a);
    fc.print_answer();

    return 0;
}
