main:main.o ensei.o
	g++ main.o ensei.o -Wall -o main
main.o:main.cpp
	g++ -c main.cpp
ensei.o:ensei.cpp
	g++ -c ensei.cpp
clean:
	rm -f *.o *~ *# main
