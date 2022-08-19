#ifndef SHRUBERRYCREATIONFORM_HPP
#define SHRUBERRYCREATIONFORM_HPP
#include "Form.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm: public Form{
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string &target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &obj);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &obj);
		void execute(Bureaucrat const & executor) const; 
		std::string	getTarget(void)const;
};
#endif
