NAME        =   rush00
CC          =   clang++
LIB			=	-lncurses
CFLAGS      =   -Wall -Wextra -Werror
SRC         =   *.cpp

all: rush00

rush00:
	    @$(CC) $(SRC) -o $(NAME) $(LIB)

clean:
	    @echo "\033[92m    Nothing to clean\033[0m"

fclean: clean
	    @echo "\033[92m    RM    $(NAME)\033[0m"
		    @rm -f $(NAME)

re: fclean all
