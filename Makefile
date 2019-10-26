all: build ru

build:
	mkdir build && cd build && cmake -G "MinGW Makefiles" ../src/ && make

run:
	cd build && ./main

build_test:
	mkdir build && cd build && cmake -G "MinGW Makefiles" ../ut/ && make

run_test:
	cd build && ./test

clean:
	rmdir /S /Q build