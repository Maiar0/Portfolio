#include "MainMenu.h"
/*Contains code related to the display and handling of Main Menu interface
for further information on specific paramaters and purpose see the header file*/

MainMenu::MainMenu(std::string investmentAmount, std::string monthlyDeposit, std::string annualDeposit, std::string numYears) {//constructor
    m_investmentAmount = investmentAmount;
    m_monthlyDeposit = monthlyDeposit;
    m_annualInterest = annualDeposit;
    m_numYears = numYears;
};

std::string MainMenu::nCharString(size_t n, char c) {

    std::string result(n, c);// creates a string of c, n times

    return result; //returns string
}

std::string MainMenu::formatLine(int t_width, std::string t_str, char t_symbol) {
    int t_bufferSpaceLength = (t_width - t_str.length()) / 2 - 1;//logic for spaces
    std::string t_buffer_space = nCharString(t_bufferSpaceLength, ' ');
    std::string t_line = t_symbol + t_buffer_space + t_str + t_buffer_space + t_symbol;//format
    return t_line;
}

std::string MainMenu::stringToIntAsString(const std::string& t_str) {//Sanitize input
    try {
        int t_intValue = std::round(std::stof(t_str)); // Round the result after conversion
        return std::to_string(t_intValue);
    }
    catch (const std::invalid_argument&) {
        return "0"; // Default return value for invalid input
    }
    catch (const std::out_of_range&) {
        return "0"; // Default return value for out-of-range input
    }
}

std::vector<int> MainMenu::interfaceMenu() {
    int t_width = 80;//init variables
    char t_symbol = '*';
    std::string t_result;
    std::string t_tip;

    for (size_t i = 0; i < 5; i++)
    {
        system("cls");//refresh command prompt
        t_result = "";//formatting
        t_result.append(nCharString(t_width, t_symbol) + "\n");
        t_result.append(formatLine(t_width, "Data Input", t_symbol) + "\n");
        t_result.append("Initial Investment Amount:" + m_investmentAmount + "\n");
        t_result.append("Monthly Deposit:" + m_monthlyDeposit + "\n");
        t_result.append("Annual Interest:" + m_annualInterest + "\n");
        t_result.append("Number of Years:" + m_numYears + "\n");
        if (i == 0) { t_tip = "Intial Investment Amount(Positive Whole numbers only): "; }

        t_result.append(t_tip + "\n");
        std::cout << t_result;//output interface

        switch (i) {//handles input for interface
        case 0:
            std::cin >> m_investmentAmount;
            m_investmentAmount = stringToIntAsString(m_investmentAmount);//fixes any input
            t_tip = "Monthly Deposit(Positive Whole numbers only): ";
            break;
        case 1:
            std::cin >> m_monthlyDeposit;
            m_monthlyDeposit = stringToIntAsString(m_monthlyDeposit);
            t_tip = "Annual Interest(Positive Whole numbers only): ";
            break;
        case 2:
            std::cin >> m_annualInterest;
            m_annualInterest = stringToIntAsString(m_annualInterest);
            t_tip = "Number of Years to Invest(Positive Whole numbers only): ";
            break;
        case 3:
            std::cin >> m_numYears;
            m_numYears = stringToIntAsString(m_numYears);
            t_tip = "Press Enter to continue! ";
            break;
        case 4:
            break;
        }

    }
    std::cin.ignore(); // clear buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //wait for enter
    std::vector<int> t_data = { std::stoi(m_investmentAmount), std::stoi(m_monthlyDeposit), std::stoi(m_annualInterest), std::stoi(m_numYears) };
    return t_data;

}