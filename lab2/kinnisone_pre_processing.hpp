/*
Name: Emma Claire Kinnison
Date:2/19/21
Assignment: Lab 2
Comments: these are my preprocessing files
*/

#ifndef PRIMER3
#define PRIMER3

#include "kinnisone_pre_processing.hpp"
#include "kinnisone_vector_ops.hpp"
#include <vector>
#include <iostream>
#include <string>

using std::vector;

    namespace pizza{       //this is my namespace, I was hungry when making it
        class toppings{       //this is my class, named provide toppings to the pizza
            public:             //just make sure all the functions work
                toppings();
                vector<float> get_log_ratio();
                void set_log_ratio(vector<float> data, vector<float> data2);
            private:
                vector<float> log_ratio;
        };
    }


#endif