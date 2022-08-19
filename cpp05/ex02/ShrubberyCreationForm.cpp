#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string &target): Form("Shrubbery", 145, 137){
	this->target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &obj){
	*this = obj;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &obj){
	Form::operator=(obj);
	return (*this);
}
std::string	ShrubberyCreationForm::getTarget(void)const{
	return (this->target);
}
void ShrubberyCreationForm::executeAction(Bureaucrat const & executor) const{
	if (executor.getGrade() > this->getGradeToExec())
		throw Form::GradeTooLowException();
	std::ofstream	file_out;
	std::string		name = this->target + "_shrubbery";
	file_out.open(name.c_str());
    if (!file_out.is_open())
        return ;
	file_out
    <<           "v .   ._, |_  .,"         << std::endl
    <<       "`-._\\/  .  \\ /    |/_"        << std::endl
    <<            "\\\\  _\\, y | \\//"         << std::endl
    <<      "_\\_.___\\, \\/ -.\\||"          << std::endl
    <<        "`7-,--.`._||  / / ,"         << std::endl
    <<        "/'     `-. `./ / |/_.'"      << std::endl
    <<                 "|    |//"           << std::endl
    <<                 "|_    /"            << std::endl
    <<                 "|-   |"             << std::endl
    <<                 "|   =|"             << std::endl
    <<                 "|    |"             << std::endl <<
  "--------------------/ ,  . \\--------._"  << std::endl;
}
