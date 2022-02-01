/*Name: Emma Claire Kinnison
Assignment: Lab 1
Date 2/1/22
Comments: This is the c file to sum the random numbers and output the resutle
*/

#ifndef EmmaClairegaurds
#define EmmaClairedefinesstuff

#include <iostream>
#include <fstream>
#include <string>
#include <vector> // #include directive

using namespace std;

namespace ECnamespace{
    class ECclass{
        public:
            ECclass();


            //setters
            void maxcalc(std::vector<float> data);
            void mincalc(std::vector<float> data2);
            void meancalc(std::vector<float> data3);

            //getters

        private:
            float max;
            float min;
            float mean;


    };
}

#endif

