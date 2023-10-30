#include <iostream>//includes
#include <vector>
#include <sstream>//for vectorToString()

std::string vectorToString(const std::vector<int>& vec) {//function i made to easily print a variable
    std::stringstream ss;
    for (int num : vec) {
        ss << num << ",";
    }
    return ss.str();
}

void SortVector(std::vector<int>& myVec) {
    bool done = true;//initialize for loop
    while (done) {//loops until a pass is made with no swap
        done = false;//assumes we are done
        for (int i = 0; i < myVec.size(); i++)
        {
            if (i + 1 < myVec.size() && myVec.at(i) < myVec.at(i + 1)) {//checks to see if a swap should be made and to verify we are in range
                int num = myVec.at(i + 1);//used as temp variable to swap there spots
                myVec.at(i + 1) = myVec.at(i);//swapping
                myVec.at(i) = num;//swapping
                done = true;//we are not done
            }
        }
    }
    std::cout << vectorToString(myVec) << "\n";
}



int main() {
    std::vector<int> vec;//initializing
    int userInput;
    while (std::cin >> userInput) {//reads all inputs 
        vec.push_back(userInput);//appends input
    }
    if (!vec.empty()) {//if vector isnt empty
        vec.erase(vec.begin());//erases first number in vector
    }
    SortVector(vec);//function call
   

    return 0;
}

