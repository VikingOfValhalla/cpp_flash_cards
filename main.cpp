#include <iostream>
#include <string>

class FlashCards {
    private:
        // game instance -- if 1, game is on;
        int game_instance = 0;
    public: 
        std::string welcome_message;

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

int main ()
{
    // Start Menu
    std::cout << "Hello, please select from the following options:" << "\n"; 
    std::cout << "1: Play Flash Cards" << "\n";
    std::cout << "2: Edit Flash Cards" << "\n";
    std::cout << "3: Exit" << "\n";
    
    int player_input;
    std::cin >> player_input;

    int test = game_menu(player_input);

    std::cout << test;
    return 0;
}
