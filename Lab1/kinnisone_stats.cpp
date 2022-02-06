#include "kinnisone_stats.hpp"


tryme::hell::hell(){
    this->max=0;
    this->min=0;
    this->mean=0;
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

void tryme::hell::set_max(vector<float> data){
    int i=0;
    float temp=0;

    while((data[i])!=NULL){
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
void set_histogram(vector<float> data) {
    double max = 0;                 //initialze variables
    double min = 10000;
    int i = 0;
    int j = 0;
    double upperbound = 0;
    double lowerbound = 0;
    int numbuckets = 50;

    for (i = 0; i < data.size(); i++) {       //increment throuhg all the data 
        if (data[i] > max) {        //find the maximum
            max = data[i];
        }
        if (data[i] < min) {        //find the minimum
            min = data[i];
        }

    }
    double difference = max - min;      //calc the difference
    double index = difference / numbuckets; //calc the size of the buckets


   

    for (j = 0; j < numbuckets; j++){        //increment through all the buckets
        lowerbound = (j* index) + min;      //calc the lower and upper bounds of the buckets
        upperbound = ((j+ 1) * index) + min;
       // fprintf(fp, "%f-%f", lowerbound, upperbound);       //print the bounds to the file

        for (i = 0; i < data.size(); i++) { //increment throuhg the data points

            if (data[i] >= lowerbound && data[i] < upperbound) {    //if the data falls in the bucket

                //fprintf(fp, "|");   //print a tally to the bin in the file

            }
        }
       // fprintf(fp, "\n");      //print a new line to the file

    }
    //fclose(fp);     //close the file
}

/*
This function calculates the standard deviation of the selected column

*/
double std_data(double** data, int col, int numrows) {

    double var = 0;                                 //initialize variables
    double sum = 0;
    double mean = mean_col(data, col, numrows);     //call the mean function
    int i = 0;

    for (i = 0; i < numrows; i++) {                 //incremnt through all the rows in the column
        sum = pow((data[i][col] - mean), 2) + sum;  //make the summation of the (data point-the mean)^2
    }
    var = sum / (numrows-1 );                       //the varience is equal to the summation divided by the number of rows-1


    double std = sqrt(var);                         //the standard deviation is the square root of the varience

    return std;                                     //return the standard deviation

}

int main(){
    return 0;
}