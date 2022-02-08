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
    std::cout << "Please provide the file name.\n";
	std::cin >> filename;
   
    myfile.open(filename);

    if(myfile.is_open()){
        std::istream_iterator<float> start(myfile), end;
        vector<float> data(start, end);

        int i=0;
        std::cout<<"numbnerof data points: "<<data.size()<<"\n";
        
        whatamI.set_max(data);
        float maximum= whatamI.get_max();
        std::cout<<"max: "<<maximum<<"\n";

        whatamI.set_min(data);
        float minimum= whatamI.get_min();
        std::cout<<"min: "<<minimum<<"\n";

        whatamI.set_mean(data);
        float mean= whatamI.get_mean();
        std::cout<<"mean: "<<mean<<"\n";

        whatamI.set_std(data, mean);
        float std= whatamI.get_std();
        std::cout<<"std: "<<std<<"\n";
        
        whatamI.set_histogram(data);
        std::vector<float> buckets= whatamI.get_histogram_buckets();
        std::vector<float> bucketvals= whatamI.get_histogram_bucketsvals();
                std::cout<<"\n \n \n \t \t Histogram\n\n\n";

        for(int i=0; i<buckets.size();i++){
            std::cout<<buckets[i] <<" <-> "<<buckets[i+1];
            for(int j=0;j<bucketvals[i];j++){
                std::cout<<"=";
            }
            std::cout<<"\n";

        }


    }


    return 0;
}