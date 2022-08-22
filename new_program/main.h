#include <string>
#include <iostream>

class Flash_Card {
    private:
        std::string question;
        std::string  correct_answer;

    public:
        std::string set_question(std::string q) { 
            question = q;
            return question;
        }

        std::string set_correct_answer(std::string c) {
            correct_answer = c;
            return correct_answer;
        }

        void print_question() { std::cout << question; }
        void print_answer() { std::cout << correct_answer; }
        
        /*
        Flash_Card(char u, bool c, std::string a) :
                   user_input(u), correct_answer(c), answers(a)
            {
                std::cin >> u;
                switch (u) {
                    case 'a':
                        correct_answer = c;
                        std::cout << 'a' << '\n';        
                    case 'b':
                        correct_answer = c;
                        std::cout << 'b' << '\n';
                    case 'c':
                        correct_answer = c;
                        std::cout << 'c' << '\n';
                    case 'd':
                        correct_answer = c;
                        std::cout << 'd' << '\n';
            }
        }

        */

};
