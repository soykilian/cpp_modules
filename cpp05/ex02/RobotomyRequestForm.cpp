#include "RobotomyRequestForm.hpp"
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(std::string &target): Form("Robotomy Request Form", 72, 45){
	this->target = target;
}

RobotomyRequestForm::~RobotomyRequestForm(){}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj){
	*this = obj;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &obj){
	Form::operator=(obj);
	return (*this);
}
std::string	RobotomyRequestForm::getTarget(void)const{
	return (this->target);
}

void RobotomyRequestForm::executeAction(Bureaucrat const & executor) const{
	if (executor.getGrade() > this->getGradeToExec())
	{
		std::cout << "ATTENTION!! Failure" << std::endl;
		throw Form::GradeTooLowException();
	}
	std::cout << this->getTarget() + "has been robotomized successfully up to 50% of the time" << std::endl;
}
