all: project.c
	gcc -o project0 project0.c

all2:
	gcc -o project project.c

clean:
	rm project0

clean2:
	rm project0

run:
	./project