/*Dennis Ward 10/06/2023 Grocery Data Interface*/

#include <iostream>

#include "MainMenu.h"
#include "DataHandler.h"


int main()
{
    std::map<std::string, int> t_foodData; //Map to store ordered pairs of data
    t_foodData = DataHandler().readData("CS210 Project Three Input File.txt"); // Reads, Sorts, and backups data;
    /*if (foodData.count("Peas") == 1) {//Debug ensures data was retrieved
        std::cout << "Data Exists!";
    }
    else { std::cout << "Data Does not Exist!!!!!!"; }*/
    while (true) {//Menu Loop
        MainMenu().printMenu(); //prints menu options
        std::string t_input;//for input handling
        int t_intInput;
        try {//receives input trys to use it
            std::cin >> t_input;
            t_intInput = std::stoi(t_input);
            if (t_intInput == 4) {//if we want to close program
                std::cout << MainMenu().boxItFormat("Good Bye!", 20);
                return 0;
            }
            MainMenu(t_intInput, t_foodData).handleInput();//handles input
        }
        catch (const std::invalid_argument& e) {//catch invalid input such as a letter
            std::cout << "Invalid input please try 1,2,3, or 4." << "\n";
        }
        catch (const std::out_of_range& e) {//handles number to large
            std::cout << "Invalid input please try 1,2,3, or 4." << "\n";
        }

        
    }
    
    
}

