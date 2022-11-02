CC = g++
CFLAGS = -g -Wall

default: week5

week5: bankAccount.o savingsAccount.o checkingAccount.o main.o
		$(CC) $(CFLAGS) -o week5 bankAccount.o savingsAccount.o checkingAccount.o main.o
bankAccount.o: bankAccount.cpp bankAccount.h
		$(CC) $(CFLAGS) -c bankAccount.cpp
savingsAccount.o: savingsAccount.cpp savingsAccount.h
		$(CC) $(CFLAGS) -c savingsAccount.cpp
checkingAccount.o: checkingAccount.cpp checkingAccount.h
		$(CC) $(CFLAGS) -c checkingAccount.cpp
clean:
		$(RM) week5 *.o *~
