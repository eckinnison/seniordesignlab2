#Name: Emma Claire Kinnison
#Date:4/11/22
#Assignment: miniproject 1
#Comments: this is my attempt at a make file
CC = g++ -c
SHELL= /bin/bash
CFLAGS = -fPIC -g

kinnisone_stats.o: /home/kinnise/Lab0_C_code/Lab1/kinnisone_stats_test.cpp /home/kinnise/Lab0_C_code/Lab1/kinnisone_stats.cpp /home/kinnise/Lab0_C_code/Lab1/kinnisone_stats.hpp 
		$(CC) $(CFLAGS) $^ -lm

library_i_think.so: kinnisone_stats.o
		$(CC) -shared $^ -o $@

all:kinnisone_stats.o library_i_think.so

clean:
		rm -f *.o 
		rm -f *.gch
			

