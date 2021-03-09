all: project.c
	gcc -o a project.c

clean:
	rm a.out

run:
	./a