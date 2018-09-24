out_dir=bin/
objects=bin/main.o bin/item.o bin/dummy.o
classes=main.cpp things/item.cpp dummys/dummy.cpp

build: clean structure sources dungeon

structure:
	mkdir $(out_dir)

dungeon: $(objects)
	g++ -g -o $(out_dir)/dungeon $(objects)

sources: $(classes)
	g++ -c -g -std=c++11 main.cpp -o $(out_dir)/main.o
	g++ -c -g -std=c++11 things/item.cpp -o $(out_dir)/item.o
	g++ -c -g -std=c++11 dummys/dummy.cpp -o $(out_dir)/dummy.o

clean:
	rm -rf $(out_dir)