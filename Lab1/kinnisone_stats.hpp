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


            //setters
             ECclass();
             
            //getters

            float get_max(){
                return max;
            }
            float get_min(){
                return min;
            }
            float get_mean(){
                return mean;
            }

            //setters
            void set_max(std::vector<float> data);
            void set_min(std::vector<float> data);
            void set_mean(std::vector<float> data);

        private:
            float max;
            float min;
            float mean;


    };
}

#endif

