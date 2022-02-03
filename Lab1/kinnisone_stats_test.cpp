/*Name: Emma Claire Kinnison
Assignment: Lab 1
Date 2/1/22
Comments: This is the c file to sum the random numbers and output the resutle
*/

#include <iostream>
#include <fstream>
#include <string>
//#include "kinnisone_stats.cpp"
#include "kinnisone_stats.hpp"
using namespace ECnamespace;


int main(){

    ECclass myObj;
    std::vector<float> tester { 1.0, 4.0, 3.2, 5.4, 2.8};

    float maxval= myObj.maxcalc(tester); 
   
    printf("max %f\n", maxval);

    float minval= ECclass::mincalc(tester); 
   
    printf("min %f\n", minval);

    float meanval= ECclass::meancalc(tester); 
   
    printf("mean %f\n", meanval);
    return 0;
}