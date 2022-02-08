/*
Name: Emma Claire Kinnison
Date:2/6/21
Assignment: Lab 1
Comments: This is the header file for the corelation program

*/

#ifndef PRIMER2
#define PRIMER2

#include <vector>
#include <iostream>
#include <string>
#include "kinnisone_stats.hpp"
using std::vector;

    namespace imgood{
        class heaven{
            public:
                heaven();
                float get_cor();
                void set_cor(vector<float> data, vector<float> data2);
            private:
                float cor;
        };
    }

#endif
