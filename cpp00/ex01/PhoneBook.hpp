#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

#define MAX_CONTACT 8
class PhoneBook{
	 
	public:
		PhoneBook();
		~PhoneBook();
		void	ft_new_contact();
		void	ft_list_contacts();
	private:
		Contact		contact_book[MAX_CONTACT];
		int	number_contacts;	
};

#endif
