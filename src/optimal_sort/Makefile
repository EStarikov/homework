all:
	gcc -S quicksort.c -o quicksort.s
	gcc main.c quicksort.c -o qsort

clean:
	rm -f *.o qsort *.s