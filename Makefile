
CC           = gcc
CFLAGS       = -Wall

main.o : main.c
	# compiling main.c
	$(CC) $(CFLAGS) -o  dijkstra.exec main.c 
clean:
	rm -f *.exec
