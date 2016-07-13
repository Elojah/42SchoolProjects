#ifndef NODE_H
# define NODE_H

# define MAX_CHARS_ASCII 256
# include "List.hpp"

class Node
{
public:
	Node(void);
	~Node(void);

	void		create(void);
	void		addValue(char const *s, char *value);
	Node		*getSNode(char *s);
	void		display(void);

protected:
private:

	Node(Node const &src);
	Node&	operator=(Node const &rhs);

	Node		*_children;
	sList		*_files;

};

#endif
