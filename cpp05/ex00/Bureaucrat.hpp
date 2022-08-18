#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
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
#endif
