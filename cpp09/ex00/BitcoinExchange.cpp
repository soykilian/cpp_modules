#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : m_database("data.csv"){
	std::cout << "BitcoinExchange default constructor called"<< std::endl;
}

BitcoinExchange::BitcoinExchange(const std::string &filename): m_database("data.csv"){
	this->m_filename = filename;
	load();
}

BitcoinExchange::~BitcoinExchange(){
	std::cout << "BitcoinExchange destructor called"<< std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj){
	this->m_data = obj.m_data;
	this->m_database = obj.m_database;
	this->m_filename = obj.m_filename;
	std::cout << "BitcoinExchange copy constructor called"<< std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &obj){
	if (this != &obj)
	{
		this->m_data = obj.m_data;
		this->m_filename = obj.m_filename;
	}
	std::cout << "BitcoinExchange assignment operator"<< std::endl;
	return (*this);
}

void BitcoinExchange::checkPrice(const std::string &date, const int &price)
{
	if(m_data.find(date) != m_data.end())
	{
		std::cout << date << " => " << price << " = " << m_data[date] << std::endl;
		return;
	}
}

void BitcoinExchange::load()
{
// Function that reads from m_filename and fills m_data
	std::ifstream file(m_database.c_str(), std::ifstream::in);
	std::string line;
	std::string date;
	char *p;
	while (std::getline(file, line))
	{
		date = line.substr(0, line.find(','));
        std::string price = line.substr(line.find(',') + 1, line.length());
		strtod(price.c_str(), &p);
		if (atof(price.c_str()) >= 0 && *p == '\0')
        	m_data[date] = price;
		else 
		{
			std::cout << "Error: Invalid price" << std::endl;
			break;
		}
	}
	file.close();
}
