#include "kinnisone_stats.hpp"
#include "kinnisone_vector_ops.hpp"
#include "kinnisone_pre_processing.hpp"
#include <math.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>

std::ifstream myfile;
std::ifstream myfile2;
std::ifstream myfile3;
std::ifstream myfile4;
std::ifstream myfile5;


pizza::toppings::toppings(){
    this->log_ratio;
}

vector<float> pizza::toppings::get_log_ratio(){
    return this->log_ratio;
}

void pizza::toppings::set_log_ratio(vector<float> data, vector<float> data2){
    float arr[data.size()];    //make an array to count data points in each bucket

    for(int i=0; i<data.size();i++){
        arr[i]=log(data[i]/data2[i]);
        vector<float>::iterator testing2= this->log_ratio.insert(log_ratio.begin(), 1, arr[i]);    //load the bucketvals with the array values
    }

}

std::ofstream finalfile;

int main(int argc, char** argv){
    banana::pie obj;
    tryme::hell calc;
    pizza::toppings bacon;

    std::string redcellfile;
    std::string backgroundredfile;
    std::string greencellfile;
    std::string backgroundgreenfile;
    std::string calidatafile;
    int genenum;

	if(argv[1]!=NULL){
        redcellfile =argv[1];
    }
    else{
        std::cout<<"Error: No red cell file\n";
            return 1;
    }  

    if(argv[2]!=NULL){
        backgroundredfile =argv[2];
    }
    else{
        std::cout<<"Error: No red background file\n";
            return 2;
    } 

    if(argv[3]!=NULL){
        greencellfile =argv[3];
    }
    else{
        std::cout<<"Error: No green cell file\n";
            return 3;
    } 

    if(argv[4]!=NULL){
        backgroundgreenfile =argv[4];
    }
    else{
        std::cout<<"Error: No green background file\n";
            return 4;
    } 

    if(argv[5]!=NULL){
        calidatafile =argv[5];
    }
    else{
        std::cout<<"Error: No written file name\n";
            return 5;
    } 

    if(argv[6]!=NULL){
        genenum =atoi(argv[6]);
    }
    else{
        std::cout<<"Error: No number of genes\n";
            return 6;
    } 

    myfile.open(redcellfile);                              //open the files
    myfile2.open(backgroundredfile);                              //open the files
    myfile3.open(greencellfile);                              //open the files
    myfile4.open(backgroundgreenfile);                              //open the files

    if((myfile.is_open())&&(myfile2.is_open())&&(myfile3.is_open())&&(myfile4.is_open())){
        std::istream_iterator<float> start(myfile), end;    //get the red data for file one
        std::vector<float> data(start, end);
        std::istream_iterator<float> start2(myfile2), end2; //get the red background data for file two
        std::vector<float> data2(start2, end2);  
        std::istream_iterator<float> start3(myfile3), end3;    //get the green data for file one
        std::vector<float> data3(start3, end3);
        std::istream_iterator<float> start4(myfile4), end4; //get the green background data for file two
        std::vector<float> data4(start4, end4); 


        if((genenum<=data.size())||(genenum<=data2.size())||(genenum<=data3.size())||(genenum<=data4.size())){
            obj.set_arr_sub(data, data2);
            std::vector<float> subred = obj.get_arr_sub();
            printf("size subred: %f\n", subred.size());
            obj.set_arr_sub(data3, data4);
            std::vector<float> subgreen = obj.get_arr_sub();

            calc.set_mean(subred);
            float meanred= calc.get_mean();
            printf("meanred: %f\n", meanred);

            calc.set_mean(subgreen);
            float meangreen= calc.get_mean();
            printf("meangreen: %f\n", meangreen);

            obj.set_div_arr(subred, meanred);
            std::vector<float> normred = obj.get_div_arr();
            obj.set_div_arr(subgreen, meangreen);
            std::vector<float> normgreen = obj.get_div_arr();
            printf("normred[2]: %i\n", normred[2]);
            printf("normgreen[2]: %i\n", normgreen[2]);

            bacon.set_log_ratio(normred, normgreen);
            std::vector<float> intense_ratio =bacon.get_log_ratio();

            finalfile.open(calidatafile);
                    printf("here3\n");
            printf("intense_ratio.size(): %i\n", intense_ratio.size());

            for (int j=0; j<intense_ratio.size();j++){
                finalfile << intense_ratio[j]<<"\n";
            }
            finalfile.close();

        }
        else{
            std::cout<<"Error: Data file too small for number of genes requested\n";
            return 12;
        }



    }
    else{
        if(!(myfile.is_open())){
            std::cout<<"Error: Red cell file didnt open\n";
            return 7;
        }
        else if(myfile.is_open()){
            std::cout<<"Error: Red cell background file didnt open\n";
            return 8;

        }
        else if (myfile.is_open()){
            std::cout<<"Error: Green cell file didnt open\n";
            return 9;

        }
        else if(myfile.is_open()){
            std::cout<<"Error: Green cell background file didnt open\n";
            return 10;
        }
        else{
            std::cout<<"Error: Unknown error\n";
            return 11;
            
        }
    }
    return 0;
}