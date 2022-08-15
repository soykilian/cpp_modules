#include "Ice.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();

	std::cout << std::endl;

    src->learnMateria(new Ice());
	std::cout << std::endl;

    src->learnMateria(new Cure());
	std::cout << std::endl;

    ICharacter* me = new Character("me");
	std::cout << std::endl;

    AMateria* tmp;
	std::cout << std::endl;

    tmp = src->createMateria("ice");
    me->equip(tmp);
	std::cout << std::endl;

    tmp = src->createMateria("cure");
    me->equip(tmp);
	std::cout << std::endl;

    tmp = src->createMateria("ice");
    me->equip(tmp);
	std::cout << std::endl;

    tmp = src->createMateria("cure");
    me->equip(tmp);
	std::cout << std::endl;

    tmp = src->createMateria("ice");
    me->equip(tmp);
	std::cout << std::endl;

    ICharacter* bob = new Character("bob");
	std::cout << std::endl;

    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    me->use(4, *bob);
	std::cout << std::endl;

    delete bob;
    delete me;
    delete src;

    return 0;
}
