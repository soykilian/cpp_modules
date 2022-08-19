#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat{

	private: 
		std::string name;
		int		grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat &operator=(const Bureaucrat &obj);

		std::string getName(void)const;
		int	getGrade(void)const;

		void incrementGrade();
		void decrementGrade();

		void signForm(Form &f)const;
		void executeForm(Form &f)const;

		class GradeTooHighException : public std::exception{
			public:
				GradeTooHighException(){}
				virtual ~GradeTooHighException() throw() {}
				const char * what() const throw(){
					return "Grade Too High!";
				};

		};
		class GradeTooLowException : public std::exception{
			public:
				GradeTooLowException(){}
				virtual ~GradeTooLowException() throw() {}
				const char * what() const throw(){
					return "Grade Too Low!";
				};
		};
};
std::ostream & operator<<(std::ostream &out, const Bureaucrat& bur);
#endif
