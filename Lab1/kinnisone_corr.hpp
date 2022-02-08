/*
Name: Emma Claire Kinnison
Date:2/6/21
Assignment: Lab 1
Comments: This corresponding shows how similar two data sets are

*/

#ifndef PRIMER2
#define PRIMER2

#include <vector>
#include <iostream>
#include <string>
#include "kinnisone_stats.hpp"
using std::vector;

    namespace imgood{       //this is my namespace, I was less frustrated this time
        class heaven{       //this is my class, named to balence out the last class
            public:             //just make sure all the functions work
                heaven();
                float get_cor();
                void set_cor(vector<float> data, vector<float> data2);
            private:
                float cor;
        };
    }

#endif
