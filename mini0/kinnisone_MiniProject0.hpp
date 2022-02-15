/*
Name: Emma Claire Kinnison
Date:2/15/22
Assignment: miniproject 0
Comments: The objective of this code is to hack time(whatever that means)

*/


#ifndef PRIMER2
#define PRIMER2


#include <iostream>
#include <unistd.h>

    namespace hacker{       //this is my namespace, I was less frustrated this time
        class time_hack{       //this is my class, named to balence out the last class
            public:             //just make sure all the functions work
                time_hack(std::string objectToHack);
                void setTimeToHack(int seconds);
                void setObjectToHack(std::string objectname);
                int getTimeToHack();
                std::string getObjectToHack();
                void hackTime();
            private:
                int time_to_hack;
                std::string objectToHack;
        };
    }
    

#endif
