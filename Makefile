all: project.c
	gcc -o project0 project0.c
	gcc -o project project.c

clean:
	rm project0
	rm project

run:
	./project