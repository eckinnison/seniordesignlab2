#include "kinnisone_stats.hpp"
#include "kinnisone_stats.cpp"
#include "kinnisone_corr.hpp"
#include <math.h>


imgood::heaven::heaven(){
    this->cor=0;
}

float imgood::heaven::get_cor(){
    return this->cor;
}

void imgood::heaven::set_cor(vector<float> data, vector<float> data2){
    int N=data.size();
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
    
    for(int i=0; i<N;i++){
        sum= sum+data[i]*data2[i];
    }
    tryme::hell whatamI;
    whatamI.set_mean(data);
    meandata=whatamI.get_mean();
    whatamI.set_mean(data2);
    meandata2=whatamI.get_mean();
    num= sum-(N*meandata*meandata2);
    
    for(int i=0; i<N;i++){
        sumdatasqrd= sumdatasqrd+data[i]*data[i];
    }
    whatamI.set_mean(data);
    meandatasqrd=whatamI.get_mean();
    meandatasqrd=meandatasqrd*meandatasqrd;
     for(int i=0; i<N;i++){
        sumdata2sqrd= sumdata2sqrd+data2[i]*data2[i];
    }
    whatamI.set_mean(data2);
    meandata2sqrd=whatamI.get_mean();
    meandata2sqrd=meandata2sqrd*meandata2sqrd;

    float part1=0;
    float part2=0;
    
    part1= sumdatasqrd-(N*meandatasqrd);
    part2= sumdata2sqrd-(N*meandata2sqrd);
    denom=part1*part2;

    denom=sqrt(denom);

    this->cor=num/denom;
}


