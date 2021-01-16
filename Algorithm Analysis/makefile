prog: main.o Sort.o
	g++  main.o Sort.o -o prog
	
main.o: main.cpp 
	g++ -c main.cpp

Sort.o: Sort.cpp Sort.h
	g++ -c Sort.cpp

clean:
	rm main.o Sort.o prog
