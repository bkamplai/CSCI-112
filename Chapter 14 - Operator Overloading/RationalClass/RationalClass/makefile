CC = g++
CFLAGS = -g -Wall

default: rationalWithOperators

rationalWithOperators: RationalWithOperators.o TestRationalWithOperators.o
		$(CC) $(CFLAGS) -o rationalWithOperators RationalWithOperators.o TestRationalWithOperators.o
RationalWithOperators.o: RationalWithOperators.cpp RationalWithOperators.h
		$(CC) $(CFLAGS) -c RationalWithOperators.cpp
rational: Rational.o TestRationalClass.o
		$(CC) $(CFLAGS) -o rational Rational.o TestRationalClass.o
Rational.o: Rational.cpp Rational.h
		$(CC) $(CFLAGS) -c Rational.cpp
clean:
		$(RM) rationalWithOperators *.o *~
		$(RM) rational *.o *~
