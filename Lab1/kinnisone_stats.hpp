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

namespace tryme{
    class hell{
        public:
            hell();

            float get_max();
            float get_min();
            float get_mean();
            float get_std();
            float get_histogram();

            void set_max(vector<float> data);
            void set_min(vector<float> data);
            void set_mean(vector<float> data);
            void set_std(vector<float> data, float means);
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