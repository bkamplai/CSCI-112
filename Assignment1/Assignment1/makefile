CC = g++
CFLAGS = -g -Wall

default: assignment1

assignment1: student.o StudList.o subject.o SubjList.o main.o
		$(CC) $(CFLAGS) -o assignment1 student.o StudList.o subject.o SubjList.o main.o

student.o: student.cpp student.h
		$(CC) $(CFLAGS) -c student.cpp

StudList.o: StudList.cpp StudList.h
		$(CC) $(CFLAGS) -c StudList.cpp

subject.o: subject.cpp subject.h
		$(CC) $(CFLAGS) -c subject.cpp

SubjList.o: SubjList.cpp SubjList.h
		$(CC) $(CFLAGS) -c SubjList.cpp

clean:
		$(RM) assignment1 *.o *~
