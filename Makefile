CFLAGS = -g -lncurses
default:
	g++ main.cpp game.cpp  well.cpp piece.cpp -o tetris $(CFLAGS)
run: default
	./tetris
debug: default
	./tetris -t
clean:
	rm tetris
