/*
Author: Brea Brennan
Date: 2/8/21

Discription: This is the header file for Lab1, which contains the class and functions used in the
	     calculation of different statistics for a single EEG file from the EEG_Data folder
	     copied over to the user's drive.

*/

#ifndef STATS
#define STATS

#include <iostream>
#include <unistd.h>
#include <vector>

namespace Statistics{
	class Stats{
		public:
			Stats(float min, float max, float mean, float std); //Constructor for the class
			void minimum(std::vector<float>*); //Calculates the min of the input arrays
			void maximum(std::vector<float>*); //Calculates the max of the input arrays
			float meanCalc(std::vector<float>*);	//Calculates the mean of the input arrays
			void standardDev(std::vector<float>*, float , float);	//Calculates the standard deviation of the input arrays
			std::vector<float>  histogram(std::vector<float>*, float, float);	//estimates a histogram from input arguments			
			//Getters
			float get_min(); //returns min number
			float get_max(); //retuns max number
			float get_mean(); //returns the mean value
			float get_std();	//returns the std value
			
		private:
			float min;
			float max;
			float mean;
			float std;
	};
}


#endif


