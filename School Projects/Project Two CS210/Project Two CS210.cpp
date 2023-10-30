/*Dennis Ward 09/27/2023
Airgaurd Banking App*/

#include <iostream>

#include "MainMenu.h"
#include "Reporting.h"
int main() {
    std::vector<int> t_userInput;
    while (true) {
        t_userInput = MainMenu().interfaceMenu();//starts Main Menu interface Object will delete when finished.
        Reporting().reportInvestment(t_userInput[0], 0, t_userInput[2], t_userInput[3]);//starts Reporting for 0 dollars a month will delete object when complete
        Reporting().reportInvestment(t_userInput[0], t_userInput[1], t_userInput[2], t_userInput[3]);//starts Reporting for 0 dollars a month will delete object when complete
        std::cin.ignore();
        std::cout << "Would you like to continue?(Press Enter to continue or type 'quit' to quit application!)";//restart program?
        std::string t_input;
        std::getline(std::cin, t_input);
        std::transform(t_input.begin(), t_input.end(), t_input.begin(), ::tolower);//sanitize input
        if (t_input != "quit") {//check if we want to quit
            system("cls");//clears command line if we are restarting!
        }
        else {
            system("cls");
            std::cout << "Goodbye!\n";
            std::cout << " ";
            return 0;
        }
    }
    return 1;
}

