#include <iostream>

int		main(int ac, char **av)
{
	int		i;
	int		j;

	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (i = 1; i < ac ; ++i)
		{
			for (j = 0; av[i][j] ; ++j)
			{
				if (islower(av[i][j]))
					std::cout << (char)toupper(av[i][j]);
				else
					std::cout << av[i][j];
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
