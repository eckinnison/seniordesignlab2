#include "kinnisone_vector_ops.hpp"
#include <math.h>
#include<algorithm>
#include <vector>
/*
This sets up all the variables so they can be modified in this file
*/
banana::pie::pie(){
    this->sum=0;
    this->sub; 
    this->div;
}

/*
This calculates and sets the current value for the sum
*/
void banana::pie::set_arr_sum(vector<float> data){
    for(int i=0; i<data.size(); i++){
        this->sum= data[i]+this->sum;
    }
}

/*
This calculates and sets the current value for the sub
*/
void banana::pie::set_arr_sub(vector<float> data, vector<float> data2){
    float arr[data.size()];    //make an array to count data points in each bucket
    float starter= data[0]-data2[0];

    this->sub.insert(sub.begin(), starter);  //start the vector

    for(int i=1; i<data.size(); i++){
        arr[i]= data[i]-data2[i];
        vector<float>::iterator testing2= this->sub.insert(sub.end(), 1, arr[i]);    //load the bucketvals with the array values
        
    }

}

/*
This calculates and sets the current value for the div
*/
void banana::pie::set_div_arr(vector<float> data, float val){
    float arr[data.size()];    //make an array to count data points in each bucket

    float starter= data[0]/val;

    this->div.insert(div.begin(), starter);  //start the vector
    for(int i=1; i<data.size(); i++){
        arr[i]= data[i]/val;
        vector<float>::iterator testing2= this->div.insert(div.end(), 1, arr[i]);    //load the bucketvals with the array values
    }
}

/*
This returns the current value for the variable sum
*/
float banana::pie::get_arr_sum(){
    return this->sum;
}

/*
This returns the current value for the variable sub
*/
vector<float> banana::pie::get_arr_sub(){
    return this->sub;
}

/*
This returns the current value for the variable div
*/
vector<float> banana::pie::get_div_arr(){
    return this->div;
}

