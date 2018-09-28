out_dir=./bin
sources := $(shell find . -name '*.cpp')

build: clean structure sources dungeon

structure:
	mkdir $(out_dir)

sources: $(sources)
	$(foreach class,$(sources),$(call compile,$(class),$(notdir $(class:.cpp=.o))))
objs=$(shell find $(out_dir) -name '*.o')

dungeon: $(objs)
	g++ -g -o $(out_dir)/dungeon $(objs)

clean:
	rm -rf $(out_dir)

define compile
	g++ -c -g -std=c++17 $1 -o $(out_dir)/$2

endef
define print
	@echo $1

endef