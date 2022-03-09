mowin.o: mowin.cpp mowin.hpp   
	 	 	 g++ -c $^
 
 
thehob.o: thehob.cpp thehob.hpp   
	 	 	 g++ -c $^
 
 
seememow.o: seememow.cpp mowin.o thehob.o
	 	 	 g++ -c $^
	 	 	 g++ -o MoarComplicated $^

tthti.o: tthti.cpp mowin.o thehob.o
	 	 	 g++ -c $^
	 	 	 g++ -o MoarComplicated $^

all: mowin.o seememow.o thehob.o tthti.o 

clean: 
	 rm -f *.o
	 rm -f *.gch
	 rm -f all
