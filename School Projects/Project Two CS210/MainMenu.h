#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include <string>
#include <cmath>

#include "Reporting.h"

class MainMenu
{

private:
    std::string m_investmentAmount;
    std::string m_monthlyDeposit;
    std::string m_annualInterest;
    std::string m_numYears;

public: 
    /**
     * Constructor for MainMenu class.
     *
     * @param investmentAmount Initial investment amount as a string.
     * @param monthlyDeposit Monthly deposit amount as a string.
     * @param annualDeposit Annual deposit amount as a string.
     * @param numYears Number of years as a string.
     */
    MainMenu(std::string t_investmentAmount = "", std::string t_monthlyDeposit = "", std::string t_annualDeposit = "", std::string t_numYears = "");
    /**
     * Creates a string containing n instances of a specified character.
     *
     * @param n The number of characters to repeat.
     * @param c The character to repeat.
     * @return A string with n instances of c.
     */
    std::string nCharString(size_t t_n, char t_c); 
    /**
     * Formats a line with a specified width, string, and symbol.
     *
     * @param t_width The total width of the line.
     * @param t_str The string to be centered in the line.
     * @param t_symbol The symbol to use for padding.
     * @return The formatted line.
     */
    std::string formatLine(int width, std::string t_str, char t_symbol); 
    /**
     * Converts a string to an integer and returns it as a string.
     *
     * @param t_str The input string.
     * @return The string representation of the converted integer.
     * purpose is to sanitize input
     */
    std::string stringToIntAsString(const std::string& t_str);
    /**
     * Displays the interface menu and handles user input.
     *This is the handdlign of user input and interface display
     */
    std::vector<int> interfaceMenu();



};

#endif //INTERFACE_H