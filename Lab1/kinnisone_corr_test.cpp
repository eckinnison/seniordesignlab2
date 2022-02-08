#include "kinnisone_stats.hpp"
//#include "kinnisone_stats.cpp"
#include "kinnisone_corr.hpp"
#include "kinnisone_corr.cpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>

using namespace tryme;

std::ifstream myfile;
std::ifstream myfile2;


int main(int argc, char** argv){
    imgood::heaven iamthis;

    std::vector<float> data;
    std::string filename;
    std::cout << "Please provide the file name.\n";
	std::cin >> filename;

    std::vector<float> data2;
    std::string filename2;
    std::cout << "Please provide a second file name.\n";
	std::cin >> filename2;

    myfile.open(filename);
    myfile2.open(filename2);

    if((myfile.is_open())&&(myfile2.is_open())){
        std::istream_iterator<float> start(myfile), end;
        vector<float> data(start, end);
        std::istream_iterator<float> start2(myfile2), end2;
        vector<float> data2(start2, end2);

        iamthis.set_cor(data, data2);
        float corr= iamthis.get_cor();
        std::cout<<"corr: "<<corr<<"\n";
    }
    else{
        std::cout<<"Couldnt read datafiles\n";
        return 1;
    }
    return 0;
}