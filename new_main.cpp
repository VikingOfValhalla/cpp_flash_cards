#include <stack>
#include <string>
#include <iostream>

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
  
}


int main() {
    
    bool bool_value;
    std::string test_value = "{]";
    bool_value = is_valid(test_value);
    std::cout << std::boolalpha << bool_value << "\n";
    return 0;
};
