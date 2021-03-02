CC = gcc
OUTPUT = ppmp3

all: compile_main
	$(CC) main.o ppmp3.o -o $(OUTPUT)

compile_main: compile_ppmp3
	$(CC) -c src/main.c

compile_ppmp3:
	$(CC) -c src/ppmp3.c

clean:
	rm -rf *.o || true
	rm -rf $(OUTPUT) || true
	rm -rf *.obj || true