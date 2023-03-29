#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP
#include <fstream>
#include <iostream>
#include <map>
#include <stdlib.h>
#include <string>
class BitcoinExchange{
	private:
		std::map<std::string, std::string> m_data;
		std::string m_database;
		std::string m_filename;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const std::string &filename);
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange &operator=(BitcoinExchange &obj);
		void checkPrice(const std::string &date, const int &price);
		void load();
};
#endif
