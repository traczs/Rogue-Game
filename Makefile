all:a.out

a.out: src/functions.c src/main.c
	gcc -Wall -std=c99 src/main.c src/functions.c -Iinclude -lncurses