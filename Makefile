#C for object files, E for executables, A for all, L for lib flags
AFLAGS=-o esh 

esh: esh.o
	cc -o esh esh.o -lreadline

esh.o: esh.c
	cc -c esh.c -lreadline

all: esh.c
	cc $(AFLAGS) esh.c -lreadline

clean:
	rm -f esh.o && rm -f esh

run: esh
	./esh
