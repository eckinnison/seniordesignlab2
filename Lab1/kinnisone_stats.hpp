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
#include <fstream>


namespace tryme{
    class hell{
        public:
            hell();

            float get_max();
            float get_min();
            float get_mean();

            void set_max(float* data);
            void set_min(float* data);
            void set_mean(float* data);

        private:
           float max;
           float min;
           float mean; 
    };
}

#endif