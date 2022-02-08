#include "kinnisone_stats.hpp"
#include <math.h>

/*
This sets up all the variables so they can be modified in this file
*/
tryme::hell::hell(){
    this->max=0;
    this->min=0;
    this->mean=0;
    this->std=0;
    this->buckets;
    this->bucketvals;
}

/*
This returns the current value for the variable max
*/
float tryme::hell::get_max(){
    return this->max;
}
/*
This returns the current value for the variable min
*/
float tryme::hell::get_min(){
    return this->min;
}
/*
This returns the current value for the variable mean
*/
float tryme::hell::get_mean(){
    return this->mean;
}

/*
This returns the current value for the variable std
*/
float tryme::hell::get_std(){
    return this->std;
}

/*
This returns the current vector for the variable buckets
*/
vector<float> tryme::hell::get_histogram_buckets(){
    return this->buckets;
}
/*
This returns the current vector for the variable bucketvals
*/
vector<float> tryme::hell::get_histogram_bucketsvals(){
    return this->bucketvals;
}

/*
This calculates and sets the current value for the max
*/
void tryme::hell::set_max(vector<float> data){
    int i=0;
    float temp=0;

    while((data[i])){
        if(data[i]>temp){               //figure out the max value
            temp=data[i];
        }
        else{
        }
        i++;
    }
    this->max=temp;                     //set the max value
}

/*
This calculates and sets the current value for the min
*/
void tryme::hell::set_min(vector<float> data){
    int i=0;
    float temp=0;

    while((data[i])){           //figure out what the min value is
        if(data[i]<temp){
            temp=data[i];
        }
        else{
        }
        i++;
    }
    this->min=temp;             //set the min value
}

/*
This calculates and sets the current value for the mean
*/
void tryme::hell::set_mean(vector<float> data){

    int index= data.size();     
    int i=0;
    float sum=0;
    while(i<index){             //figure out the mean value
        sum=sum+data[i];
        i++;
    }
    float answer=sum/index;
    this->mean=answer;          //set the mean value

}


/*
This calculates and sets the current value for the vectors buckets and bucketsvals
>buckets contains the boundries for the buckets of data
>bucketsvals contains the number of data points in each bucket
*/
void tryme::hell::set_histogram(vector<float> data) {

    float maximum = 0;                 //initialze variables
    float minimum = 10000;
    int j = 0;

    float width = 0.4*(this->std); //calc the size of the buckets
    float upperbound = this->mean+( 3*(this->std)); //calc the limits of the histogram
    float lowerbound= this->mean-(3*(this->std));
    float indexer=upperbound-width;                 //make something to index between the two
    int i=1;

        this->buckets.insert(buckets.begin(), upperbound);  //start the vector

    while(indexer>lowerbound){      //cycle through making all the bucket boundries
        vector<float>::iterator testing= this->buckets.insert(buckets.begin(),1, indexer);
        indexer=indexer-width;
        i++;
        

    }
    
    int arr[buckets.size()];    //make an array to count data points in each bucket
    for(int j=0; j<this->buckets.size(); j++){      //populate with 0s
        arr[j]=0;
    }
    for(int i=0; i<data.size();i++){                    //nested loop to go through each data point and each bucket
        for(int j=0; j<this->buckets.size(); j++){
            if(data[i]>=this->buckets[j]){          
                if(data[i]<this->buckets[j+1]){     
                    arr[j]++;                           //if the data point is between the bucket bounds add one to that bucket from the array
                }
            }
        }
    }

    for(int i=0;i<buckets.size();i++){
        vector<float>::iterator testing2= this->bucketvals.insert(bucketvals.begin(),1, arr[i]);    //load the bucketvals with the array values
    }     
}

/*
This calculates and sets the current value for the std
*/
void tryme::hell::set_std(vector<float> data, float mean) {

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
