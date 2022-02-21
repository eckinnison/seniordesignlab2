#include "kinnisone_vector_ops.hpp"
#include <math.h>
#include<algorithm>
#include <vector>

banana::pie::pie(){
    this->sum=0;
    this->sub; //this is wrong but core dumps
    this->div;//this is wrong but core dumps
}


void banana::pie::set_arr_sum(vector<float> data){
    for(int i=0; i<data.size(); i++){
        this->sum= data[i]+this->sum;
    }
}

void banana::pie::set_arr_sub(vector<float> data, vector<float> data2){
    float arr[data.size()];    //make an array to count data points in each bucket

    for(int i=0; i<data.size(); i++){
        arr[i]= data[i]-data2[i];
        vector<float>::iterator testing2= this->sub.insert(sub.begin(), 1, arr[i]);    //load the bucketvals with the array values
    }
    printf("sub(): %f\n",data.size());

}

void banana::pie::set_div_arr(vector<float> data, float val){
    printf("data.size(): %f\n",data.size());
    float arr[data.size()];    //make an array to count data points in each bucket

    
    for(int i=0; i<data.size(); i++){
        arr[i]= data[i]*(1/val);
        vector<float>::iterator testing2= this->div.insert(div.begin(), 1, arr[i]);    //load the bucketvals with the array values
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

