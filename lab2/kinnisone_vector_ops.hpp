/*
Name: Emma Claire Kinnison
Date:2/19/21
Assignment: Lab 2
Comments: This is the header created for part 1 this means that this sums all elements of an array,
          subtracts one array from another, and divides all values of an array by a constant
*/



#ifndef PRIMER2
#define PRIMER2

#include <vector>
#include <iostream>
#include <string>

using std::vector;

    namespace banana{       //i was eating a banana when making this
        class pie{       //wanted the class to go with it
            public:             //just make sure all the functions work
                pie();

                float get_arr_sum();
                void set_arr_sum(vector<float> data);
                vector<float> get_arr_sub();
                void set_arr_sub(vector<float> data, vector<float> data2 );
                vector<float> get_div_arr();
                void set_div_arr(vector<float> data, float val);

            private:
                float sum;
                vector<float> sub;
                vector<float> div;

        };
    }





#endif