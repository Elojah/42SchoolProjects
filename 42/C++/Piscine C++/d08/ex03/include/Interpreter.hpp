#ifndef INTERPRETER_H
# define INTERPRETER_H
# define SIZE_MAX_MEMORY 4000

# include <queue>
class IInstruction;

class Interpreter
{
public:
	Interpreter(void);
	~Interpreter(void);
	Interpreter(Interpreter const &src);
	Interpreter&	operator=(Interpreter const &rhs);

	void						read(std::string const &filename);
	void						exec(void);

protected:
private:
	int							*_i;
	std::queue<IInstruction *>	_q;
	int							_buffer[SIZE_MAX_MEMORY];
};

#endif
