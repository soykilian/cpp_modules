#include "Form.hpp"
Form::Form(): name("default"), signature(false), gradeToSign(150), gradeToExec(150){
	std::cout << "Default constructor called"<< std::endl;
}

Form::~Form(){
	std::cout << "Default destructor called"<< std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec): name(name), signature(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec) {
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec < 1)
		throw GradeTooLowException();
}

Form::Form(const Form &obj): name(obj.name), signature(obj.signature), gradeToSign(obj.gradeToSign), gradeToExec(obj.gradeToExec){
	std::cout << "Copy destructor called"<< std::endl;
}

Form &Form::operator=(const Form &obj){
	if (this != &obj)
		*this = obj;
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

void Form::beSigned(Bureaucrat &b){
	if (b.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();
	std::cout << b.getName() << " signed form " << this->getName() << "."<< std::endl;
	this->signature = true;
}
