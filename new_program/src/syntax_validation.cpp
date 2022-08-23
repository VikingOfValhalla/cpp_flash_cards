#include <stack>
#include <stdexcept>
#include <string>
#include <algorithm>

// TODO: need to fix if an input contains other special characters such as '/'

std::string return_alphanumeric(std::string string_input) {
    // removes alpha-numeric  and spaces to easily check syntax
    auto it = std::remove_if(string_input.begin(), string_input.end(), [](char const &c) {
        return std::isalnum(c);
    });

    string_input.erase(it, string_input.end()); // remove alpha-numeric
    string_input.erase(remove(string_input.begin(), string_input.end(), ' '), string_input.end()); // remove spaces

    return string_input;
}


bool syntax_validator(std::string s) {    
    std::stack<char> open;
    std::string error_message = "Please enter the correct syntax. Use (\"QUESTION\"),{\"ANSWER\"}\n";
    

    if (s.empty()) {
        throw std::runtime_error(error_message); // if string is empty
        throw false;
    }
    // evalutes syntax
    for (int i = 0; i < s.size(); i++) {
        
        if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
             // if stack doesn't have starting bracket
            if (open.empty()) {
                throw std::runtime_error("You're missing a starting bracket: " + error_message); 
                return false;
            }

            // if stack does not have matching pair
            if (s[i] == ')' && open.top() != '(') {
                throw std::runtime_error("Use ( ): " + error_message);
                return false;
            }
            if (s[i] == '}' && open.top() != '{') {
                throw std::runtime_error("Use { }: " + error_message);
                return false;
            }
            if (s[i] == ']' && open.top() != '[') {
                throw std::runtime_error("Use [ ]: " + error_message);
                return false;
            }
            open.pop();
        } 
        else {
            open.push(s[i]);
        }
    }
    // if stack has leftover non-alphanumeric characters
    if (!open.empty()) {
        throw std::runtime_error("You're missing an ending bracket: " + error_message);
        return false;
    }
    return true;
}

