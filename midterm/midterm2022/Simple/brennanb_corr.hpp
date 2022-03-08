/*
Author: Brea Brennan
Date: 2/16/2021

Discription: This is the header file for Lab1, which contains the class and functions used in the
	     calculation of the correlation coeficient between two different EEG files that have 
	     been coppied over to the user's local environment.


*/

#ifndef CORR
#define CORR

#include <iostream>
#include <unistd.h>
#include <vector>


namespace Statistics{
	class Corr{
		public:
			Corr(float corrCoef); //Constructor
			
			//Function used to estimate the correclation coefficent of 2 data sets
			void findCorrCoef(std::vector<float>*, std::vector<float>*, float);
			
			//Getters
			float get_CorrCoef(); 	

		private:
			float corrCoef;
	};
}

#endif

