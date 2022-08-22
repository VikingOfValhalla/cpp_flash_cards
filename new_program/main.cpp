#include <fstream>
#include <iostream>
#include <string>

#include "main.h"
#include "syntax_validation.cpp"
#include "fstream_process.cpp"


int main () {
    /*    
    std::string test = return_alphanumeric("(this is a test)");
    bool test_2 = syntax_validator(test);
    std::cout << std::boolalpha  <<  test_2 << '\n';
    */

    
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
