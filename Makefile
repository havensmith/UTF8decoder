all: charactercount.c
	gcc -o charactercount charactercount.c

clean:
	rm charactercount

run:
	./charactercount