 
brennanb_stats.o: brennanb_stats.cpp brennanb_stats.hpp   
	 	 	 g++ -c $^
 
brennanb_corr.o: brennanb_corr.cpp brennanb_stats.o
	 	 	 g++ -c $^
	 	 	 g++ -o Simple $^

all: brennanb_corr.o brennanb_stats.o 

clean: 
	 rm -f *.o
	 rm -f *.gch
	 rm -f all
