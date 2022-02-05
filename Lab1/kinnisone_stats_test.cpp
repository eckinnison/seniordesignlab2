/*Name: Emma Claire Kinnison
Assignment: Lab 1
Date 2/1/22
Comments: This is the c file to sum the random numbers and output the resutle
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "kinnisone_stats.hpp"
//#include "kinnisone_stats.cpp"
using namespace ECnamespace;


int main(){
    //ECnamespace::ECclass testsrun;
    //ECclass myObj;
    std::vector<float> tester { 1.0, 4.0, 3.2, 5.4, 2.8};
    //float tester[]={ 1.0, 4.0, 3.2, 5.4, 2.8};

   // testsrun.set_max(tester); 

    ECclass::ECclass set_max(tester);



    //float maxval= testsrun.get_max();
   // printf("max %f\n", maxval);

    // myObj.get_min(tester); 
    // float minval= myObj.get_min();
    // printf("min %f\n", minval);

    // myObj.get_mean(tester); 
    // float meanval= myObj.get_mean();
    // printf("mean %f\n", meanval);


    return 0;
}