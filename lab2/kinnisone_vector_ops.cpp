#include "kinnisone_vector_ops.hpp"
#include <math.h>
#include<algorithm>
#include <vector>

banana::pie::pie(){
    this->sum=0;
    this->sub; 
    this->div;
}


void banana::pie::set_arr_sum(vector<float> data){
    for(int i=0; i<data.size(); i++){
        this->sum= data[i]+this->sum;
    }
}

void banana::pie::set_arr_sub(vector<float> data, vector<float> data2){
    float arr[data.size()];    //make an array to count data points in each bucket
    float starter= data[0]-data2[0];

    this->sub.insert(sub.begin(), starter);  //start the vector

    for(int i=1; i<data.size(); i++){
        arr[i]= data[i]-data2[i];
        vector<float>::iterator testing2= this->sub.insert(sub.end(), 1, arr[i]);    //load the bucketvals with the array values
        
    }

}

void banana::pie::set_div_arr(vector<float> data, float val){
    float arr[data.size()];    //make an array to count data points in each bucket

    float starter= data[0]*(1/val);

    this->div.insert(div.begin(), starter);  //start the vector
    for(int i=1; i<data.size(); i++){
        arr[i]= data[i]*(1/val);
        vector<float>::iterator testing2= this->div.insert(div.end(), 1, arr[i]);    //load the bucketvals with the array values
    }
}


float banana::pie::get_arr_sum(){
    return this->sum;
}

vector<float> banana::pie::get_arr_sub(){
    return this->sub;
}

vector<float> banana::pie::get_div_arr(){
    return this->div;
}

