res: main.c
	rm -rf main
	gcc -Wall -o res main.c bstree.c hashtab.c -lm
