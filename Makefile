# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/07 17:08:49 by vbranco      #+#   ##    ##    #+#        #
#    Updated: 2018/05/02 09:43:08 by vbranco     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME        =   ft_ls 

HEADER      =   ft_ls.h 

FILENAMES   =   main.c ft_flag.c ft_stat.c ft_stat2.c\
	ft_fileinfoprint.c ft_add_node.c ft_ls.c \
	ft_count_args.c ft_args.c ft_fileinfo_sort.c\
	ft_add_file_back.c ft_dir.c ft_color_and_long.c\
	ft_initialise.c ft_list_dell.c ft_flag_a.c ft_display_dir.c\


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
		@echo "\033[31m Cleanning ft_ls"
		@rm -rf build/
		@$(MAKE) -C $(L_FT) clean

fclean: clean
	    @echo "\033[31m FCleanninf ft_ls"
		@rm -f $(NAME)
		@$(MAKE) -C $(L_FT) fclean

re:
		@echo "\033[32m RE ft_ls"
		@$(MAKE) fclean
		@$(MAKE) all

build:
	    @echo "\033[32m Making ft_ls"
		@mkdir build/

$(NAME): $(OBJECTS)
		@$(MAKE) -C $(L_FT)
		@gcc $(FLAGS) -I  $(HEADER) $(SOURCES) $(LIB) -o $@ #-g
		@echo " Ready to play"

build/%.o: ./%.c | build
	    @gcc $(FLAGS) $(LIB_INC) -I $(HEADER) -c $< -o $@
