# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/07 17:08:49 by vbranco      #+#   ##    ##    #+#        #
#    Updated: 2018/04/07 17:21:44 by vbranco     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME        =   ft_ls 

HEADER      =   ft_ls.h 

FILENAMES   =   main.c ft_init_flag.c ft_flag.c ft_stat.c ft_flag_status.c \
	ft_fileinfoprint.c ft_init_fileinfo.c ft_init_node.c ft_node_back_add.c \
	ft_node_front_add.c ft_node_sort_add.c ft_nodedell.c ft_ls.c \
	ft_dir.c ft_count_args.c ft_args.c ft_init_space.c ft_fileinfo_sort.c\
	ft_add_file_back.c ft_fileinfo_dell.c\


SOURCES     =   $(addprefix ./, $(FILENAMES))

OBJECTS     =   $(addprefix build/, $(FILENAMES:.c=.o))

L_FT        =   ./libft

LIB	  	 	=   ./libft/libft.a

LIB_LNK     =   -L $(L_FT) -l ft

LIB_INC     =   -I $(L_FT)/libft.h

#FLAGS	    =  -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

clean:
		rm -rf build/
#		@$(MAKE) -C $(L_FT) clean

fclean: clean
	    @echo "\033[31m"
		rm -f $(NAME)
#		@$(MAKE) -C $(L_FT) fclean

re:	fclean all
	#   @$(MAKE) fclean
	#	@$(MAKE) all

build:
	    @echo "\033[35m"
		mkdir build/

$(NAME): $(OBJECTS)
	#   @$(MAKE) -C $(L_FT)
		@echo "\033[32m"
		gcc $(FLAGS) -I  $(HEADER) $(SOURCES) $(LIB) -o $@ -g

build/%.o: ./%.c | build
	    gcc $(FLAGS) $(LIB_INC) -I $(HEADER) -c $< -o $@
