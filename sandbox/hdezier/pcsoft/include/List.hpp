#ifndef LIST_H
# define LIST_H

# include <stddef.h>
# include <string.h>
# include <iostream>

/*
**Basic struct list to register filenames
*/
struct			sList {
	char		*value;
	sList		*next;

	void		create(char *valueSet) {
		value = valueSet;
		next = NULL;
	}
	void		addLst(char *valueSet) {
		if (value != NULL && strcmp(value, valueSet) == 0) {
			return ;
		} else if (next != NULL) {
			next->addLst(valueSet);
		} else {
			next = new sList;
			next->create(valueSet);
		}
	}
	void		display(void) {
		std::cout << "\t" << value << std::endl;
		if (next != NULL) {
			next->display();
		}
	}
	/*
	**freeValues must be used once (FileScanner.files)
	*/
	void		freeValues(void) {
		if (next != NULL) {
			next->freeValues();
		}
		if (value != NULL) {
			free(value);
			value = NULL;
		}
	}
	void		remove(void) {
		if (next != NULL) {
			next->remove();
			delete next;
			next = NULL;
		}
	}
};

#endif
