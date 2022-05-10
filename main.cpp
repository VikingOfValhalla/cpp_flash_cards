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
            std::cout << "Play" << std::endl;
            break;
        }
    case 2:
        {
            std::cout << "Edit Flash Cards" << std::endl;
            break;
        }
    case 3:
        {
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


/*
// test function to iterate list
std::string iterate_list2(std::list<std::string> name_of_list, int position)
{
    for(std::list<std::string>::iterator name_of_list.begin(); name_of_list)
    {
        std::cout << name_of_list[x] << std::endl;
    }
}
*/


int main ()
{
    FlashCards FlashCards;
    
    // Start Menu
    std::cout << FlashCards.welcome_message << "\n"; 
    std::cout << iterate_list(FlashCards.game_menu, 0) << "\n";
    std::cout << iterate_list(FlashCards.game_menu, 1) << "\n";
    std::cout << iterate_list(FlashCards.game_menu, 2) << "\n";
    
    int player_input;
    std::cin >> player_input;

    int test = game_menu(player_input);

    std::cout << test;
    return 0;
}
