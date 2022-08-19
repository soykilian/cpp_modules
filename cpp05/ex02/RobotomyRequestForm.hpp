#ifndef SHRUBERRYCREATIONFORM_HPP
#define SHRUBERRYCREATIONFORM_HPP
#include "Form.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm: public Form{
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string &target);
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &obj);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &obj);
		void executeAction(Bureaucrat const & executor) const; 
		std::string	getTarget(void)const;
};
#endif
