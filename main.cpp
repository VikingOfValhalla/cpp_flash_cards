#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <string>

// ==================================
//~~~~ TODO LIST ~~~~

// TODO: use getline() to select line and delete -- for question removal
// TODO: adjust the syntax for the new question to better suit deliniations
// TODO: work on play game read function
// TODO: create game loop and include a score count for each correct question
// TODO: create something to catch input create error
// TODO: adjust .gitignore to not include .exe and .ccls files
// ==================================

class FlashCards {
    private:
        // game instance -- if 1, game is on;
        int game_instance = 0;
    public: 
        std::string welcome_message = "Hello, Please selection from the following options:";

        std::list<std::string> flash_card_paths = {
            "data/data_structures.txt",
            "data/design_patters.txt",
            "data/big_o.txt"
        };

        std::list<std::string> game_menu = { 
            "Play", 
            "Edit Flash Cards", 
            "Exit" 
        };
        bool exception;
};


// input text into file
void read_and_write_file(std::string file_location, std::string &text_to_add)
{
    std::ofstream file_name;
    file_name.open(file_location, std::ios_base::app);
    file_name << text_to_add;
    file_name.close();
}


// iterate list
std::string iterate_list(std::list<std::string> &name_of_list, int position)
{
    std::list<std::string>::iterator selection = name_of_list.begin();
    advance(selection, position);
    return *selection;
}


std::string input_string_to_var()
{ 
    // read multiple words into buffer
    std::string input_flash_card;
    
    std::cout << "SYNTAX: \"QUESTION\"; {ANSWER}" << "\n";
    std::cout << "Enter Text: ";

    std::getline(std::cin, input_flash_card);
    input_flash_card = "\n" + input_flash_card;
    
    return input_flash_card;
}

std::string error_handling(std::string search_string)
{

    // TODO: this logical operator is messed up -- only finds the first { not the proceeding }
    bool found_symbol = ((search_string.find("{")) && (search_string.find("}")) == std::string::npos);
    std::cout << found_symbol << "\n";
    // error to catch syntactical question input
    if(found_symbol == true)
    {
        std::cout << "Please enter the correct syntax." << "\n";
    };
    return "Please enter the correct syntax.";
}

int main ()
{
    FlashCards FlashCards; 
    
    
    // Start Menu
    std::cout << FlashCards.welcome_message << "\n"; 
    std::cout << "1: " << iterate_list(FlashCards.game_menu, 0) << "\n";
    std::cout << "2: " << iterate_list(FlashCards.game_menu, 1) << "\n";
    std::cout << "3: " << iterate_list(FlashCards.game_menu, 2) << "\n";
   
   
    // player initial input
    int player_input;
    std::cin >> player_input;
    // to clear the buffer after cin
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    // handle test cases of input selections
    switch(player_input)
    {


    // function to play flash cards
    case 1:
        {
            std::cout << "Play" << std::endl;
            break;
        }


    // function to add to flash cards
    case 2:
        {
            // input text to add to flash card
            std::string input_flash_card = input_string_to_var();

            // error handling
            error_handling(input_flash_card);

            // input string from buffer into file
            read_and_write_file(iterate_list(FlashCards.flash_card_paths, 0), input_flash_card);
        }

    
    // function to exit program
    case 3:
        {
            break;
        }

    }

    // end program
    return 0;
}
