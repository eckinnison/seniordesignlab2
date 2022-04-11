#Name: Emma Claire Kinnison
#Date:4/11/22
#Assignment: miniproject 1
#Comments: this is my attempt at a make file
CC = g++
SHELL= /bin/bash
CFLAGS = -fPIC -g

kinnisone_stats.o: kinnisone_stats_test.cpp kinnisone_stats.hpp kinnisone_stats.cpp
		$(CC) $(CFLAGS) $^ -lm

library_i_think.so: kinnisone_stats.o
		$(CC) -shared $^ -o $@

all: library_i_think.so

clean:
		rm -f *.o 
		rm -f *.gch
			

