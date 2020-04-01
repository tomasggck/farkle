a.out: main.o die.o player.o
	g++ main.o die.o player.o

main.o: main.cc die.h player.h
	g++ -c main.cc

die.o: die.cc die.h
	g++ -c die.cc
player.o: player.cc player.h
	g++ -c player.cc
clean:
	rm -f *.o a.out core
