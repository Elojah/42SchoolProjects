#ifndef FORM_H
# define FORM_H

# include <string>
class Bureaucrat;

class Form
{
public:
	Form(std::string const &name, int const gradeRequiredSign, int const gradeRequiredExe);
	virtual ~Form(void);
	Form(Form const &src);
	Form&	operator=(Form const &rhs);

	std::string const	&getName(void) const;
	bool				getIsSigned(void) const;
	int					getGradeRequiredSign(void) const;
	int					getGradeRequiredExe(void) const;

	void	beSigned(Bureaucrat const &b);
	void	execute(Bureaucrat const & executor) const;
	virtual void			action(void) const = 0;

	class GradeTooHighException: public std::exception
	{
	public:
		GradeTooHighException(void);
		GradeTooHighException(GradeTooHighException const &gTHE);
		virtual ~GradeTooHighException(void) throw();

		virtual char const		*what(void) const throw();
	private:
		GradeTooHighException	&operator=(GradeTooHighException const &gTHE);
	};
	class GradeTooLowException: public std::exception
	{
	public:
		GradeTooLowException(void);
		GradeTooLowException(GradeTooLowException const &gTLE);
		virtual ~GradeTooLowException(void) throw();

		virtual char const 		*what(void) const throw();
	private:
		GradeTooLowException	&operator=(GradeTooLowException const &gTLE);
	};

protected:
private:
	Form(void);

	std::string const	_name;
	bool				_isSigned;
	int const			_gradeRequiredSign;
	int const			_gradeRequiredExe;
};

std::ostream&	operator<<(std::ostream& stream, Form const &s);

#endif
