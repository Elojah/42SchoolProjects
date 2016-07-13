#ifndef REPLACE_H
# define REPLACE_H

# include <string>

class Replace
{
public:
	Replace(void);
	~Replace(void);
	void	exec(const std::string &filename, const std::string &s1, const std::string &s2);
protected:
private:
};

#endif
