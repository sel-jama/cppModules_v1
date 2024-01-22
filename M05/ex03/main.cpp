#include "Intern.hpp"

int main()
{
	Intern	intern;
	AForm	*f;

	f = intern.makeForm("shurbbery creation", "Bender3");
	if (f)
		std::cout << "target :" << f->getTarget() << std::endl;

	f = intern.makeForm("robotomy request", "Bender2");
	if (f)
		std::cout << "target :" << f->getTarget() << std::endl;

	f = intern.makeForm("prsidentila pardon", "Bender1");
	if (f)
		std::cout << "target :" << f->getTarget() << std::endl;
	
	delete f;

	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("none", "Bender");
	delete rrf;

	return 0;
}
