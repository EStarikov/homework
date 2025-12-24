all: qsort

quicksort.s: quicksort.c
	gcc -S quicksort.c -o quicksort.s

quicksort.o: quicksort.s
	gcc -c quicksort.s -o quicksort.o

main.o: main.c
	gcc -c main.c -o main.o

qsort: main.o quicksort.o
	gcc main.o quicksort.o -o qsort

clean:
	rm -f *.o qsort *.s
