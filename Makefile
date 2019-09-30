default:
	g++ main.cpp game.cpp  well.cpp piece.cpp -o tetris -g -lncurses
run: default
	./tetris
clean:
	rm tetris
