#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/09/27 13:33:19 by erobert           #+#    #+#              #
#    Updated: 2016/03/28 10:51:27 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_nm ft_otool
TMPS = Makefile~

.PHONY: all nm otool clean fclean re

all: nm otool

nm:
	make -C nm/
	ln -sf nm/ft_nm ft_nm
otool:
	make -C otool/
	ln -sf otool/ft_otool ft_otool

clean:
	make -C nm/ clean
	make -C otool/ clean

fclean: clean
	make -C nm/ fclean
	make -C otool/ fclean
	/bin/rm -f $(NAME) $(TMPS)

re: fclean all
