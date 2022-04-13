/*
Name: Emma Claire Kinnison
Date:4/11/22
Assignment: miniproject 1
Comments: this is to calculate statistics of the airspeed velocity of swallows
*/
#include "/home/kinnise/Lab0_C_code/Lab1/kinnisone_stats.cpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
std::ifstream myfile;

int main(int argc, char** argv){
    tryme::hell whatamI;                //make the object and vector and file name
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
      
    }
    else{                                               //throw an error if the file doesnt exist
        std::cout<<"Error: The file didnt open\n";
        return 2;
    }

    return 0;
}
