# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leeios <leeios@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/06 13:12:27 by hdezier           #+#    #+#              #
#    Updated: 2016/04/19 20:12:18 by leeios           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Directories
SERVER_DIR = server
CLIENT_DIR = client

#RULES
all :
	make -C $(SERVER_DIR)
	make -C $(CLIENT_DIR)

clean :
	make clean -C $(SERVER_DIR)
	make clean -C $(CLIENT_DIR)

fclean :
	make fclean -C $(SERVER_DIR)
	make fclean -C $(CLIENT_DIR)

server:
	make -C $(SERVER_DIR)

client:
	make -C $(CLIENT_DIR)

re : fclean all
