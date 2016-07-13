#include "Node.hpp"
#include <iostream>
#include <stddef.h>

Node::Node(void) :
	_children(NULL),
	_files(NULL) {
}

Node::Node(Node const &src) {
	if (this != &src)
		*this = src;
}

Node::~Node(void) {
	if (_files != NULL) {
		_files->remove();
		delete _files;
	}
	if (_children != NULL) {
		delete[] _children;
	}
}

Node		&Node::operator=(Node const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

/*
**Create children nodes when needed: if (children == NULL) => NOT INIT
*/
void		Node::create(void) {
	_children = new Node[MAX_CHARS_ASCII];
}

void		Node::addValue(char const *s, char *value) {
	int		c;

	if (!s) {
		return ;
	} else if (*s == '\0') {
		if (_files != NULL) {
			_files->addLst(value);
		} else {
			_files = new sList;
			_files->create(value);
		}
	} else if (*s > 0) {/*Check here for valid chars (unsigned, etc.)*/
		c = static_cast<int>(*s);
		if (_children[c]._children == NULL) {
			_children[c].create();
		}
		_children[c].addValue(s + 1, value);
	}
}

Node		*Node::getSNode(char *s) {
	int		n;

	if (*s == '\0') {
		return (this);
	} else if ((n = static_cast<int>(*s)) >= 0 && n < MAX_CHARS_ASCII/*Check here for valid chars (unsigned, etc.)*/
		&& _children[n]._children != NULL) {
		return (_children[n].getSNode(s + 1));
	} else {
		return (NULL);
	}
}

/*
**To improve by replacing with operator<< ?
*/
void		Node::display(void) {
	if (_files != NULL) {
		_files->display();
	} else {
		std::cout << "No results found" << std::endl;
	}
}
