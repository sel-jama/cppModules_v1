

void				Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << "Bureaucrat " << this->name << " successfully signed ";
		std::cout << "the form " << form.getName() << "!" << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << *this << ". ";
		std::cout << e.what() << std::endl;
	}
}

void				Bureaucrat::executeForm(const Form& form)
{
	try
	{
		form.execute(*this);
		std::cout << this->name << " executes form " << form.getName() << std::endl;
	}
	catch (Form::InvalidFormException &e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& out, Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (out);
}
