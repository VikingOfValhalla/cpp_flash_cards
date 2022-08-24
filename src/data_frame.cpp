#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>


struct Data_Frame {

    int position;
    std::string group;
    std::string question;
    std::string answer;
    

};

int main () {
    
    std::string test_dataframe = "1 Group Question Answer\n2 Group Question Answer\n3 Group Question Answer\n";
    
    // to create the column fixed row dynamic 2 d array
    std::vector<std::array<std::string, 4>> d = {
            {"1", "Group", "Question", "Answer"},
            {"2", "Group", "Question", "Answer"},
            {"3", "Group", "Question", "Answer"},
            {"4", "Group", "Question", "Answer"},
            {"5", "Group", "Question", "Answer"},
            };
    // TODO: to filter by specific element
    // d.at(2).printInfo();
 
    // to erase specific element    
    d.erase(std::remove(d.begin(), d.end(), d[2]), d.end());

    // to add to vector 
    d.push_back({"6", "Group", "Question", "Answer"});
    
    /*
    // to print the column fixed row dynamic 2 d array
    for (int a = 0; a < d.size(); a++) {
        for (int b = 0; b < 4; b++) {
            std::cout << '\t' << d[a][b];
        }
        std::cout << std::endl;
    }
    */
    return 0;
}
