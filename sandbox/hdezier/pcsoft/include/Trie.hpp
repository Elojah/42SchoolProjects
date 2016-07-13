#ifndef TRIE_H
# define TRIE_H

/*
**MAX_CHARS_ASCII may up to 256 (smask256)
*/
# define MAX_CHARS_ASCII 256
# include <stddef.h>
# include <string>
# include <string.h>
# include <iostream>

class Trie
{
public:
	Trie(void);
	~Trie(void);
	Trie(Trie const &src);
	Trie&	operator=(Trie const &rhs);
	void	addValue(std::string const &value, char *filename);
	void	searchValue(std::string &s);
protected:
private:

	struct				sMask256 {
		long long		fi64;
		long long		se64;
		long long		th64;
		long long		fo64;
		sMask256		&operator=(int n) {
			fi64 = n;
			se64 = 0;
			th64 = 0;
			fo64 = 0;
			return (*this);
		}
		void			setByte(int n) {
			if (n < 64) {
				fi64 = fi64 | (1 << n);
			} else if (n < 128) {
				se64 = se64 | (1 << (n - 64));
			} else if (n < 192) {
				th64 = th64 | (1 << (n - 128));
			} else if (n < 256) {
				fo64 = fo64 | (1 << (n - 192));
			}
		}
		bool			checkByte(int n) {
			if (n < 64) {
				return (fi64 & (1 << n));
			} else if (n < 128) {
				return (se64 & (1 << (n - 64)));
			} else if (n < 192) {
				return (th64 & (1 << (n - 128)));
			} else if (n < 256) {
				return (fo64 & (1 << (n - 192)));
			} else {
				return (false);
			}
		}
	};

	/*
	**Basic struct list to register filenames
	*/
	struct			sList {
		char		*value;
		sList		*next;

		void		create(char *valueSet) {
			value = strdup(valueSet);/*DIRTY STUFF*/
			next = NULL;
		}
		void		addLst(char *valueSet) {
			if (strcmp(value, valueSet) == 0) {
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
		void		remove(void) {
			if (next != NULL) {
				next->remove();
				delete next;
				free (value);
			}
		}
	};

	/*
	**Trie nodes implementations
	*/
	struct			sNode {
		sNode		*children;
		sList		*files;
		sMask256	bmaskNext;/*Needs to be sMask256 ! 256 char = 256 bytes*/

		void		create(void) {
			bmaskNext = 0;
			files = NULL;
			children = new sNode[MAX_CHARS_ASCII];
		}
		void		addValue(char const *s, char *value) {
			int		c;

			if (!s) {
				return ;
			} else if (*s == '\0') {
				if (files != NULL) {
					files->addLst(value);
				} else {
					files = new sList;
					files->create(value);
				}
			} else if (*s > 0) {/*Check here for valid chars (unsigned, etc.)*/
				c = static_cast<int>(*s);
				if ((bmaskNext.checkByte(c)) == 0 || children[c].children == NULL) {
					children[c].create();
					bmaskNext.setByte(c);
				}
				children[c].addValue(s + 1, value);
			}
		}
		sNode		*getNode(char *s) {
			if (*s == '\0') {
				return (this);
			} else if ((bmaskNext.checkByte(*s)) != 0) {
				return (children[static_cast<int>(*s)].getNode(s + 1));
			} else {
				return (NULL);
			}
		}
		void		remove(void) {
			if (files != NULL) {
				files->remove();
				delete files;
			}
			delete[] children;
		}
	};

	sNode			_root;
};

#endif
