#include "kinnisone_vector_ops.hpp"
#include <math.h>
#include<algorithm>
#include <vector>

banana::pie::pie(){
    this->sum=0;
    this->sub.push_back(0); //this is wrong but core dumps
    this->div.push_back(0);//this is wrong but core dumps
}


void banana::pie::set_arr_sum(vector<float> data){
    for(int i=0; i<data.size(); i++){
        this->sum= data[i]+this->sum;
    }
}

void banana::pie::set_arr_sub(vector<float> data, vector<float> data2){
    for(int i=0; i<data.size(); i++){
        this->sub[i]= data[i]-data2[i];
    }
}

void banana::pie::set_div_arr(vector<float> data, float val){
        printf("data.size(): %f\n",data.size());

    
    for(int i=0; i<data.size(); i++){
        this->div[i]= data[i]*(1/val);
        printf("data: %f\n",data[i]);
       // this->div= Vector.Divide(data, val);
       printf("div: %f\n", this->div[i]);
        printf("val: %f\n", val);
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

