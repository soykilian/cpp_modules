#ifndef INTERN_HPP
# define INTERN_HPP
#include "Form.hpp"

class Intern{
	public:
		Intern();
		~Intern();
		Intern(Intern const &obj);
		Intern &operator=(Intern const &obj);
		Form *makeForm(std::string name, std::string target);
	private:
		typedef struct t_form{
			std::string	name;
			Form 		*form;
		}	s_form;
};
#endif
