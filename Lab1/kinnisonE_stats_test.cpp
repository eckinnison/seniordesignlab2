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


int main(){
    ECclass testsrun;

    std::vector<float> tester { 1, 4, 3, 5, 2};

    float maxval= testsrun.maxcalc(tester); 
   
    printf("max %f\n", maxval);

    float minval= testsrun.mincalc(tester); 
   
    printf("min %f\n", minval);

    float meanval= testsrun.meancalc(tester); 
   
    printf("mean %f\n", meanval);
    return 0;
}