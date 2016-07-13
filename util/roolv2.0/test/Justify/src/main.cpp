#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "TextJustify.hpp"
#define SEP ' '
#define IS_SEP(n) ((n) == ' ')

typedef struct		s_line
{
	char			*s;
	int				n_gaps;
}					t_line;

static void		get_line_from_buffer(const char *buffer
	, unsigned int *n_buffer, int n, t_line *line)
{
	int			i;
	int			offset;
	bool		space_state = false;

	/*Clean str*/
	for (int j = 0; j < n + 1; ++j)
		line->s[j] = '\0';
	/*Superficial remove of space in line begin*/
	for (offset = 0; offset < n && IS_SEP(buffer[*n_buffer + offset]); ++offset)
		;
	line->n_gaps = 0;
	/*Line with only spaces*/
	if (offset >= n)
		return ;
	*n_buffer += offset;
	/*Actual get_line_from_buffer*/
	for (i = 0;i < n && buffer[*n_buffer + i] != '\0'; ++i)
	{
		line->s[i] = buffer[*n_buffer + i];
	/*Here we count nbr gaps*/
		if ((space_state && IS_SEP(line->s[i])) || (!space_state && !IS_SEP(line->s[i])))
			continue ;
		space_state = !space_state;
		if (!IS_SEP(line->s[i]))
			++line->n_gaps;
	}
	line->s[i] = '\0';
}

static int		spaces_to_add(int step_between_offset_spaces, int current, int *spaces_offset)
{
	if (*spaces_offset > 0
		&& (current + 1) % step_between_offset_spaces == 0)
	{
		--(*spaces_offset);
		return (1);
	}
	else
		return (0);
}

static int		ft_strncat_offset(char *dest, const t_line *orig, int n, int offset)
{
	int			spaces_offset;
	int			space_per_word;
	int			step_between_offset_spaces;
	int			j;
	int			i = 0;
	int			current_gap = 0;

	/*space_per_word is the nbr of spaces to insert between every words of the line*/
	/*spaces_offset is the nbr of insertion which take one more spaces*/
	space_per_word = offset / (orig->n_gaps);
	spaces_offset = offset - (space_per_word * orig->n_gaps);
	if (spaces_offset == 0)
		step_between_offset_spaces = 0;
	else
		step_between_offset_spaces = orig->n_gaps / spaces_offset;
	for (j = 0; j < n && orig->s[j] != '\0'; ++j)
	{
		/*Offset is handle here*/
		if (offset > 0 && j != 0 && !IS_SEP(orig->s[j]) && IS_SEP(orig->s[j - 1]))
		{
			/*spaces_to_add determine which gaps will get the bonus space*/
			for (int k = space_per_word + spaces_to_add(step_between_offset_spaces, current_gap, &spaces_offset);
				k > 0; --k)
			{
				dest[i + j] = SEP;
				++i;
			}
			++current_gap;
		}
		/*Actual strncat*/
		dest[i + j] = orig->s[j];
	}
	return (i + j);
}

static int		ft_strncat_endl(char *dest, const t_line *orig, int n, int offset)
{
	int			res;

	if (offset > 0 && orig->n_gaps > 0)
		res = ft_strncat_offset(dest, orig, n, offset);
	else
	{
		int			i = 0;
		int			j;

		for (j = 0; j < n && orig->s[j] != '\0'; ++j)
			dest[i + j] = orig->s[j];
		res = i + j;
	}
	dest[res] = '\n';
	dest[res + 1] = '\0';
	return (res + 1);
}

static int		find_last_occ(const char *buffer, int n)
{
	/*lookin for last space in dat     0  */
	/*                            ^    ^  */
	/*____________________________|____|  */
	/*                            37   42 */
	/*                            i    n  */
	for (int i = n; i >= 0; --i)
	{
		if (IS_SEP(buffer[i]))
		{
			/*ATTENTION au --i dans le define*/
			while (i > 0 && IS_SEP(buffer[--i]))
				;
			return (i + 1);
		}
	}
	return (n);
}

