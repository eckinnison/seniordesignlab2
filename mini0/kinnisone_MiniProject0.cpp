/*
Name: Emma Claire Kinnison
Date:2/15/22
Assignment: miniproject 0
Comments: The objective of this code is to hack time(whatever that means)

*/

#include "kinnisone_MiniProject0.hpp"
#include <iostream>
#include <unistd.h>
/*
This sets up all the variables so they can be modified in this file
*/
hacker::time_hack::time_hack(std::string objectToHack){
     this->time_to_hack;
     this->objectToHack;
}

/*
This sets the value for timetohack
*/
void hacker::time_hack::setTimeToHack(int sec){
    this->time_to_hack=sec;
}
/*
This sets the object name
*/
void hacker::time_hack::setObjectToHack(std::string objectname){
    this->objectToHack=objectname;
}

/*
This returns the amount of time to hack
*/
int hacker::time_hack::getTimeToHack(){

    return this->time_to_hack;
}
/*
This returns the current name of the object that wants to be hacked
*/
std::string hacker::time_hack::getObjectToHack(){
    return this->objectToHack;
}
/*
This does the hacking
*/
void hacker::time_hack::hackTime(){
    sleep(this->time_to_hack);
    printf("Time was hacked\n");
}

int main(int argc, char** argv){        
    std::string myobj;                              //UI stuff
    printf("What object do you want to hack?\n");
    std::cin>>myobj;
    printf("How many seconds do you want to hack?\n");
    int seconds=0;
    std::cin>>seconds;      

    hacker::time_hack trying(myobj);        //object
    trying.setTimeToHack(seconds);          //use the setters
    printf("This is the user input: ");     //get it back and print
    trying.setObjectToHack(myobj);
    std::string result=trying.getObjectToHack();    //get back the obj name
    std::cout<<result;
    printf("\n");                   //tell us the hacking started
    printf("hacking in progress\n");
    trying.hackTime();              //hack

    printf("completed\n");                //tell you it was done  

return 0;
}
