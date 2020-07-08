OBJECTS=cos330.o sin330.o tan330.o exp330.o log330.o arccos330.o arcsin330.o arctan330.o

bin/cli:	bin lib lib/libmath330.a cli/cli.c 
	gcc -o bin/cli cli/cli.c -Iinclude -Llib -lmath330 -lm

lib/libmath330.a: lib $(OBJECTS)
	ar r lib/libmath330.a $(OBJECTS)

include: math330.h
	mkdir -p include
	cp math330.h include

lib:
	mkdir -p lib

bin:
	mkdir -p bin

arctan330.o: include trig/arctan330.c
	gcc -c -Iinclude trig/arctan330.c

arcsin330.o: include trig/arcsin330.c
	gcc -c -Iinclude trig/arcsin330.c

arccos330.o: include trig/arccos330.c
	gcc -c -Iinclude trig/arccos330.c

cos330.o: include trig/cos330.c
	gcc -c -Iinclude trig/cos330.c

sin330.o: include trig/sin330.c
	gcc -c -Iinclude trig/sin330.c

tan330.o: include trig/tan330.c
	gcc -c -Iinclude trig/tan330.c

exp330.o: include exp/exp330.c
	gcc -c -Iinclude exp/exp330.c

log330.o: include exp/log330.c
	gcc -c -Iinclude exp/log330.c

clean:
	rm -rf lib bin include
	rm -f *.o
