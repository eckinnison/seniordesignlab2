#Name: Emma Claire Kinnison
#Date:4/11/22
#Assignment: miniproject 1
#Comments: this is my attempt at a make file

CC = g++
SHELL= /bin/bash
CFLAGS = -fPIC -g
LDFLAGS = -L"/home/kinnise/Lab0_C_code/Lab1"
# library directory 
LIBDIR = "/home/kinnise/Lab0_C_code/Lab1"
# where the header file is 
INCDIR = -I"/home/kinnise/Lab0_C_code/Lab1"

library_i_think.so:
	cd /home/kinnise/Lab0_C_code/Lab1 && make library_i_think.so

airspeed: kinnisone_miniproject1.cpp 
	make library_i_think.so
	$(CC) $(CFLAGS) $(INCDIR) -o $@ $^ -Wl, -rpath=$(LIBDIR) $(LDFLAGS)

clean:
		rm -f *.o 
		rm -f *.gch
		rm -f airspeed 
			

