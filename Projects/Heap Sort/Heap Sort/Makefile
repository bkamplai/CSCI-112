CC = g++
CFLAGS = -g -Wall

default: heapSort

heapSort: HeapSort.o main.o
	$(CC) $(CFLAGS) -o heapSort HeapSort.o main.o

HeapSort.o: HeapSort.cpp HeapSort.h
	$(CC) $(CFLAGS) -c HeapSort.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) heapSort *.o *~
