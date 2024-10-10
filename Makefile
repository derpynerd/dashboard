CC = gcc # specifying compiler
CFLAGS = -g -Wall `pkg-config --cflags gtk4` # compiler flags 
LDFLAGS = `pkg-config --libs gtk4` # linker flags $(shell pkg-config --libs gtk4)

all: run

context: context.c
	$(CC) $(CFLAGS) context.c -o context $(LDFLAGS)

run: context
	chmod +x context
	./context

clean:
	rm -f context

rerun: context.c
	$(CC) $(CFLAGS) context.c -o context $(LDFLAGS)
	chmod +x context
	./context
