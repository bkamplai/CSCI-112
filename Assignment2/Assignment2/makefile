CC = g++
CFLAGS = -g -Wall

default: assignment2

assignment2: Elevator.o Assignment2.o
		$(CC) $(CFLAGS) -o assignment2 Elevator.o Assignment2.o

Elevator.o: Elevator.cpp Elevator.h
		$(CC) $(CFLAGS) -c Elevator.cpp

clean:
		$(RM) assignment2 *.o *~
