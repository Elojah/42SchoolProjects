#ifndef F_INSTRUCTION_H
# define F_INSTRUCTION_H

# include <map>
class IInstruction;

class FInstruction
{
public:
	FInstruction(void);
	~FInstruction(void);
	FInstruction(FInstruction const &src);
	FInstruction&	operator=(FInstruction const &rhs);
	IInstruction				*makeInstruction(char c);

protected:
private:
	typedef IInstruction	*(FInstruction::*maker)(void) const;

	IInstruction				*makeIncp(void) const;
	IInstruction				*makeDecp(void) const;
	IInstruction				*makeInc(void) const;
	IInstruction				*makeDec(void) const;
	IInstruction				*makeOut(void) const;
	IInstruction				*makeIn(void) const;
	IInstruction				*makeLoopBegin(void) const;
	IInstruction				*makeLoopEnd(void) const;

	const static std::map<char, maker>		_map;
	static std::map<char, maker>			createInstructionsMap(void);
};

#endif
