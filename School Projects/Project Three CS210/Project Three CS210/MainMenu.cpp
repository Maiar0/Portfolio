/* class controls main menu and its print functions see header file for detailed param descriptions.*/
#include "MainMenu.h"

MainMenu::MainMenu()// base constructor
{
    m_choice = 0;
}

MainMenu::MainMenu(int t_input, std::map<std::string, int> t_data)//constructor
{
	m_choice = t_input;
    m_data = t_data;
}

void MainMenu::printMenu()//prints menu options
{
    std::cout << formatLine(30, "Options*", '*', '*') << "\n";
    std::cout << formatLine(30, "1: Search", '|') << "\n";
    std::cout << formatLine(30, "2: List", '|') << "\n";
    std::cout << formatLine(30, "3: Histogram", '|') << "\n";
    std::cout << formatLine(30, "4: Exit", '|') << "\n";
    std::cout << nCharString(32,'*') << "\n";
    std::cout << boxItFormat("Type a number(1,2,3,4) and press enter to conitue!",65) << "\n";

}

std::string MainMenu::nCharString(size_t n, char c) {

    std::string t_result(n, c);// creates a string of c, n times

    return t_result; //returns string
}

std::string MainMenu::formatLine(int t_width, std::string t_str, char t_symbol, char t_whitespace) {//formats a line
    int t_bufferSpaceLength = (t_width - t_str.length()) / 2;//logic for buffer area
    if (t_bufferSpaceLength < 0) {//in case buffer space is negative program doesnt crash
        return "Error in building message!";
    }
    std::string t_buffer_space = nCharString(t_bufferSpaceLength, t_whitespace);
    std::string t_line = t_symbol + t_buffer_space + t_str + t_buffer_space + t_symbol;//format
    int t_length = t_line.length();
    if (t_length % 2 != 0) {//in the case of non-even line size
        t_line.insert(1,std::string(1,t_whitespace));
    }
    return t_line;
}

void MainMenu::handleInput()//handles user input if valid input error handling is done in main
{
    switch (m_choice) {

    case 1:
        search();
        break;
    case 2:
        printNumerical();
        break;
    case 3:
        printHistogram();
        break;
    case 4:
        std::cout << "Good bye!" << std::endl;
        break;
    default:
        std::cout << "Invalid input please try 1,2,3, or 4." << "\n";
        break;
    }

}

void MainMenu::search()//Option 1 to search the data we have
{
    std::string t_keyword;
    while (t_keyword != "quit") {
        bool t_matchFound = false;//in case no match is found
        std::vector <std::string> t_alternativeSpellingList;//for a hint to user in case no match is found

        std::cout << boxItFormat("Type the item you are looking for! You may type quit to go back to main menu!", 100) << "\n";
        std::cin >> t_keyword;
        std::string t_lowerKeyword = toLowercase(t_keyword);//sanitize input

        for (auto it = m_data.begin(); it != m_data.end(); ++it) {//iterates through map
            std::string t_key = it->first;
            std::string t_lowerKey = toLowercase(t_key);//sanitize map key
            if (compareKeywords(t_lowerKey, t_lowerKeyword)) {//proccessing of hint
                t_alternativeSpellingList.push_back(it->first);
            }
            if (t_lowerKey == t_lowerKeyword) {//match found
                int count = it->second;

                std::cout << boxItFormat(t_key + " : " + std::to_string(count),26);//Output of match
                t_matchFound = true;
                break;
            }
        }
        t_keyword = t_lowerKeyword;
        if (!t_matchFound && t_keyword != "quit" && t_alternativeSpellingList.size() > 0) {//provides hint if no mathc is found and there were possible matches
            std::string t_errorMes = "No match was found perhaps you meant : " + concatenateVector(t_alternativeSpellingList);
            std::cout << boxItFormat(t_errorMes,t_errorMes.length()+10);
        }
        
    }
    
}

void MainMenu::printNumerical()//Option 2 print numerical output of map.
{
    std::string t_listOutput;
    system("cls");
    std::cout << formatLine(30, "Numerical List", '*','*') << "\n";
    for (auto it = m_data.begin(); it != m_data.end(); ++it) {
        std::string t_word = it->first;
        int t_num = it->second;
        t_listOutput.append(
            formatLine(30, t_word + " : " + std::to_string(t_num), '*')+"\n"
        );

    }
    std::cout << t_listOutput;
    std::cout << nCharString(32,'*') << "\n";
}

void MainMenu::printHistogram()//Option 3 prints Histogram of map.
{
    std::string t_listOutput;
    system("cls");
    std::cout << formatLine(16, "Histogram", '-', '-') << "\n";
    for (auto it = m_data.begin(); it != m_data.end(); ++it) {
        std::string t_word = it->first;
        int t_num = it->second;
        t_listOutput.append(
            formatLine(16, t_word, '|') + nCharString(t_num, '*') + "\n"
        );

    }
    std::cout << t_listOutput;
    std::cout << nCharString(18, '-') << "\n";
}

std::string MainMenu::toLowercase(const std::string& t_input) {//used to sanitize strings for comparison
    std::string t_result = t_input;

    for (char& c : t_result) {
        c = std::tolower(c);
    }

    return t_result;
}

bool MainMenu::compareKeywords(const std::string& t_str1, const std::string& t_str2) {//used to compare first letter of two strings
    if (!t_str1.empty() && !t_str2.empty() && t_str1[0] == t_str2[0]) {
        return true;
    }
    return false;
}

std::string MainMenu::concatenateVector(const std::vector<std::string>& t_strings) {//conecntate vector for hint could be modified to have more value
    std::string t_result;

    for (size_t i = 0; i < t_strings.size(); ++i) {
        t_result += t_strings[i];
        if (i < t_strings.size() - 1) {
            t_result += ", ";
        }
    }

    return t_result;
}

std::string MainMenu::boxItFormat(std::string t_str, int t_width) {//Format for user prompts
    if (t_width % 2 != 0) {
        t_width = t_width+1;
    }
    std::string t_out = nCharString(t_width+2, '*') + "\n";
    t_out.append(formatLine(t_width, t_str, '*') + "\n");
    t_out.append(nCharString(t_width+2, '*') + "\n");
    return t_out;
}
