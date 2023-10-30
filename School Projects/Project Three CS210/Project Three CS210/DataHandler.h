#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>

class DataHandler
{
private:
	std::map<std::string, int> m_foodData;//The map of data.
public:
	/**
	 * Constructor for the DataHandler class.
	 */
	DataHandler();
	/**
	 * Reads data from a file and processes it to a vector currently a 1D vector.
	 *
	 * @param file The name of the file to read data from.
	 * @return A map containing the processed data.
	 */
	std::map<std::string, int> readData(std::string t_file);
	/**
	 * Stores data in a map from 1D vector
	 * counts occurences of item in vector and append str:count to map
	 * @param list A vector containing the data to process.
	 */
	void storeData(std::vector<std::string> t_list);
	/**
	 * Writes data to a file from 1D vector.
	 *
	 * @param list A vector containing the data to write.
	 */
	void writeData(std::vector<std::string> t_list);

};

