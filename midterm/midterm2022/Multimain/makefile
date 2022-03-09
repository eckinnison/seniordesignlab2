brennanb_corr.o: brennanb_corr.cpp brennanb_corr.hpp brennanb_stats.hpp   
	 	 	 g++ -c $^
 
 
brennanb_stats.o: brennanb_stats.cpp brennanb_corr.o brennanb_stats.o
	 	 	 g++ -o brennanb_stats $^

all: brennanb_corr.o brennanb_stats.o 

clean: 
	 rm -f *.o
	 rm -f *.gch
	 rm -f all
