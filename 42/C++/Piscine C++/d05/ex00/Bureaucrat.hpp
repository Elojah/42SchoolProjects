#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>

class Bureaucrat
{
public:
	Bureaucrat(std::string const &s, int const grade);
	~Bureaucrat(void);
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat			&operator=(Bureaucrat const &rhs);

	std::string const	&getName(void) const;
	int					getGrade(void) const;

	Bureaucrat			&operator++(void);
	Bureaucrat			&operator--(void);

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
	Bureaucrat(void);

	std::string		_name;
	int				_grade;
};

std::ostream&	operator<<(std::ostream& stream, Bureaucrat const &s);

#endif
