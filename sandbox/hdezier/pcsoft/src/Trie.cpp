#include "Trie.hpp"
#include <iostream>/*DEBOG*/

Trie::Trie(void) {
	_root.create();
}

Trie::Trie(Trie const &src) {
	if (this != &src)
		*this = src;
}

Trie::~Trie(void) {
}

Trie		&Trie::operator=(Trie const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

/*May be done with CHAR * instead of STD::STRING*/
void	Trie::addValue(std::string const &s, char *filename) {
	_root.addValue(s.c_str(), filename);
}

void	Trie::searchValue(std::string &s) {
	sNode	*node;

	if ((node = _root.getNode(&(s[0]))) != NULL
		&& node->files != NULL) {
		node->files->display();
	} else {
		std::cout << "No results found" << std::endl;
	}
}
