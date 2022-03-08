wolf.o: wolf.cpp wolf.hpp
	g++ -c wolf $^

valley_of_plenty.o: valley_of_plenty.cpp valley_of_plenty.hpp
	g++ -c valley_of_plenty $^

toss_a_coin.o: toss_a_coin.cpp toss_a_coin.hpp valley_of_plenty.hpp
	g++ -c toss_a_coin $^
 

dandelion.o: dandelion.cpp valley_of_plenty.cpp valley_of_plenty.hpp toss_a_coin.cpp toss_a_coin.hpp wolf.cpp wolf.hpp
	g++ -o dandelion $^
 

all:  wolf.o valley_of_plenty.o toss_a_coin.o dandelion.o  

clean: 
	 rm -f *.o
	 rm -f *.gch
	 rm -f all
