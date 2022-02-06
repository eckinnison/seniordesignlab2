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

    if(myfile.is_open()){
        istream_iterator<float> start(myfile), end;
        vector<float> data(start, end);

        cout<< "%d\n";
        int i=0;
        for (int i=0; i<data.size(); i++){
            cout<<data[i]<<endl;
        }

    }

    tryme::hell::hell whatamI;

    //whatamI.set_max(data);

     
    return 0;
}