static void		justify(const char *orig, char *dest, unsigned int width)
{
	dest[0] = '\0';
	if (width < 1)
		return ;

	t_line				line;
	unsigned int		size = strlen(orig);
	unsigned int		n_buffer = 0;
	int					end_dest = 0;

	line.s = (char *)malloc((width + 1) * sizeof(char));
	get_line_from_buffer(orig, &n_buffer, width + 1, &line);
	while (n_buffer < size)
	{
		unsigned int		n_last_separator;

		/*To trim end of line*/
		n_last_separator = find_last_occ(line.s, width);
		/*Case 1: All words can be copied*/
		if (IS_SEP(line.s[width]))
		{
			end_dest += ft_strncat_endl(dest + end_dest, &line, n_last_separator, width - n_last_separator);
			n_buffer += width + 1;
			goto next;
		}
		/*Case 2: End of file, this is last line*/
		else if (line.s[0] != '\0' && line.s[width - 1] == '\0')
		{
			ft_strncat_endl(dest + end_dest, &line, width, 0);
			break ;
		}
		/*Case 3: Last word is cutted so we remove from this line*/
		else
		{
			--line.n_gaps;
			/*Empty line*/
			if (line.s[0] != '\0' || n_last_separator != width)
				end_dest += ft_strncat_endl(dest + end_dest, &line, n_last_separator, width - n_last_separator);
			n_buffer += n_last_separator;
		}
		next:
		get_line_from_buffer(orig, &n_buffer, width + 1, &line);
	}
	free(line.s);
}

#include <iostream>
class CVisiteur : public IVisiteurJustifier
{
public:
	virtual BOOL	bVisit(const STInfoMot *stInfoMot)
	{
		std::cout << stInfoMot->pszMot << "\t\t" << '|'
				  << stInfoMot->nX << '\t' << '|'
				  << stInfoMot->nY << '\t' << '|'
				  << stInfoMot->nLargeur << std::endl;
		return (TRUE);
	}
};
class CVisiteurPrint : public IVisiteurJustifier
{
public:
	virtual BOOL	bVisit(const STInfoMot *stInfoMot)
	{
		static int line = 0;

		if (line != stInfoMot->nY)
			std::cout << std::endl;
		line = stInfoMot->nY;
		std::cout << stInfoMot->pszMot << ' ';
		return (TRUE);
	}
};
class CTailleMots : public ITailleMots
{
public:
	virtual int		nGetTailleMot(const PCXSTR pszMot)
	{
		return (strlen(pszMot));
	}
};

static void	execClasses(void)
{
	char				test[] = "	Lorem ipsum\
\
\
	VelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittestVelittest dolor voluptate velit do non laborum quis commodo aliqua sunt in velit aute quis minim dolore anim velit sint consectetur labore aute ullamco mollit labore adipisicing aliqua aliquip irure pariatur eu voluptate magna non officia reprehenderit est ex in dolor dolore proident ut fugiat laborum\
	nulla nulla dolore commodo do consectetur in cupidatat sunt exercitation veniam exercitation sunt ullamco in adipisicing consequat pariatur nulla id eiusmod nisi nulla consequat aliquip est Excepteur sint do dolor quis sunt laborum anim irure proident id\
	tempor non mollit et tempor\
\
\
	cillum non nulla quis in sit eu nisi magna Ut voluptate adipisicing proident adipisicing fugiat ad enim laborum proident irurelaborumquinisiculpanostrudadipisicingreprehenderitlaborelaboriscupidatat esse fugiat est officia culpa incididunt ullamco laborum commodo est nostrud laboris et qui esse nostrud voluptate aliqua\
	nisi aliquip cupidatat est labore occaecat ut elit officia irure dolore pariatur ut quis aliquip aliquip dolore ex adipisicing est veniam sed eiusmod dolore cillum sit reprehenderit\
	elit consectetur ex commodo Ut et labore aliqua minim aliquip ad in dolore veniam Duis ad\
	quis non id Excepteur cupidatat in eiusmod Ut cillum elit sed qui ad deserunt Excepteur ex minim aute cillum consequat nulla culpa nostrud tempor sunt minim Ut consectetur do consequat labore commodo Ut sed ullamco elit amet minim exercitation Excepteur sint dolor\
	proident cupidatat elit Excepteur adipisicing elit cupidatat cupidatat mollit nisi\
\
	voluptate cillum ullamco culpa laboris et et ea labore dolor ad velit fugiat sed sed ex Duis nisi reprehenderit incididunt tempor aliquip dolor consectetur aute reprehenderit in ut anim irure consequat cillum amet in officia.";

	CTextJustify		tj;
	CTailleMots			tm;

	printf("%s\n", test);
	tj.bJustifie(test, &tm, 80, -4);
	tj.__display();
	// for (int i = 60; i > 0; i -= 10)
	// {
	// 	tj.bJustifie(i, 5);
	// 	std::cout << std::endl;
	// 	tj.__display();
	// }
}

static void		exec(void)
{
	// static const char	buffer[] = "Lorem ipsum .";

	(void)justify;
	// printf("_____________________\n");
	// printf("%s\n", buffer);
	// printf("_____________________\n");
	// printf("%s\n", result);
	// printf("_____________________\n");
	execClasses();
}

int			main(int ac, char **av)
{
	(void)ac;
	(void)av;
	exec();
	return (0);
}
