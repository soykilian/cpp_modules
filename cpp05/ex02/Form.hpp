#ifndef FORM_HPP
# define FORM_HPP
#include "Bureaucrat.hpp"
#include <iostream>
class Bureaucrat;
class Form{
	private:
		const std::string name;
		bool signature;
		const int	gradeToSign;
		const int	gradeToExec;
		
	public:
		Form();
		~Form();
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form &obj);
		Form &operator=(const Form &obj);
		std::string getName(void)const;
		int	getGradeToSign(void)const;
		int	getGradeToExec(void)const;
		bool isSigned(void)const;
		void beSigned(Bureaucrat const &b);
		void execute(Bureaucrat const & executor) const;
		virtual void executeAction() const = 0;
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
		class NotSigned : public std::exception{
			public:
				NotSigned(){}
				virtual	 ~NotSigned() throw() {}
				const char* what() const throw(){
					return "Form cannot be executed. Signature missing";
				}
		};
};
std::ostream &operator<<(std::ostream &out, const Form& bur);
#endif
