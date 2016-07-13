#ifndef OFFICE_BLOCK_HPP
# define OFFICE_BLOCK_HPP

# include "Bureaucrat.hpp"
# include "Intern.hpp"

class OfficeBlock
{
public:
	OfficeBlock(void);
	OfficeBlock(Bureaucrat *sB, Bureaucrat *eB, Intern *i);
	~OfficeBlock(void);

	void			setSigner(Bureaucrat *b);
	void			setExecutor(Bureaucrat *b);
	void			setIntern(Intern *i);

	void			doBureaucracy(std::string const &fN, std::string const &tN);

private:
	Bureaucrat			*_signer;
	Bureaucrat			*_executer;
	Intern				*_slave;

	OfficeBlock(OfficeBlock const &rhs);
	OfficeBlock		&operator=(OfficeBlock const &rhs);
};

#endif
