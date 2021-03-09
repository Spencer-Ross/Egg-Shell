#C for object files, E for executables, A for all, L for lib flags
CFLAGS=-c 
EFLAGS=-lreadline 
AFLAGS=-o esh -lreadline 

esh: esh.o
	cc -o esh esh.o

esh.o: esh.c
	cc -c -lreadline esh.c

all: esh.c
	cc -o esh -lreadline esh.c

clean:
	rm -f esh.o && rm -f esh

run: esh
	./esh
