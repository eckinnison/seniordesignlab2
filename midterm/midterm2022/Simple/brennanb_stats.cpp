/*
Author: Brea Brennan
Date: 2/8/2021

Description: This file is used to find statistics about the inputed file. The
	     statistics of interest are the minimum, the maximim, the mean
	     and the standard deviation of the dataset. After the statistcal
	     anaylisis is complete, a histogram is to be generated to
	     represent the data of the input file.

Assignment: Lab 1 

*/

#include "brennanb_stats.hpp"
#include <iostream>
#include <fstream>
#include <cmath>


//Constructor for the stats class
Statistics::Stats::Stats(float min, float max, float mean, float std){
	this->min = min;
	this->max = max;
	this->mean = mean;
	this->std = std;
}

//getter for min value
float Statistics::Stats::get_min(){
	return this->min;
}

//getter for max value
float Statistics::Stats::get_max(){
	return this->max;
}

//getter for mean value
float Statistics::Stats::get_mean(){
	return this->mean;
}

//getter for std vlaue
float Statistics::Stats::get_std(){
	return this->std;
}

//Function to find min value
void Statistics::Stats::minimum(std::vector<float>* input){

	//Local Variables
	float temp = input->at(0); 

	for(int i=0; i < input->size(); i++)
	{
		if(input->at(i) < temp)
		{
			temp = input->at(i);
		}
	}
	
	//set the min value using the setter
	this->min = temp;
}

//Function to find max value
void Statistics::Stats::maximum(std::vector<float>* input){

	//Local Variables
	float temp = input->at(0);

	for(int i=0; i < input->size(); i++)
	{
		if(input->at(i) > temp)
		{
			temp = input->at(i);
		}
	}
	
	//set the max using the setter
	this->max = temp;
}

//Function to find the mean of the data vector
float Statistics::Stats::meanCalc(std::vector<float>* input){

	//Local Variables
	float m = 0;
	float sum = 0;
	float count = 0;
	
	//sum the values in the array
	for(int i=0; i < input->size(); i++)
	{
		sum = sum + input->at(i);
		count++;
	}
	
	//calculate the mean
	m = sum / count;

	this->mean = m;
	return m;
}

//Function to calculate the standard deviation of the data vector
void Statistics::Stats::standardDev(std::vector<float>* input, float m, float N){

	float sum = 0;
	float value = 0;
	float temp = 0;
	float val = 0;
	
	//Find the sum of the (value - mean) squared
	for(int i=0; i < input->size(); i++)
	{
		value = input->at(i) - m;
		sum = sum + pow(value, 2);
	}
	
	temp = sum / N;
	val = pow(temp, .5);
	
	//set the calculated std value
	this->std = val;
}
 
//Function to estimate a histogram and calc points in each pin
std::vector<float> Statistics::Stats::histogram(std::vector<float>* input, float standDev, float m){

	//Variables:
	float width;
	float binNum;
	float binMin;
	float binMax;
	std::vector<float> histOut;
	int counter = 0;
	int i = 0;

	//Calculating the width and number of bins
	width = .4 * standDev;
	binMin = m - (3 * standDev); //Needs to be 3 bins on each side anything below this num is an outlier
	binMax = m + (3 * standDev); //anything above this is an outlier
	binNum = (binMax- binMin) / width;

	for(int b = 0; b< binNum; b++){
		histOut.push_back(0); //set all the bins to start at zero
	}
	
	while(i < binNum){
		for(int p = 0; p < input->size(); p++){ //cycles through all the input value
			if((*input)[p] < binMin){ //in the first bin
				++histOut[0];
			} 
			else if(((*input)[p] >= (binMin + (width*i))) && ((*input)[p] <= (binMin + width + (width * i)))){
				++histOut[i];
			}
			else if((*input)[p] > binMax){ //in the last bin
				++histOut[binNum - 1];
			}
		}
		i++;
	}	

	return histOut;
}

//Function used to print the estimated histogram
void printHistogram(std::vector<float>* data){

	//Variables
	float max = 0;
	float temp = 0;
	float s = 0;
	float c = 0;

	//finding the max number of points in a bin to be used as the normalization
	for(int i = 0; i < data->size(); i++){
		if((*data)[i] >= temp){
			temp = (*data)[i];
		}
	}

	max = temp;

	std::cout << "\n";
	s = data->size();

	//actually printing the histogram out horizontally	
	for(int i = 0; i < s; i++){
		temp = ((*data)[i] / max) * 10;
		c = temp;
		std::cout << std::right << " | ";	
		while(c > 0){
			std::cout << "=";
			c--;
		}
		
		std::cout <<"\n";
		c = 0;
	}
	std::cout << "\nEach '=' represents less than or equal to 10 data points\n";
}
