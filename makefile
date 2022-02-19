#Name: Emma Claire Kinnison
#Date:2/19/21
#Assignment: Lab 2
#Comments: this is my attempt at a make file


CC= g++

vector_ops.o: lab2/kinnisone_vector_ops.hpp lab2/kinnisone_vector_ops.cpp
			  #g++ -c vector_ops vector_ops.vector_ops
			  $(CC) -c $^
lab1_stats.o: lab1/kinnisone_stats.hpp lab1/kinnisone_stats.cpp lab1/kinnisone_stats_test.cpp 
			 # g++ -c lab1_stats lab1_stats.o 
			 $(CC) -c $^

all: vector_ops.o lab1_stats.o 

clean:
		rm -f *.o 
		rm -f *.gch
		rm -f all 
			