#include <iostream>
#include <string>
#include <map>
#include <vector>

class MainMenu
{
private:
	int m_choice;//choice made by user
	std::map<std::string, int> m_data;//data to be formatted

public:
	/**
	 * Constructor for MainMenu class.
	 */
	MainMenu();
	/**
	 * Constructor for MainMenu class with parameters.
	 *
	 * @param t_input The user's choice input.
	 * @param data A map containing data.
	 */
	MainMenu(int t_input, std::map<std::string, int> data = std::map<std::string, int>());
	/**
	 * Prints the main menu options.
	 */
	void printMenu();
	/**
	 * Generates a string of n characters.
	 *
	 * @param n The number of characters in the string.
	 * @param c The character to repeat.
	 * @return The generated string.
	 */
	std::string nCharString(size_t n, char c);
	/**
	 * Formats a line with specified width, string, symbol, and whitespace.
	 *
	 * @param t_width The total width of the line.
	 * @param t_str The string to be centered in the line.
	 * @param t_symbol The symbol to use for padding.
	 * @param t_whitespace The whitespace character intialized with ' '.
	 * @return The formatted line.
	 */
	std::string formatLine(int t_width, std::string t_str, char t_symbol, char t_whitespace = ' ');
	/**
	 * Handles user input and performs corresponding actions.
	 * Object must be instialized
	 */
	void handleInput();
	/**
	 * Searches for items based on user input.
	 * Object must be instialized
	 */
	void search();
	/**
	 * Prints a numerical list of data.
	 * Object must be instialized.
	 */
	void printNumerical();
	/**
	 * Prints a histogram based on data.
	 * Object must be instialized
	 */
	void printHistogram();
	/**
	 * Converts a string to lowercase.
	 *
	 * @param input The input string.
	 * @return The converted string in lowercase.
	 */
	std::string toLowercase(const std::string& t_input);
	/**
	 * Compares two strings based on their first character.
	 *
	 * @param str1 The first string.
	 * @param str2 The second string.
	 * @return True if the first characters are the same, false otherwise.
	 */
	bool compareKeywords(const std::string& t_str1, const std::string& t_str2);
	/**
	 * Concatenates strings in a vector, separated by commas.
	 *
	 * @param strings The vector of strings to concatenate.
	 * @return The concatenated string.
	 */
	std::string concatenateVector(const std::vector<std::string>& t_strings);
	/**
	 * Formats a string in a box pattern.
	 *
	 * @param str The input string.
	 * @param width of box.
	 * @return The formatted string.
	 */
	std::string boxItFormat(std::string t_str, int t_width = 20);
};

