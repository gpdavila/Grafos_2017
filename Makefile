
CC           = g++
CFLAGS       = -Wall

main.o : main.cpp
	# compiling main.c
	$(CC) $(CFLAGS) -o  dijkstra.exec main.cpp 
clean:
	rm -f *.exec
