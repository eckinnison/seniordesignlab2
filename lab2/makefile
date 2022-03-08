#Name: Emma Claire Kinnison
#Date:2/19/21
#Assignment: Lab 2
#Comments: this is my attempt at a make file

vector_ops.o: kinnisone_vector_ops.hpp kinnisone_vector_ops.cpp
				g++ -c vector_ops $^

lab1_stats.o: kinnisone_stats.hpp kinnisone_stats.cpp kinnisone_stats_test.cpp 
			  g++ -c cppstats $^

preprocess.o: kinnisone_pre_process_test.cpp kinnisone_pre_processing.cpp kinnisone_pre_processing.hpp kinnisone_stats.hpp kinnisone_stats.cpp kinnisone_vector_ops.hpp kinnisone_vector_ops.cpp
			  g++ -o preprocess $^

cluster.o: kinnisone_k_means.hpp kinnisone_k_means.cpp kinnisone_stats.hpp kinnisone_stats.cpp kinnisone_pre_processing.hpp kinnisone_pre_processing.cpp kinnisone_vector_ops.hpp kinnisone_vector_ops.cpp
			  g++ -o cluster $^

all: vector_ops.o lab1_stats.o preprocess.o cluster.o

clean:
		rm -f *.o 
		rm -f *.gch
		rm -f all 
			

