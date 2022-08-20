#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
	this->name = "Bureaucrat";
	this->grade = 0;
	std::cout << "Bureaucrat created"<< std::endl;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat destroyed"<< std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade){
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->name = name;
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj){
	*this = obj;
	std::cout << "Copy destructor called"<< std::endl;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat& bur)
{
    out << bur.getName() << " has grade : " << bur.getGrade();
    return (out);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj){
	this->name = obj.getName();
	this->grade = obj.getGrade();
	std::cout << "Assignation operator called"<< std::endl;
	return (*this);
}

std::string Bureaucrat::getName(void)const{
	return (this->name);
}

int	Bureaucrat::getGrade(void)const{
	return (this->grade);
}

void Bureaucrat::incrementGrade(){
	if (this->grade == 1)
		throw GradeTooHighException();
	this->grade--;	
	std::cout << "Increment grade method called"<< std::endl;
}

void Bureaucrat::decrementGrade(){
	if (this->grade == 150)
		throw GradeTooLowException();
	this->grade++;
	std::cout << "Decrement grade method called"<< std::endl;
}

void Bureaucrat::signForm(Form &f)const{
	try{
		f.beSigned(*this);
	}catch(std::exception &e)
	{
		std::cout << this->getName() << " tried to sign " << f.getTarget() << " but threw an exception: " << e.what() << std::endl;
	}
}
void Bureaucrat::executeForm(Form &f)const{
	try{
		f.execute(*this);
	}catch(std::exception &e)
	{
		std::cout << this->getName() << " tried to execute " << f.getTarget() << " but threw an exception: " << e.what() << std::endl;
	}
}