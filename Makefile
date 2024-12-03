CFLAGS = -Wall
# Remove this -lm flag on Mac
LDLIBS = -lm

tree:		global.o bt.o bst.o avl.o main.o ui.o
			gcc $(CLFAGS) -o tree bt.o bst.o avl.o ui.o global.o main.o $(LDLIBS)

global.o:	global.h global.c
			gcc $(CFLAGS) -c global.c

main.o:		main.c ui.h global.h
			gcc $(CFLAGS) -c main.c

ui.o:		ui.c ui.h global.h
			gcc $(CFLAGS) -c ui.c

bt.o:		bt.h bt.c
			gcc $(CFLAGS) -c bt.c

bst.o:		bt.h bst.h global.h bst.c
			gcc $(CFLAGS) -c bst.c

avl.o:		bt.h bst.h avl.h global.h avl.c
			gcc $(CFLAGS) -c avl.c

clean:
			rm -f *.o
			rm -f tree
