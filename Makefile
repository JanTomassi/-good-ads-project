CC = g++
CFLAGS = -DEVAL -std=gnu++11 -O2 -pipe -static -s

main: main.o
	$(CC) $(CFLAGS) -o main main.o

clear:
	rm -f core *.o main
