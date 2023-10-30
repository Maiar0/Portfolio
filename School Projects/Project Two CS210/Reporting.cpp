
#include "Reporting.h"

Reporting::Reporting(int t_investmentAmount, int t_monthlyDeposit, int t_annualDeposit, int t_numYears) {
	m_investmentAmount = 0;
	m_monthlyDeposit = 0;
	m_annualInterest = 0;
	m_numYears = 0;
	m_balance = m_investmentAmount;
}

std::string Reporting::tableToString(const std::vector<std::vector<double>>& t_table) {//converts the vector used here to a string for debug purposes
	std::ostringstream t_oss;

	for (const auto& t_row : t_table) {
		for (double t_value : t_row) {
			t_oss << t_value << " ";
		}
		t_oss << "\n";
	}

	return t_oss.str();
}

double Reporting::calculateInterestForOneMonth(double t_principal, double t_annualInterestRate) {
	double t_monthlyInterestRate = t_annualInterestRate / 12; // Convert annual rate to monthly rate
	double t_finalAmount = t_principal * std::pow(1 + t_monthlyInterestRate, 1);
	
	return t_finalAmount - t_principal; // Return the interest earned in one month
}




void Reporting::reportInvestment(int t_investmentAmount, int t_monthlyDeposit, int t_annualInterest, int t_numYears) {//handles user input for reporting
	m_investmentAmount = t_investmentAmount;//init values from user input
	m_balance = t_investmentAmount;
	m_monthlyDeposit = t_monthlyDeposit;
	m_annualInterest = t_annualInterest / 100.0;
	m_numYears = t_numYears;

	std::vector<std::vector<double>> t_monthlyTable(m_numYears, std::vector<double>(3));
	
	for (size_t i = 0; i < m_numYears; i++)//calculate yearly balance and interest
	{
		double t_balance = m_balance;
		double t_interestAccrued = 0;
		
		for (size_t i = 0; i < 12; i++)//calculating balance and interest for each month
		{

			t_balance = m_balance + m_monthlyDeposit;
			t_interestAccrued = t_interestAccrued+calculateInterestForOneMonth(t_balance, m_annualInterest);
			m_balance = t_balance + calculateInterestForOneMonth(t_balance, m_annualInterest);
			

		}
		t_monthlyTable[i][0] = i + 1;
		t_monthlyTable[i][2] = t_interestAccrued;
		t_monthlyTable[i][1] = m_balance;
	}
	
	//std::string out = tableToString(t_monthlyTable);
	//std::cout << out;
	interfaceReporting(t_monthlyTable);

	
}

void Reporting::interfaceReporting(const std::vector<std::vector<double>>& t_table) {//handles calculated data and reports to user some input handling
	// Set the width for each column
	const int t_colWidth = 25;

	// Print header
	std::cout << std::setw(t_colWidth*1.5) << std::left <<  "		Balance and Interest with " + std::to_string(m_monthlyDeposit) + "$ Monthly Deposit\n";
	std::cout << std::setw(t_colWidth) << std::left <<  MainMenu().nCharString(t_colWidth * 3, '*')<<"\n";
	std::cout << std::setw(t_colWidth) << std::left <<  "Year";
	std::cout << std::setw(t_colWidth) << std::left <<  "Year End Balance";
	std::cout << std::setw(t_colWidth) << std::left <<  "Year Earned Interest";
	std::cout << "\n";

	// Print data
	for (const auto& t_row : t_table) {
		for (double t_value : t_row) {
			std::cout << std::setw(t_colWidth) << std::left << t_value;
		}
		std::cout << "\n\n";
	}
	if (m_monthlyDeposit != 0) {//will not ask to save 0 monthlyDeposit = 0
		std::cout << "Type anything to Continue or type 'save' to save result to CSV file";
		std::string t_userInput;
		std::cin >> t_userInput;
		std::transform(t_userInput.begin(), t_userInput.end(), t_userInput.begin(), ::tolower);
		if (t_userInput == "save") {
			saveToCsv(t_table);
		}
	}
	

}

void Reporting::saveToCsv(const std::vector<std::vector<double>>& t_table) {//saves vector to CSV file for bettter comparison later
	int t_interest = m_annualInterest * 100;
	std::string t_fileName = "Investment Report $" + std::to_string(m_investmentAmount) + "_$" + std::to_string(m_monthlyDeposit)
		+ "_" + std::to_string(t_interest) + "%_" + std::to_string(m_numYears) + ".csv";
	std::ofstream t_outFile(t_fileName);

	if (!t_outFile.is_open()) {
		std::cerr << "Error: Unable to open file " << t_fileName << std::endl;
		return;
	}

	t_outFile << "Years,Balance,Interest_Accrued\n";
	for (const auto& t_row : t_table) {
		for (size_t i = 0; i < t_row.size(); i++) {
			t_outFile << t_row[i];
			if (i < t_row.size() - 1) {
				t_outFile << ',';
			}
		}
		t_outFile << '\n';
	}
	std::cout << "File was saved to root folder, Name coresponds to the user input!\n";
	t_outFile.close();

}
