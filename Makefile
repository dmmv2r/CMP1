CC = g++

output: main.o scanner.o testScanner.o token.o
	$(CC) main.o scanner.o testScanner.o token.o -o scanner

main.o: main.cpp
	$(CC) -c main.cpp

scanner.o: scanner.cpp scanner.h
	$(CC) -c scanner.cpp

testScanner.o: testScanner.cpp testScanner.h
	$(CC) -c testScanner.cpp

token.o: token.cpp token.h
	$(CC) -c token.cpp

clean:
	rm *.o scanner
