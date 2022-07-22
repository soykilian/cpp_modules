#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact {
	public:
			Contact();
			~Contact();
			void setContact(std::string, std::string, std::string,std::string,std::string);
			void printTable();
	private:
		int				idx;
		std::string		first_name;
		std::string		last_name;
		std::string		nickname;
		std::string		phone_number;
		std::string		darkest_secret;
};
#endif
