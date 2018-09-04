dungeon:main.o
	g++ -o dungeon main.o

main.o:main.cpp
	g++ -c main.cpp

clean:
	rm dungeon main.o