#include "kinnisone_stats.hpp"
#include "kinnisone_vector_ops.hpp"
#include "kinnisone_pre_processing.hpp"
#include <math.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>


pizza::toppings::toppings(){
    this->log_ratio;
}

vector<float> pizza::toppings::get_log_ratio(){
    return this->log_ratio;
}

void pizza::toppings::set_log_ratio(vector<float> data, vector<float> data2){
    float arr[data.size()];    //make an array to count data points in each bucket

    for(int i=0; i<data.size();i++){
        arr[i]=log10(data[i]/data2[i]);
        vector<float>::iterator testing2= this->log_ratio.insert(log_ratio.begin(), 1, arr[i]);    //load the bucketvals with the array values
    }

}