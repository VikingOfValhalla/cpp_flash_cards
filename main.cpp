#include <iostream>
#include <string>
#include <list>

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


int game_menu(int selection)
{
    // Handle test cases of input selections
    switch(selection)
    {
    case 1:
        {
            // function to play flash cards
            std::cout << "Play" << std::endl;
            break;
        }
    case 2:
        {
            // function to edit flash cards
            std::cout << "Edit Flash Cards" << std::endl;
            break;
        }
    case 3:
        {
            // function to exit program
            std::cout << "Exit" << std::endl;
            break;
        }

    }
    return selection;
}

// iterate list
std::string iterate_list(std::list<std::string> name_of_list, int position)
{
    std::list<std::string>::iterator selection = name_of_list.begin();
    advance(selection, position);
    return *selection;
}



// test function to iterate list
std::string iterate_list2(std::list<std::string> name_of_list)
{
    for(std::list<std::string>::iterator it = name_of_list.begin(); it != name_of_list.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    return "Test";
}


int main ()
{
    FlashCards FlashCards;

    // Start Menu
    std::cout << FlashCards.welcome_message << "\n"; 
    std::cout << "1: " << iterate_list(FlashCards.game_menu, 0) << "\n";
    std::cout << "2: " << iterate_list(FlashCards.game_menu, 1) << "\n";
    std::cout << "3: " << iterate_list(FlashCards.game_menu, 2) << "\n";
   
    // Player Initial Input
    int player_input;
    std::cin >> player_input;

    return 0;
}
