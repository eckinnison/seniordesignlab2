#include "kinnisone_stats.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>

using namespace std;

ifstream myfile;


int main(){

    string filename;
    cout << "Please provide the file name.\n";
	cin >> filename;
   
    myfile.open(filename);

    vector<float> data;
    if(myfile.is_open()){
        istream_iterator<float> start(myfile), end;
        vector<float> dataget(start, end);

       // cout<< "%d\n";
        int i=0;
        for (int i=0; i<dataget.size(); i++){
            data[i]=dataget[i];
        }

    }

    tryme::hell::hell() whatamI;
    whatamI.set_max(data);
    whatamI.set_min(data);
    whatamI.set_mean(data);





    return 0;
}