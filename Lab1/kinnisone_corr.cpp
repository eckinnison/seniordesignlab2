#include "kinnisone_stats.hpp"
#include "kinnisone_corr.hpp"
#include <math.h>

/*
This sets up all the variables so they can be modified in this file
*/
imgood::heaven::heaven(){
    this->cor=0;
}
/*
This returns the current value for the variable cor
*/
float imgood::heaven::get_cor(){
    return this->cor;
}

/*
This calculates and sets the current value for the cor
*/
void imgood::heaven::set_cor(vector<float> data, vector<float> data2){
    int N=data.size();              //initialize everything
    float num=0;
    float denom=0;
    float sum=0; 
    float meandatadata2=0;
    float meandata=0;
    float meandata2=0;
    float sumdatasqrd=0;
    float meandatasqrd=0;
    float sumdata2sqrd=0;
    float meandata2sqrd=0;
    
    for(int i=0; i<N;i++){          //get the sum
        sum= sum+data[i]*data2[i];
    }
    tryme::hell whatamI;            //make the object to use the functions
    whatamI.set_mean(data);         //set and get the mean of the data, and data2
    meandata=whatamI.get_mean();
    whatamI.set_mean(data2);
    meandata2=whatamI.get_mean();
    num= sum-(N*meandata*meandata2);    //make the numerator
    
    for(int i=0; i<N;i++){              //sum all the data^2 values
        sumdatasqrd= sumdatasqrd+data[i]*data[i];
    }
    whatamI.set_mean(data);     //get the mean of the data 
    meandatasqrd=whatamI.get_mean();
    meandatasqrd=meandatasqrd*meandatasqrd;     //make the mean data squared
     for(int i=0; i<N;i++){
        sumdata2sqrd= sumdata2sqrd+data2[i]*data2[i];   //sum the data2^2
    }
    whatamI.set_mean(data2);        //get the mean of data2
    meandata2sqrd=whatamI.get_mean();
    meandata2sqrd=meandata2sqrd*meandata2sqrd;  //get the mean data2 squared

    float part1=0;
    float part2=0;
    
    part1= sumdatasqrd-(N*meandatasqrd);    //calc the first half of the equation
    part2= sumdata2sqrd-(N*meandata2sqrd);   //calc the second part of the equation
    denom=part1*part2;                       //make the denominator

    denom=sqrt(denom);                      //make teh denominator

    this->cor=num/denom;                    //calcualte the ratio
}


