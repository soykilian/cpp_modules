#include "Bureaucrat.hpp"
Bureaucrat::Bureaucrat(): name("Bureaucrat"){
	this->grade = 150;
	std::cout << "Default constructor called"<< std::endl;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Default destructor called"<< std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name){
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): name(obj.name){
	this->grade = obj.getGrade();
	std::cout << "Copy destructor called"<< std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj){
	this->grade = obj.getGrade();
	std::cout << "Assignation operator called"<< std::endl;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat& bur)
{
    out << bur.getName() << " has grade : " << bur.getGrade();
    return (out);
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
