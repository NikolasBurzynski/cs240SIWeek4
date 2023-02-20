all: main

main: main.o OperationCounter.o My_arr.o
	g++ main.o OperationCounter.o My_arr.o -o main

main.o: main.cpp OperationCounter.h My_arr.h
	g++ -c main.cpp

My_arr.o: My_arr.cpp My_arr.h
	g++ -c My_arr.cpp

OperationCounter.o: OperationCounter.cpp OperationCounter.h
	g++ -c OperationCounter.cpp

clean:  #delete .os and the main executable -f ignores files that aren't found
	rm -f *.o main