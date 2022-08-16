#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
class Bureaucrat{

	private: 
		std::string const name;
		int		grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat &operator=(const Bureaucrat &obj);

		std::string getName(void)const;
		int	getGrade(void)const;

		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception{
			public:
				GradeTooHighException(){}
				virtual ~GradeTooHihgException() throw() {}
				const char * what() const throw(){
					return "Grade Too High!"
				};

		};

		class GradeTooLowException : public std::exception{
			public:
				GradeTooLowException(){}
				virtual ~GradeTooLowException() throw() {}
				const char * what() const throw(){
					return "Grade Too Low!"
				};
		};
};
#endif
