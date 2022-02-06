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

void tryme::hell::set_max(float* data){
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

void tryme::hell::set_min(float* data){

    this->min=1;
}

void tryme::hell::set_mean(float* data){

    this->mean=1;
}

int main(){
    return 0;
}