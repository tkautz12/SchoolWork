IDIR=../../include/
CC=gcc
CFLAGS = -std=c99 -I$(IDIR) -Wall -Werror --pedantic
LIBFLAGS = -L../../lib/ -lmy -llist

all:
	$(CC) client.c $(CFLAGS) $(LIBFLAGS) -o client
	$(CC) server.c $(CFLAGS) $(LIBFLAGS) -o server

clean:
	rm -f *.o

fclean: clean
	rm -f client
	rm -f server

re: fclean all
