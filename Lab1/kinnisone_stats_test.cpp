#include "kinnisone_stats.hpp"
#include "kinnisone_stats.cpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>

using namespace tryme;

std::ifstream myfile;


int main(int argc, char** argv){
    
    tryme::hell whatamI;
    std::vector<float> data;
    std::string filename;
    if(argc!=1){
        std::cout << "there needs to be 1 input, thanks";
        return 2;
    }

    filename= argv[1];


   
    myfile.open(filename);

    if(myfile.is_open()){
        std::istream_iterator<float> start(myfile), end;
        vector<float> dataget(start, end);

       // cout<< "%d\n";
        int i=0;
        for (int i=0; i<dataget.size(); i++){
            data[i]=dataget[i];
        }

    }

        whatamI.set_max(data);
//    // whatamI.set_min(data);
//    // whatamI.set_mean(data);

     float maximum= whatamI.get_max();

    std::cout<<"max: "<<maximum<<"/n";




    return 0;
}