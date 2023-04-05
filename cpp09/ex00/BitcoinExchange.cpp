#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : m_database("data.csv"){
}

BitcoinExchange::BitcoinExchange(const std::string &filename): m_database("data.csv"){
	this->m_filename = filename;
	load();
}

BitcoinExchange::~BitcoinExchange(){
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj){
	this->m_data = obj.m_data;
	this->m_database = obj.m_database;
	this->m_filename = obj.m_filename;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &obj){
	if (this != &obj)
	{
		this->m_data = obj.m_data;
		this->m_filename = obj.m_filename;
	}
	return (*this);
}

static bool isDate(const std::string &date)
{
	int year, month, day;
	time_t t;
    struct tm tm;

	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (date[i] < '0' || date[i] > '9')
			return false;
	}
    year  = atoi(date.substr(0, 4).c_str());
    month = atoi(date.substr(5, 2).c_str());
    day   = atoi(date.substr(8, 2).c_str());

    memset(&tm, 0, sizeof(struct tm));
    tm.tm_year = year - 1900;
    tm.tm_mon  = month - 1;
    tm.tm_mday = day;
    t = mktime(&tm);
    if (t == -1)
        return false;
    return tm.tm_mday == day && tm.tm_mon == month - 1 &&
           tm.tm_year == year - 1900;
}

static std::string &rtrim(std::string &s, const char *t)
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

static std::string &ltrim(std::string &s, const char *t)
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}

static std::string &trim(std::string &s, const char *t)
{
    return ltrim(rtrim(s, t), t);
}

void BitcoinExchange::checkPrice(const std::string &date, const float price)
{
	if(m_data.find(date) != m_data.end())
	{
		std::cout << date << " => " << price << " = " << atof(m_data[date].c_str())*(price) << std::endl;
		return;
	}
	std::map<std::string, std::string>::iterator it = this->m_data.lower_bound(date);
   	if (it != this->m_data.begin())
		it--;
	std::cout << date << " => " << price << " = " << atof(it->second.c_str())*(price) << std::endl;
}

void BitcoinExchange::checkAllPrices()
{
	std::ifstream file(m_filename.c_str(), std::ifstream::in);
	std::string line;
	std::string date;
	char *p;
	const char * spaces = " \r\n\t\f\v";
	std::getline(file, line);
	while (std::getline(file, line))
	{
		date = line.substr(0, line.find('|'));
        std::string price = line.substr(line.find('|') + 1, line.length());
		date = trim(date, spaces);
		price = trim(price, spaces);
		if (price.size() == 0 || date.size()==0) 
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (!isDate(date))	
		{
			std::cout << "Error: bad input => '" << date << "'" << std::endl;
			continue;
		}
		strtod(price.c_str(), &p);
		float value = atof(price.c_str());
		if (value < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value>1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		if (*p != '\0')
		{
			std::cout << "Error: wrong price " << price << std::endl;
			continue;
		}
		checkPrice(date,value);
	}
	file.close();
}

void BitcoinExchange::load()
{
	std::ifstream file(m_database.c_str(), std::ifstream::in);
	std::string line;
	std::string date;
	char *p;
	std::getline(file, line);
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
