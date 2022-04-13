#Name: Emma Claire Kinnison
#Date:4/11/22
#Assignment: miniproject 1
#Comments: this is my attempt at a make file

CC = g++ -c
SHELL= /bin/bash
CFLAGS = -fPIC -g
LDFLAGS = -lm -lstats  
# library directory 
LIBDIR = /home/kinnise/Lab0_C_code/Lab1
# where the header file is 
INCDIR = /home/kinnise/Lab0_C_code/Lab1

library_i_think.so:
	cd /home/kinnise/Lab0_C_code/Lab1 && make library_i_think.so

airspeed: /home/kinnise/Lab0_C_code/miniproject1/kinnisone_miniproject1.cpp 
	$(CC) $(CFLAGS) -I$(INCDIR) -o $@ $< -Wl,-rpath=$(LIBDIR) -L$(LIBDIR) $(LDFLAGS)

#	$(CC) $(CFLAGS) $(INCDIR) -o $@ $^ -Wl, -rpath=$(LIBDIR) $(LDFLAGS)

clean:
		rm -f *.o 
		rm -f *.gch
		rm -f airspeed 
			

