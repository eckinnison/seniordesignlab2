/*
Name: Emma Claire Kinnison
Date:2/19/21
Assignment: Lab 2
Comments: these are my k_means files
*/

#ifndef PRIMER4
#define PRIMER4

#include "kinnisone_pre_processing.hpp"
#include "kinnisone_vector_ops.hpp"
#include <vector>
#include <iostream>
#include <string>

using std::vector;

    namespace meanie{       //this is my namespace, I was hungry when making it
        class cluster{       //this is my class, named provide toppings to the pizza
            public:             //just make sure all the functions work
                cluster();
                void set_name(std::string namer);
                std::string get_name();
                float get_cluster_mean();
                void set_cluster_mean(float data);
                void set_distance(float data);
                float get_distance();
            private:
                std::string name;
                float mean;
                float distance;
                vector<float> cluster_data;
        };
    }


#endif