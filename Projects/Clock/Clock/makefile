#This is makefile for the clock project will build and can clean the build repository
#Typing 'make' or 'make clock' will generate the executable

#define makefile variables and compiler flags
#to use a makefile variable later in the makefile $()
#
# -g adds debugging info to the executable
# -Wall turns on most but not all warnings
#
# for C++ define CC = g++ (or Clang++)

CC = g++
CFLAGS = -g -Wall

#typing 'make' will invoke the first target entry in the file
#(int this case the default entry)
#you can name this target any name, but "default" or "all"
#are the common practice
#
default: clock

#to create the executable the clock needs the object files
#namely clockType.o, main.o: so tell make how to build these
clock: ClockType.o main.o
		$(CC) $(CFLAGS) -o clock ClockType.o main.o

#To create the object file ClockType.o we need the source files
#ClockType.cpp, clockType.h
#
ClockType.o: ClockType.cpp clockType.h
		$(CC) $(CFLAGS) -c ClockType.cpp

#To start over from scratch type 'make clean'
#remove all object files and executbales and backups
# backups are hidden and look like *~
clean:
		$(RM) clock *.o *~
