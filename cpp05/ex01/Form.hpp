#ifndef FORM_HPP
# define FORM_HPP
#include <iostream>
class Form{
	private:
		std::string name;
		bool signature;
		int	gradeToSign;
		int	gradeToExec;
		
	public:
		Form();
		~Form();
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form &obj);
		Form &operator=(const Form &obj);

		std::string getName(void)const;
		std::ostream & operator<<(std::ostream &out, const Form& bur);
		int	getGradeToSign(void)const;
		int	getGradeToExec(void)const;
		bool isSigned(void)const;
		void beSigned(Bureaucrat &b);
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
}
