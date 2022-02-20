#include "kinnisone_stats.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>

//using namespace tryme;

std::ifstream myfile;


int main(int argc, char** argv){
    tryme::hell whatamI;                //make the object and vector and file name
    std::vector<float> data;
    std::string filename;
	if(argv[1]!=NULL){
        filename =argv[1];
    }
    else{
        std::cout<<"Error: No arguments\n";
            return 8;
    }
    
    myfile.open(filename);                              //open the files

    if(myfile.is_open()){
        std::istream_iterator<float> start(myfile), end;        //get the data
        vector<float> data(start, end);
        if(data[0]==NULL){                                  //the file is empty
            std::cout<<"Error: The file is empty\n";
            return 1;
        }

        int i=0;
        std::cout<<"numbnerof data points: "<<data.size()<<"\n";        //print the numebr of data points
        
        whatamI.set_max(data);                  //set, get, print the max
        float maximum= whatamI.get_max();
        std::cout<<"max: "<<maximum<<"\n";

        whatamI.set_min(data);                  //set, get, print the min
        float minimum= whatamI.get_min();
        std::cout<<"min: "<<minimum<<"\n";

        whatamI.set_mean(data);                 //set, get, print the mean
        float mean= whatamI.get_mean();
        std::cout<<"mean: "<<mean<<"\n";

        whatamI.set_std(data, mean);            //set, get, print the std
        float std= whatamI.get_std();
        std::cout<<"std: "<<std<<"\n";
        
        whatamI.set_histogram(data);            //set, get, print the histogram
        std::vector<float> buckets= whatamI.get_histogram_buckets();
        std::vector<float> bucketvals= whatamI.get_histogram_bucketsvals();
        std::cout<<"\n \n \n \t \t Histogram\n";
        std::cout<<"\t  Key: = -> 1 data point\n\n\n";

        if(buckets.size()==0){
            std::cout<<"Error: There are zero histogram buckets\n";
            return 3;
        }
        if(bucketvals.size()==0){
            std::cout<<"Error: There are zero datapoints in the histogram buckets\n";
            return 4;
        }
        for(int i=0; i<buckets.size();i++){
            std::cout<<buckets[i] <<" <-> "<<buckets[i+1]<< " num in bucket "<<bucketvals[i];
            for(int j=0;j<bucketvals[i];j++){
                std::cout<<"=";
            }
            std::cout<<"\n";
        }
    }
    else{                                               //throw an error if the file doesnt exist
        std::cout<<"Error: The file didnt open\n";
        return 2;
    }
    return 0;
}