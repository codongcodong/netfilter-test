all: netfilter-test

netfilter-test: main.o simpleNetfilter.o 
	g++ -o netfilter-test main.o simpleNetfilter.o -lnetfilter_queue

main.o: main.cpp 
	g++ -Wall -c -o main.o main.cpp 

simpleNetfilter.o: simpleNetfilter.cpp simpleNetfilter.h
	g++ -Wall -c -o simpleNetfilter.o simpleNetfilter.cpp

clean:
	rm -f netfilter-test *.o
