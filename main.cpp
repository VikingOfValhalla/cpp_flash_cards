#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <string>
#include <stack>

// ==================================
//~~~~ TODO LIST ~~~~

// TODO: use getline() to select line and delete -- for question removal
// TODO: adjust the syntax for the new question to better suit deliniations
// TODO: work on play game read function
// TODO: include a score count for each correct question
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
};


// input text into file
void write_file(std::string file_location, std::string &text_to_add)
{    
    // logic for writing to file
    std::ofstream file_name;
    file_name.open(file_location, std::ios_base::app);
    file_name << text_to_add;
    file_name.close();
    
}

void read_file(std::string file_location)    
{
    // logic for reading the file
    std::ifstream file_name;
    file_name.open(file_location, std::ios_base::app);
    std::string file_text;
    while(std::getline(file_name,file_text))
    {
        std::cout << file_text << std::endl;
    };
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

bool is_valid(std::string s) {
std::stack<char> open;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (open.empty()) {
                throw std::runtime_error("01 Please enter the correct syntax.Use '{QUESTION},{ANSWER}'\n");
                return false;
            }
            if (s[i] == ')' && open.top() != '(') {
                throw std::runtime_error("02 Please enter the correct syntax.Use '{QUESTION},{ANSWER}'\n");
                return false;
            }
            if (s[i] == '}' && open.top() != '{') {
                throw std::runtime_error("03 Please enter the correct syntax.Use '{QUESTION},{ANSWER}'\n");
                return false;
            }
            if (s[i] == ']' && open.top() != '[') {
                throw std::runtime_error("04 Please enter the correct syntax.Use '{QUESTION},{ANSWER}'\n");
                return false;
            }
            open.pop();
        } else {
            open.push(s[i]);
        }
    }
    if (!open.empty()) {
        throw std::runtime_error("05 Please enter the correct syntax.Use '{QUESTION},{ANSWER}'\n");
        return false;
    }
    return true;

    /*
    // symbols for syntactical requirements
    int found_symbol = search_string.find("{") == std::string::npos;
    int found_symbol2 = search_string.find("}") == std::string::npos; 
    int found_comma = search_string.find(",") == std::string::npos;

    // error to catch syntactical question input
    if((found_symbol || found_symbol2 || found_comma) > 0)
    {
        throw "Please enter the correct syntax.Use '{QUESTION},{ANSWER}'\n";
    };
    */
}


int main ()
{
    // MAIN PROGRAM    
    try {

        // game loop
        while(true)
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
                    // input string from buffer into file
                    read_file(iterate_list(FlashCards.flash_card_paths, 0));
                
                    break;
                }


            // function to add to flash cards
            case 2:
                {
                    // input text to add to flash card
                    std::string input_flash_card = input_string_to_var();

                    // error handling
                    bool syntax_bool;
                    syntax_bool = is_valid(input_flash_card);
                    std::cout << "Syntax_bool return: " << std::boolalpha << syntax_bool << "\n";
                    
                    // input string from buffer into file
                    write_file(iterate_list(FlashCards.flash_card_paths, 0), input_flash_card);
                }


            // function to exit program
            case 3:
                {
                    break;
                }

            }
        }
    }

    // ERROR HANDLING
    catch (const char* exception)
    {
        std::cout << "Exception: " << exception << std::endl;
    }

    // end program
    return 0;
}
