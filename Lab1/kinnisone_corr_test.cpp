#include "kinnisone_stats.hpp"
#include "kinnisone_corr.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>


std::ifstream myfile;
std::ifstream myfile2;


int main(int argc, char** argv){
    imgood::heaven iamthis;         //create object

    std::vector<float> data;        //create data vector
    std::string filename;           //make and get the filename
    //std::cout << "Please provide the file name.\n";
    if (argv[1]!= NULL){
        	filename =argv[1];
    }
    else{
        std::cout<<"Error: first argument missing!\n";
         return 8;
    }

    std::vector<float> data2;       //create a second data vector
    std::string filename2;          //make and get the second filename
    //std::cout << "Please provide a second file name.\n";
    if (argv[2]!= NULL){
        	filename2 =argv[2];
    }
    else{
        std::cout<<"Error: second argument missing!\n";
         return 9;
    }
    myfile.open(filename);      //open both files
    myfile2.open(filename2);

    if((myfile.is_open())&&(myfile2.is_open())){        //only run if both files open
        std::istream_iterator<float> start(myfile), end;    //get the data for file one
        vector<float> data(start, end);
        std::istream_iterator<float> start2(myfile2), end2; //get the data for file two
        vector<float> data2(start2, end2);  

        if(data[0]==NULL){                                  //if file one is empty throw error
            std::cout<<"Error: The first file is empty\n";
            return 1;
        }
        if(data2[0]==NULL){                                 //if file two is empty throw error
            std::cout<<"Error: The second file is empty\n";
            return 2;
        }

        iamthis.set_cor(data, data2);                       //set the corresponding value
        float corr= iamthis.get_cor();                      //get and print it
        std::cout<<" "<<corr<<", ";
    }
    else{                                                   //throw an error if either file doesnt exist
        std::cout<<"Error: Couldn't open one or both of the datafiles\n";
        return 3;
    }
    return 0;
}