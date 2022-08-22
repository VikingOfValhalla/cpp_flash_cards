#include <stack>
#include <string>
#include <algorithm>


std::string return_alphanumeric(std::string string_input) {
    // Removes alphanumeric  and spaces to easily check syntax
    auto it = std::remove_if(string_input.begin(), string_input.end(), [](char const &c) {
        return std::isalnum(c);
    });

    string_input.erase(it, string_input.end()); // remove alphanumeric
    string_input.erase(remove(string_input.begin(), string_input.end(), ' '), string_input.end()); // remove spaces

    return string_input;
}


bool syntax_validator(std::string s) {    
    std::stack<char> open;
    std::string error_message = "Please enter the correct syntax. Use (\"QUESTION\"),{\"ANSWER\"}\n";

    // evalutes syntax
    for (int i = 0; i < s.size(); i++) {
        
        if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (open.empty()) {
                throw std::runtime_error(error_message);
                return false;
            }
            if (s[i] == ')' && open.top() != '(') {
                throw std::runtime_error(error_message);
                return false;
            }
            if (s[i] == '}' && open.top() != '{') {
                throw std::runtime_error(error_message);
                return false;
            }
            if (s[i] == ']' && open.top() != '[') {
                throw std::runtime_error(error_message);
                return false;
            }
            open.pop();
        } 
        else {
            open.push(s[i]);
        }
    }
    if (!open.empty()) {
        throw std::runtime_error("05 Please enter the correct syntax.Use (\"QUESTION\"),{\"ANSWER\"}\n");
        return false;
    }
    return true;
}

