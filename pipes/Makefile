IDIR=../../include/
CC=gcc
CFLAGS = -std=c99 -I$(IDIR) -Wall -Werror --pedantic
LIBFLAGS = -L../../lib/ -lmy

all:
	$(CC) pipes.c $(CFLAGS) $(LIBFLAGS) -o pipes

clean:
	rm -f *.o

fclean: clean
	rm -f pipes

re: fclean all


