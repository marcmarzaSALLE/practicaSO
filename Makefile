all: clean fleck

reads.o: reads.c reads.h
	gcc -c reads.c -Wall -Wextra 

fleck.o: fleck.c fleck.h
	gcc -c fleck.c -Wall -Wextra

fleck: fleck.o reads.o
	gcc fleck.o reads.o -o fleck -Wall -Wextra

clean:
	rm -f *.o fleck


 