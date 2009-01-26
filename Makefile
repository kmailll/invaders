
all: ka235890

ka235890:
	g++ -O3 -static -o ka235890 main.cpp board.cpp player.cpp move.cpp coord.cpp dir.cpp field.cpp

clean:
	rm -f *.o *.o core ka235890


