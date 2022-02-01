/*Name: Emma Claire Kinnison
Assignment: Lab 1
Date 2/1/22
Comments: This is the c file to sum the random numbers and output the resutle
Resources:https://thispointer.com/c-how-to-read-a-file-line-by-line-into-a-vector/
*/

#include <iostream>
#include <fstream>
#include <string>
#include "kinnisone_stats.hpp"
#include <vector> // #include directive


//using namespace ECnamespace;

ECnamespace::ECclass::ECclass(){
    max=0;
    min=0;
    mean=0;
}

//this function helps to calculate the maximum value
void ECnamespace::ECclass::maxcalc(std::vector<float> data){
        int index= data.size();
        int i=0;
        while (i<index){
            if(data[i]>=this->max){
                this->max=data[i];
            }
            i++;
        }
    //    return max;
}

//this function helps to calculate the minimum value
void ECnamespace::ECclass::mincalc(std::vector<float> data){
        int index= data.size();
        int i=0;
        while (i<index){
            if(data[i]<=this->min){
                this->min=data[i];
            }
            i++;
        }
      //  return min;
}

//this function helps to calculate the mean value
void ECnamespace::ECclass::meancalc(std::vector<float> data){
        int index= data.size();
        int i=0;
        float sum=0;
        while (i<index){
            sum=sum+data[i];
            i++;
        }
        this->mean= sum/index;
//        return mean;
}


// int main(){
//     ECclass testsrun;

//     std::vector<float> tester { 1, 4, 3, 5, 2};

//     float maxval= testsrun.maxcalc(tester); 
   
//     printf("max %f\n", maxval);

//     float minval= testsrun.mincalc(tester); 
   
//     printf("min %f\n", minval);

//     float meanval= testsrun.meancalc(tester); 
   
//     printf("mean %f\n", meanval);
//     return 0;
// }