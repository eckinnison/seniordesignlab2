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
std::ofstream finalfile;

int main(int argc, char** argv){
    banana::pie obj;            //make all the objects
    tryme::hell calc;
    pizza::toppings bacon;

    std::string redcellfile;            //make all the strings and other input variables
    std::string backgroundredfile;
    std::string greencellfile;
    std::string backgroundgreenfile;
    std::string calidatafile;
    int genenum;

	if(argv[1]!=NULL){          //get the red cell file or throw an error
        redcellfile =argv[1];
    }
    else{
        std::cout<<"Error: No red cell file\n";
            return 1;
    }  

    if(argv[2]!=NULL){          //get the red background cell file or throw an error
        backgroundredfile =argv[2];
    }
    else{
        std::cout<<"Error: No red background file\n";
            return 2;
    } 

    if(argv[3]!=NULL){          //get the green cell file or throw an error
        greencellfile =argv[3];
    }
    else{
        std::cout<<"Error: No green cell file\n";
            return 3;
    } 

    if(argv[4]!=NULL){          //get the green background cell file or throw an error
        backgroundgreenfile =argv[4];
    }
    else{
        std::cout<<"Error: No green background file\n";
            return 4;
    } 

    if(argv[5]!=NULL){          //get the write to file or throw an error
        calidatafile =argv[5];
    }
    else{
        std::cout<<"Error: No written file name\n";
            return 5;
    } 

    if(argv[6]!=NULL){          //get the number of genes
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


        if((genenum<=data.size())||(genenum<=data2.size())||(genenum<=data3.size())||(genenum<=data4.size())){  //only do it while we have data
            obj.set_arr_sub(data, data2);                   //subtract the redbackground from the red
            std::vector<float> subred = obj.get_arr_sub();
            obj.set_arr_sub(data3, data4);                  //subtract the greenbackground from the green
            std::vector<float> subgreen = obj.get_arr_sub();

            calc.set_mean(subred);                      //calc the new red mean
            float meanred= calc.get_mean();

            calc.set_mean(subgreen);                      //calc the new green mean
            float meangreen= calc.get_mean();

            obj.set_div_arr(subred, meanred);            //calc the division for red
            std::vector<float> normred = obj.get_div_arr();
            obj.set_div_arr(subgreen, meangreen);       //calc the division for green
            std::vector<float> normgreen = obj.get_div_arr();
            

            bacon.set_log_ratio(normred, normgreen);        //calc the log ratio
            std::vector<float> intense_ratio =bacon.get_log_ratio();

            finalfile.open(calidatafile);       //open the write to file

            for (int j=0; j<intense_ratio.size();j++){      //write all the values to the file
                finalfile << intense_ratio[j]<<"\n";
            }
            finalfile.close();

        }
        else{       //throw the error
            std::cout<<"Error: Data file too small for number of genes requested\n";
            return 12;
        }



    }
    else{           //figure out which file was the first problem
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