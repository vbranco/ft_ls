NAME        =   ft_ls 

HEADER      =   ft_ls.h 

FILENAMES   =   main.c ft_init.c

SOURCES     =   $(addprefix ./, $(FILENAMES))

OBJECTS     =   $(addprefix build/, $(FILENAMES:.c=.o))

L_FT        =   ./libft

LIB	    =   ./libft/libft.a

LIB_LNK     =   -L $(L_FT) -l ft

LIB_INC     =   -I $(L_FT)/libft.h

FLAGS	    =  -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

clean:
		rm -rf build/
		@$(MAKE) -C $(L_FT) clean

fclean: clean
	    @echo "\033[31m"
		rm -f $(NAME)
		@$(MAKE) -C $(L_FT) fclean

re:
	    @$(MAKE) fclean
		@$(MAKE) all

build:
	    @echo "\033[35m"
		mkdir build/

$(NAME): $(OBJECTS)
	    @$(MAKE) -C $(L_FT)
		@echo "\033[32m"
		gcc $(FLAGS) -I $(HEADER) $(SOURCES) $(LIB) -o $@

build/%.o: ./%.c | build
	    gcc $(FLAGS) $(LIB_INC) -I $(HEADER) -c $< -o $@
