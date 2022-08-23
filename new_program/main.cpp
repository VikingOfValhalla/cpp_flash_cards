#include <fstream>
#include <iostream>
#include <string>

#include "main.h"
#include "syntax_validation.cpp"
#include "fstream_process.cpp"

void print_start_menu() {
    std::cout << "1) Play Game\n"; 
    std::cout << "2) Edit/Create Flash Cards\n"; 
    std::cout << "3) Exit\n"; 
}

int main () {
    
    // start program -- start menu
    // [ ] - play game
    // [ ] - edit/create flash cards
    // [ ] - exit

    // ~~ play game ~~
    // [ ] - select group
    //    [ ] - while loop for quanity in group list is > 0

    // ~~ edit/create flash cards
    // [ ] - edit flash cards
    //    [ ] - list of current flash cards
    //    [ ] - input # to edit flash card
    //        [ ] - selection: edit / delete
    //            [ ] - edit: highlights # of flash card
    //                [ ] - re-enter entire flash card using syntax
    //            [ ] - delete: removes flash card # line from text file

    // [ ] - create flash cards
    //    [ ] - ask user for input {"Question"},{"Answer"},{"Group"}
    //    [ ] - validates user input based on syntax
    //        [ ] - if correct save to new line of text file
    //        [ ] - if incorrect, throw error, retry

    // ~~ exit ~~ 


    std::string file_location = "../data/data_structures.txt";
    string_to_file(file_location, "Here is some new text");
    
    /*
    std::string test = return_alphanumeric("(this is a test)");
    bool test_2 = syntax_validator(test);
    std::cout << std::boolalpha  <<  test_2 << '\n';
    */

    file_to_string("../data/data_structures.txt");
    
    /*
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
