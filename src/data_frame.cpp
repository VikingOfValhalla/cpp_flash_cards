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


// TODO: requires template for dataframe input -- needs to be fixed
template <typename T>
T dataframe_selection(T &dataframe, int column_number) {
    // to print the column fixed row dynamic 2 d array
    for (int a = 0; a < dataframe.size(); a++) {
        for (int b = 0; b < column_number; b++) {
            // std::cout << '\t' << dataframe[a][b];
        }
        // std::cout << std::endl;
    }
    return dataframe;
}

template<typename T> // template for dataframe type
void dataframe_print(T &dataframe, std::string column_selection, int column_number) {
    // input dataframe, select either range or single, and the max number of columns wanted
    for (int row = 0; row < dataframe.size(); row++) {
        if (column_selection == "range") { // range from start of dataframe until column_number
            for (int col = 0; col < column_number; col++) {
                std::cout << '\t' << dataframe[row][col];
            }
        } else if (column_selection == "single") { // single column 1 based numbering
            for (int col = column_number-1; col < column_number; col++) {
                std::cout << '\t' << dataframe[row][col];
            }
        } else break; // break if neither range nor single is input
        std::cout << std::endl;
    }
}


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
    // using Container_t = std::vector<Data_Frame>;
    // Container_t container;
    // std::find(container.begin(), container.end(), [](d& df) { return df.position == 1;});
 
    // to erase specific element    
    d.erase(std::remove(d.begin(), d.end(), d[2]), d.end());

    // to add to vector 
    d.push_back({"6", "Group", "Question", "Answer"});

    dataframe_print(d, "range", 3);
    
    return 0;
}
