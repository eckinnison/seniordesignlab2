#include "kinnisone_pre_processing.hpp"
#include "kinnisone_vector_ops.hpp"
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



int main(int argc, char** argv){

    std::string redcellfile;
    std::string backgroundredfile;
    std::string greencellfile;
    std::string backgroundgreenfile;
    std::string calidatafile;
    float genenum;

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
        genenum =atof(argv[6]);
    }
    else{
        std::cout<<"Error: No green background file\n";
            return 6;
    } 

    myfile.open(redcellfile);                              //open the files
    myfile2.open(backgroundredfile);                              //open the files
    myfile3.open(greencellfile);                              //open the files
    myfile4.open(backgroundgreenfile);                              //open the files

    if((myfile.is_open())&&(myfile2.is_open())&&(myfile3.is_open())&&(myfile4.is_open())){
        std::istream_iterator<float> start(myfile), end;    //get the data for file one
        std::vector<float> data(start, end);
        std::istream_iterator<float> start2(myfile2), end2; //get the data for file two
        std::vector<float> data2(start2, end2);  
        std::istream_iterator<float> start3(myfile3), end3;    //get the data for file one
        std::vector<float> data3(start3, end3);
        std::istream_iterator<float> start4(myfile4), end4; //get the data for file two
        std::vector<float> data4(start4, end4); 

        if((genenum>data.size())||(genenum>data2.size())||(genenum>data3.size())||(genenum>data4.size())){
            banana::pie obj;
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



}