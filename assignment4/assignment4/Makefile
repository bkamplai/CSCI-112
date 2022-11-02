CC = g++
CFLAGS = -g -Wall

default: assignment4

assignment4: infixToPostfixImp.o HeapSort.o QuickSort.o main.o
	$(CC) $(CFLAGS) -o assignment4 infixToPostfixImp.o HeapSort.o QuickSort.o main.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

infixToPostfixImp.o: infixToPostfixImp.cpp infixToPostfix.h
	$(CC) $(CFLAGS) -c infixToPostfixImp.cpp

HeapSort.o: HeapSort.cpp HeapSort.h
	$(CC) $(CFLAGS) -c HeapSort.cpp

QuickSort.o: QuickSort.cpp QuickSort.h
	$(CC) $(CFLAGS) -c QuickSort.cpp

clean:
	$(RM) task1 *.o *~
