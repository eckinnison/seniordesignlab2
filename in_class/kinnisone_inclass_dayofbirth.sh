#!/bin/sh
##Emma Claire Kinnison
##2/28/21
##comments:This is my shell script for lab 2 part 4 part a

wget https://raw.githubusercontent.com/eckinnison/seniordesignlab2/master/Lab1/kinnisone_stats.cpp

#function = "tryme::hell::hell(){"
#function2 = "float tryme::hell::get_max(){"
#function3 = "float tryme::hell::get_min(){"
#function4 = "float tryme::hell::get_mean(){"
#function5 = "float tryme::hell::get_std(){"
#function6 = "vector<float> tryme::hell::get_histogram_buckets(){"
#function7 = "vector<float> tryme::hell::get_histogram_bucketsvals(){"
##function8 = "void tryme::hell::set_max(vector<float> data){"
#function9 = "void tryme::hell::set_mean(vector<float> data){"
#function10 = "void tryme::hell::set_histogram(vector<float> data) {"
#function11 = "void tryme::hell::set_std(vector<float> data, float mean) {"

sed -i 's/:://g' "kinnisone_stats.cpp"


