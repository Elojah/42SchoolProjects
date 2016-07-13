#ifndef LEXER_H
# define LEXER_H

class Parser;

class Lexer
{
public:
	Lexer(void);
	~Lexer(void);
	void		exec(const Parser &p);
protected:
private:
};

#endif
