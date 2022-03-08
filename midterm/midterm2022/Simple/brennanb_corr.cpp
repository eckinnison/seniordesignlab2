/*
Author: Brea Brennan
Date: 2/16/2021

Discription: This cpp file is for lab1 and the program is used to find the correlation coeficent
	     between two different data files of EEG data. The calculated correlation coeficent 
	     is displayed to the terminal window.

Assignement: Lab1

*/

#include "brennanb_corr.hpp"
#include "brennanb_stats.hpp"
#include <iostream>
#include <fstream>
#include <cmath>

//Constructor
Statistics::Corr::Corr(float corrCoef){
	this->corrCoef;
}

//getter for the corrCoef
float Statistics::Corr::get_CorrCoef(){
	return this->corrCoef;
}

//Function to estimate the correlation coef.
void Statistics::Corr::findCorrCoef(std::vector<float>* data1, std::vector<float>* data2, float N){
	
	//Note: data1 -> x and data2 -> y

	//Variables:
	float xysum = 0, xsum = 0, ysum = 0;
	float ymean, xmean;
	float num = 0;
	float dem1 = 0, dem2 = 0, demTot = 0;
	float coef = 0;

	//create a constructor for the stats class in order to use meanCalc
	float xmin, xmax, xstd;
	float ymin, ymax, ystd;
	Statistics::Stats xData(xmin, xmax, xmean, xstd);
	Statistics::Stats yData(ymin, ymax, ymean, xstd);

	//loops to calculate the summation of the data sets needed for calc.
	for(int i = 0; i < N; i++){
		xysum = xysum + ((data1->at(i)) * (data2->at(i)));
		xsum = xsum + (pow(data1->at(i), 2));
		ysum = ysum + (pow(data2->at(i), 2));		
	}
	
	//get the means of the two data sets
	xmean = xData.meanCalc(data1);
	ymean = yData.meanCalc(data2);

	//calculating the coef
	num = xysum - (N * xmean *ymean);
	dem1 = xsum - (N * pow(xmean, 2));
	dem2 = ysum - (N * pow(ymean, 2));
	demTot = dem1 * dem2;
	demTot = pow(demTot, .5);

	coef = num / demTot;

	//set the calc coef to the constructor var
	this->corrCoef = coef;
}


int main(int argc, char* argv[]){

	//Variables:
	std::vector<float> input1, input2;
	std::string path1, path2;
	std::string data1, data2;
	float p1 = 0; 
	float p2 = 0;
	float value1, value2;
	float coef;

	//Argument checking
	if(argc < 3){
		std::cout << "NOT ENOUGH ARGUMENTS\n";
		return 0;
	}
	
	//getting the path of the input files
	path1 = argv[1];
	path2 = argv[2];

	std::ifstream file1(path1);
	std::ifstream file2(path2);
	
	if(file1.is_open() && file2.is_open()){
		
		while(file1 >> data1){
			value1 = stof(data1);
			input1.push_back(value1);
			p1++;
		}

		while(file2 >> data2){
                        value2 = stof(data2);
                        input2.push_back(value2);
                        p2++;
                }
		
		//Checking to make sure the files have the same amount of points
		if(p1 != p2){
			std::cout << "THE FILES DON'T HAVE THE SAME NUMBER OF POINTS!\n";
			return 0;
		}

		//Constructor
		Statistics::Corr corrClass(coef);
		
		//find the correlation coef and dusplay it
		corrClass.findCorrCoef(&input1, &input2, p1);
		std::cout << path1.substr((path1.size() - 6), 2) << " vs " << path2.substr((path2.size() - 6), 2) << ", " << corrClass.get_CorrCoef() << "\n";

	}
	else{
		std::cout << "ERROR: ONE OR BOTH FILES WAS UNABLE TO BE OPENED\n";
	}


}






















