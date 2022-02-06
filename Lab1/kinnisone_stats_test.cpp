#include "kinnisone_stats.hpp"




int main(){

    std::string filename;
    std::cout << "Please provide the file name.\n";
	std::cin >> filename;
   

    std::ifstream myfile(filename);
    double arr[10000];
    std::string line;   // To read each line from code
	int count=0; 
    
    if (myfile.is_open())
	{
        while(myfile.peek()!=EOF)
		{
			getline(myfile, line);
			count++;
            std::cout << "count\n"<<count;

		}
        myfile.close();
	}
	else{
     std::cout << "Unable to open file";
    }

    std::ifstream mynewfile(filename);

    if(mynewfile.is_open()){
        for (int i = 0; i < count; i++)
		{
			mynewfile >> arr[i];
            std::cout << "\n"<<arr[i];
		}
    }

     
    return 0;
}