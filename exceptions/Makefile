SOURCE_S = except.cpp
CC = g++
RM = /bin/rm -rf

all: first go
first: 
	g++ -c $(SOURCE_S)
go: except.o
	g++ except.o -o e
clean:  
	$(RM) *.o e

