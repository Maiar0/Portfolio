/* class controls reading storing and writing data. see header file for detailed param description.*/
#include "DataHandler.h"

DataHandler::DataHandler()//base constructor
{
}

std::map<std::string, int> DataHandler::readData(std::string t_file)//Reads data stores in vector main handler for this class
{
	std::vector<std::string> t_list;
	std::ifstream inputFile;
	inputFile.open(t_file);
	if (inputFile.is_open()) {
		std::string t_line;
		while (std::getline(inputFile, t_line)) {
			t_list.push_back(t_line);
		}
	}
	writeData(t_list);
	storeData(t_list);
	return m_foodData;
}

void DataHandler::storeData(std::vector<std::string> t_list)//stores a vector into a map str:int
{
	for (size_t i = 0; i < t_list.size(); i++)
	{
		if (m_foodData.count(t_list[i]) == 0) {
			int t_count = 0;
			for (size_t o = 0; o < t_list.size(); o++)
			{
				if (t_list[i] == t_list[o]) {
					t_count = t_count + 1;
				}
			}
			m_foodData.insert(std::make_pair(t_list[i], t_count));
		}
	}
}

void DataHandler::writeData(std::vector<std::string> t_list)//creates our back-up file.
{
	std::ofstream outputFile("frequency.dat");
	if (outputFile.is_open()) {
		for (size_t i = 0; i < t_list.size(); i++)
		{
			outputFile << t_list[i];
			if (i != t_list.size() - 1) {
				outputFile << "\n";
			}
		}
	}
}



