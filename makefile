CC = gcc

all: ppmp3.o main.o
	$(CC) main.o ppmp3.o -o main.out

ppmp3.o:
	$(CC) -c src/ppmp3.c

main.o:
	$(CC) -c src/main.c

clean:
	rm -rf *.o || true
	rm -rf *.out || true
	rm -rf *.obj || true