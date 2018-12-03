IDIR=../../include/
CC=gcc
CFLAGS = -std=c99 -I$(IDIR) -Wall -Werror --pedantic
LIBFLAGS = -L../../lib/ -lmy

all:
	$(CC) minishell.c $(CFLAGS) $(LIBFLAGS) -o minishell

clean:
	rm -f *.o

fclean: clean
	rm -f minishell

re: fclean all
