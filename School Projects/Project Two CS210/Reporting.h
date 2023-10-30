#ifndef REPORTING_H
#define REPORTING_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <algorithm>

#include "MainMenu.h"

class Reporting
{
private:
    int m_investmentAmount;
    int m_monthlyDeposit;
    double m_annualInterest;
    int m_numYears;
    double m_balance;

public:
     /**
     * Constructor for Reporting class.
     *
     * @param t_investmentAmount Initial investment amount as an integer.
     * @param t_monthlyDeposit Monthly deposit amount as an integer.
     * @param t_annualDeposit Annual deposit amount as an integer.
     * @param t_numYears Number of years as an integer.
     */
    Reporting(int t_investmentAmount=0, int t_monthlyDeposit=0, int t_annualInterest=0, int t_numYears=0);
    /**
     * Converts a table (2D vector of doubles) to a string.
     *
     * @param t_table The 2D vector representing the table.
     * @return A string representation of the table.
     * purpose is debug
     */
    std::string tableToString(const std::vector<std::vector<double>>& t_table);
    /**
     * Calculates the interest earned in one month.
     *
     * @param t_principal The principal amount.
     * @param t_annualInterestRate The annual interest rate.
     * @return The interest earned in one month.
     */
    double calculateInterestForOneMonth(double t_principal, double t_annualInterestRate);
    /**
     * Handles user input and builds vector for reporting
     *
     * @param t_investmentAmount Initial investment amount as an integer.
     * @param t_monthlyDeposit Monthly deposit amount as an integer.
     * @param t_annualInterest Annual interest rate as an integer.
     * @param t_numYears Number of years as an integer.
     * @return None.
     */
    void reportInvestment(int t_investmentAmount, int t_monthlyDeposit, int t_annualInterest, int t_numYears);
    /**
     * Displays the investment report interface and handles user input.
     *
     * @param t_table The 2D vector representing the investment report table.
     * @return None.
     */
    void interfaceReporting(const std::vector<std::vector<double>>& t_table);
    /**
     * Saves the investment report table to a CSV file.
     *
     * @param t_table The 2D vector representing the investment report table.
     * @return None.
     */
    void saveToCsv(const std::vector<std::vector<double>>& t_table);
};
#endif //REPORTING_H
