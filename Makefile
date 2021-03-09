all: project.c
	gcc -o a project.c

clean:
	rm a

run:
	./a