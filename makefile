out_dir=bin/
objects=main.o dummy.o

build: clean dungeon

dungeon: $(objects)
	g++ -o dungeon $(objects)
	mkdir $(out_dir)
	mv ./dungeon $(out_dir)
	mv *.o $(out_dir)

sources: main.cpp dummy.cpp
	g++ -c main.cpp dummy.cpp

clean:
	rm -rf $(out_dir)