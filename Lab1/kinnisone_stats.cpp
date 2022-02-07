#include "kinnisone_stats.hpp"
#include <math.h>

tryme::hell::hell(){
    this->max=0;
    this->min=0;
    this->mean=0;
    this->std=0;
    this->buckets;
    this->bucketvals;
}


float tryme::hell::get_max(){
    return this->max;
}

float tryme::hell::get_min(){
    return this->min;
}

float tryme::hell::get_mean(){
    return this->mean;
}
float tryme::hell::get_std(){
    return this->std;
}

void tryme::hell::set_max(vector<float> data){
    int i=0;
    float temp=0;

    while((data[i])){
        if(data[i]>temp){
            temp=data[i];
        }
        else{

        }
        i++;
    }
    this->max=temp;
}

void tryme::hell::set_min(vector<float> data){
    int index=data.size();
    int i=0;
    while(i<index){
        if(data[i]<=this->min){
            this->min=data[i];
        }
        i++;
    }
}

void tryme::hell::set_mean(vector<float> data){

    int index= data.size();
    int i=0;
    float sum=0;
    while(i<index){
        sum=sum+data[i];
        i++;
    }
    this->mean=sum/index;

}


//this is a work in progrss histogram function it is not done yet at all
void tryme::hell::set_histogram(vector<float> data) {
  
    double maximum = 0;                 //initialze variables
    double minimum = 10000;
    int j = 0;

   // int numbuckets = 50;
    vector<int> buckets;
    vector<int> bucketvals;


    double width = 0.4*(this->std); //calc the size of the buckets
    double upperbound = this->mean+( 3*(this->std)); //calc the size of the buckets
    double lowerbound= this->mean-(3*(this->std));
    int indexer=lowerbound+width;
    int i=1;
    buckets[0]=lowerbound;
    while(indexer<upperbound){
        this->buckets[i]=indexer;
        indexer=indexer+width;
        i++;
    }
    for(int i=0; i<data.size();i++){
        for(int j=0; j<this->buckets.size(); j++){
            if(data[i]>=this->buckets[j]){
                if(data[i]<this->buckets[j+1]){
                    this->bucketvals[j]++;
                }
            }
        }
    }
}

/*
This function calculates the standard deviation of the selected columnS
*/
double set_std(vector<float> data, float mean) {
    //tryme::hell::hell whatamI;

    double var = 0;                                 //initialize variables
    double sum = 0;
    int numrows= data.size();
    int i = 0;

    for (i = 0; i < numrows; i++) {                 //incremnt through all the rows in the column
        sum = pow((data[i] - mean), 2) + sum;  //make the summation of the (data point-the mean)^2
    }
    var = sum / (numrows-1 );                       //the varience is equal to the summation divided by the number of rows-1


    double std = sqrt(var);                         //the standard deviation is the square root of the varience

    return std;                                     //return the standard deviation

}

int main(){
    return 0;
}