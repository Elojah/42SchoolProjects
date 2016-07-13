#include "Token.hpp"
#include <iostream>

static void		exec(void)
{
	Token<TokensDefinitions::sOperator>	TokenOperator;
	Token<TokensDefinitions::sOperand>	TokenOperand;
	Token<TokensDefinitions::sEntity>	TokenEntity;

	std::cerr << (int)TokenOperator.detect("<=>a") << std::endl;
	std::cerr << (int)TokenOperator.detect("!t") << std::endl;
	std::cerr << (int)TokenEntity.detect("ret ") << std::endl;
}

int			main(int ac, char **av)
{
	(void)ac;
	(void)av;
	exec();
	return (0);
}
