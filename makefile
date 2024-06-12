dkwc: main.o
	@echo "Building dkwc tool"
	@g++ main.o -o dkwc
	
main.o: main.cpp
	@g++ -c main.cpp
	
clean:
	@rm -f *.o dkwc