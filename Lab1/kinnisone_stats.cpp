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

vector<float> tryme::hell::get_histogram_buckets(){
    return this->buckets;
}
vector<float> tryme::hell::get_histogram_bucketsvals(){
    return this->bucketvals;
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
    int i=0;
    float temp=0;

    while((data[i])){
        if(data[i]<temp){
            temp=data[i];
        }
        else{
        }
        i++;
    }
    this->min=temp;
}

void tryme::hell::set_mean(vector<float> data){

    int index= data.size();
    int i=0;
    float sum=0;
    while(i<index){
        sum=sum+data[i];
        i++;
    }
    float answer=sum/index;
    this->mean=answer;

}


//this is a work in progrss histogram function it is not done yet at all
void tryme::hell::set_histogram(vector<float> data) {

    float maximum = 0;                 //initialze variables
    float minimum = 10000;
    int j = 0;

    float width = 0.4*(this->std); //calc the size of the buckets
    float upperbound = this->mean+( 3*(this->std)); //calc the size of the buckets
    float lowerbound= this->mean-(3*(this->std));
    float indexer=upperbound-width;
    int i=1;

        this->buckets.insert(buckets.begin(), upperbound);

    while(indexer>lowerbound){
        vector<float>::iterator testing= this->buckets.insert(buckets.begin(),1, indexer);
        indexer=indexer-width;
        i++;
        

    }
    
    int arr[buckets.size()];
    for(int j=0; j<this->buckets.size(); j++){
        arr[j]=0;
    }
    for(int i=0; i<data.size();i++){
        for(int j=0; j<this->buckets.size(); j++){
            if(data[i]>=this->buckets[j]){
                if(data[i]<this->buckets[j+1]){
                    arr[j]++;
                }
            }
        }
    }

    for(int i=0;i<buckets.size();i++){
        vector<float>::iterator testing2= this->bucketvals.insert(bucketvals.begin(),1, arr[i]);
    }

     
}

/*
This function calculates the standard deviation of the selected columnS
*/
void tryme::hell::set_std(vector<float> data, float mean) {
    //tryme::hell::hell whatamI;

    float var = 0;                                 //initialize variables
    float sum = 0;
    int numrows= data.size();
    int i = 0;

    for (i = 0; i < numrows; i++) {                 //incremnt through all the rows in the column
        sum = pow((data[i] - mean), 2) + sum;  //make the summation of the (data point-the mean)^2
    }
    var = sum / (numrows-1 );                       //the varience is equal to the summation divided by the number of rows-1


    float temp = sqrt(var);                         //the standard deviation is the square root of the varience

    this->std=temp;
}

// int main(int argc, char** argv){
//     return 0;
// }