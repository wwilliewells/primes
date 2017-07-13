all: prime_test
prime_test: prime_test.o prime_factor.o
	g++ -g -o prime_test prime_test.o prime_factor.o
prime_test.o: prime_test.cpp 
	g++ -g -c src/prime_test.cpp include/prime_factor.h
prime_factor.o: prime_factor.cpp 
	g++ -g -c src/prime_factor.cpp include/prime_factor.h
clean:
	rm -f prime_factor.o prime_test.o
wipe: clean
	rm -f prime_test.exe
