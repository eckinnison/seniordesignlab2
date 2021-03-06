/*
Name: Emma Claire Kinnison
Date:2/6/21
Assignment: Lab 1
Comments: This code helps to drive the functionality of 
the other two files. Helps to load data in to all the calculations
*/

#ifndef PRIMER
#define PRIMER

#include <vector>
#include <iostream>
#include <string>
using std::vector;

namespace tryme{        //this is my namespace, I was very frustrated when making this
    class hell{         //this is my class because I thought using the classes was very not fun
        public:         //just make all the functions work
            hell();

            float get_max();
            float get_min();
            float get_mean();
            float get_std();                                
            vector<float> get_histogram_buckets();
            vector<float> get_histogram_bucketsvals();

            void set_max(vector<float> data);
            void set_min(vector<float> data);
            void set_mean(vector<float> data);
            void set_std(vector<float> data, float mean);
            void set_histogram(vector<float> data);

        private:
           float max;
           float min;
           float mean; 
           float std;
           vector<float> buckets;
           vector<float> bucketvals; 

    };
}

#endif