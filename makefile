dkwc: main.o
	@echo "Building dkwc tool"
	@g++ main.o -o dkwc
	
main.o: main.cpp
	@g++ -c main.cpp
	@echo "Installing dkwc..."
	@sudo cp dkwc /usr/local/bin/dkwc

clean:
	@rm -f *.o dkwc