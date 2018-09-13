dungeon:main.o dummy.o
	g++ -o dungeon main.o dummy.o

main.o: main.cpp 
	g++ -c main.cpp

dummy.o: dummy.cpp
	g++ -c dummy.cpp

clean:
	rm dungeon main.o