 
toss_a_coin.o: toss_a_coin.cpp 
	 	 	 g++ -c toss_a_coin $^
 
valley_of_plenty.o: valley_of_plenty.cpp 
	 	 	 g++ -c valley_of_plenty $^
 
wolf.o: wolf.cpp valley_of_plenty.hpp wolf.hpp valley_of_plenty.hpp wolf.hpp toss_a_coin.hpp valley_of_plenty.hpp wolf.hpp 
	 	 	 g++ -c wolf $^
 
dandelion.o: dandelion.cpp valley_of_plenty.hpp
	 	 	 g++ -o dandelion $^

all: toss_a_coin.o valley_of_plenty.o wolf.o dandelion.o 

clean: 
	 rm -f *.o
	 rm -f *.gch
	 rm -f all
