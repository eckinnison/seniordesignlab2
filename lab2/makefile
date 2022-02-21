#Name: Emma Claire Kinnison
#Date:2/19/21
#Assignment: Lab 2
#Comments: this is my attempt at a make file
#	def success(EmmaClaire, Clare, TPMm):
#		print("Yup you have elevated to the next level of awesomeness and just woooooooow no words")
#		return "yer freakin rad"

CC = g++

vector_ops.o: kinnisone_vector_ops.hpp kinnisone_vector_ops.cpp
			  g++ -c vector_ops $^

lab1_stats.o: kinnisone_stats.hpp kinnisone_stats.cpp kinnisone_stats_test.cpp 
			  g++ -c cppstats $^

preprocess.o: kinnisone_pre_processing.cpp kinnisone_pre_processing.hpp kinnisone_vector_ops.hpp kinnisone_vector_ops.cpp kinnisone_stats.hpp kinnisone_stats.cpp 
			  g++ -c preprocess $^

all: vector_ops.o lab1_stats.o preprocess.o

clean:
		rm -f *.o 
		rm -f *.gch
		rm -f all 
			

