#ifndef FILE_SCANNER_H
# define FILE_SCANNER_H

# include <string>
# include "Trie.hpp"
class Trie;

class FileScanner
{
public:
	FileScanner(void);
	~FileScanner(void);
	FileScanner(FileScanner const &src);
	FileScanner&	operator=(FileScanner const &rhs);

	void			scan(char *path);
	void			ask(void);
protected:
private:

	bool			isScannableFile(char const *name);
	void			scanChildren(char *path);
	void			scanFile(char *filename);

	Trie			_t;
};

#endif
