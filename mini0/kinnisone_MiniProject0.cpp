/*
Name: Emma Claire Kinnison
Date:2/15/22
Assignment: miniproject 0
Comments: The objective of this code is to hack time(whatever that means)

*/

#include "kinnisone_MiniProject0.hpp"
#include <iostream>
#include <unistd.h>

hacker::time_hack::time_hack(std::string objectToHack){
     this->time_to_hack;
     this->objectToHack;
}

void hacker::time_hack::setTimeToHack(int sec){
    this->time_to_hack=sec;
}

void hacker::time_hack::setObjectToHack(std::string objectname){
    this->objectToHack=objectname;
}


int hacker::time_hack::getTimeToHack(){

    return this->time_to_hack;
}

std::string hacker::time_hack::getObjectToHack(){
    return this->objectToHack;
}

int hacker::time_hack::hackTime(){
    sleep(this->time_to_hack);
    printf("Time was hacked\n");
    return 0;
}

int main(int argc, char** argv){
    std::string myobj;
    printf("What object do you want to hack?\n");
    std::cin>>myobj;
    printf("How many seconds do you want to hack?\n");
    int seconds=0;
    std::cin>>seconds;

    hacker::time_hack trying(myobj);
    trying.setTimeToHack(seconds);
    printf("This is the user input: ");
    trying.setObjectToHack(myobj);
    std::string result=trying.getObjectToHack();
    std::cout<<result;
    printf("\n");
    printf("hacking in progress\n");
    trying.hackTime();

    printf("completed");

return 0;
}
