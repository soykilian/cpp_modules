#include "Form.hpp"
Form::Form(){
	this->name = "Default";
	this->gradeToSign = 150;
	this->gradeToSign = 150;
	this->signature = false;
	std::cout << "Default constructor called"<< std::endl;
}

Form::~Form(){
	std::cout << "Default destructor called"<< std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec){
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec < 1)
		throw GradeTooLowException();
	this->name = name;
	this->gradeToSign = gradeToSign;
	this->gradeToExec = gradeToExec;
	this->signature = false;
}

Form::Form(const Form &obj){
	*this = obj;
	std::cout << "Copy destructor called"<< std::endl;
}

Form &Form::operator=(const Form &obj){
	this->name = obj.getName();
	this->gradeToSign = obj.getGradeToSign();
	this->gradeToExec = obj.getGradeToExec();
	this->signature = obj.isSigned();
	std::cout << "Assignation operator called"<< std::endl;
	return (*this);
}

std::ostream & operator<<(std::ostream &out, const Form& bur){
    out << "Form " << bur.getName() << " requires grade : " << bur.getGradeToSign() << " to be signed and grade: " << bur.getGradeToExec() << " to be executed. State of signature : "<< bur.isSigned() << std::endl;
    return (out);
}

std::string Form::getName(void)const{
	return(this->name);
}

int	Form::getGradeToSign(void)const{
	return (this->gradeToSign);
}

int	Form::getGradeToExec(void)const{
	return (this->gradeToExec);

}
bool Form::isSigned(void)const{
	return (this->signature);
}

void Form::beSigned(Bureaucrat const &b){
	if (b.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();
	std::cout << b.getName() << " signed form " << this->getName() << "."<< std::endl;
	this->signature = true;
}

void Form::execute(Bureaucrat const & executor) const{
	if (this->isSigned() == false){
		std::cout << this->getName() + " is not signed, then it cannot be executed"<< std::endl;
		throw NotSigned();
	}
	if (executor.getGrade() > this->getGradeToExec())
	{
		std::cout << executor.getName() + " cannot execute " + this->getName() << std::endl;
		throw Form::GradeTooLowException();
	}
	std::cout << executor.getName() + " executed " + this->getName() << std::endl;
	this->executeAction();
}

