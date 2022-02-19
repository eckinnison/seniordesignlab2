#!/bin/sh
##Emma Claire Kinnison
##2/8/21
##comments:This is my shell script for lab 1

#user interface for selection
echo "Which concentration would you like for the histogram? ERP00 or ERP05?"

read userin

#check for correct input
while [ ! $userin == "ERP00" ] && [ ! $userin == "ERP05" ];
do
    echo "Please try again!"
    echo "ERP00 or ERP005"
    read userin
done    


#if the input is ERP00
if [ $userin == "ERP00" ];
then
    #this is the file path and indexing through it
    first="EEG_DATA/ERP/ERP00/ERP00"
    index=1
    end=".txt"

    #start the data file
    cat $first$index$end > catted_input.dat

    #loop through get the rest of the files
    while [ $index -le 59 ]
    do
        index=$((index+1))
        cat $first$index$end >> catted_input.dat
    done

    #output the histogram to the correct spot in the directory
    first="EEG_DATA/ERP/ERP00/"
    filename="catted_input.dat"
    ./cppstatstest $first$filename > EEG_DATA/hist_out00.txt
    readlink -f hist_out00.txt

    #if its the other input
elif [ $userin == "ERP05" ];
then
    
    #make the data
    first="EEG_DATA/ERP/ERP05/ERP05."
    index=1
    end=".txt"

    cat $first$index$end > catted_input.dat

    #get the rest of the data
    while [ $index -le 59 ]
    do
        index=$((index+1))
        cat $first$index$end >> catted_input.dat
    done

    #make the historgram file
    first="EEG_DATA/ERP/ERP05"
    filename="/catted_input.dat"
    ./cppstatstest $first$filename> EEG_DATA/hist_out05.txt
    readlink -f hist_out05.txt
fi

#user input stuff
echo "Which concentration would you like for the correlation? ERP00 or ERP05?"

read userin

#if theres a wrong input
while [ ! $userin == "ERP00" ] && [ ! $userin == "ERP05" ];
do
    echo "Please try again!"
    echo "ERP00 or ERP005"
    read userin
done  

#if this input
if [ $userin == "ERP00" ];
then
   
   #make the correlation file
    first="EEG_DATA/ERP/ERP00/ERP00"
    index=1
    index2=2
    end=".txt"
    vs=" vs. "
    ./corcpptest $first$index$end $first$index2$end >conc_corr_00.txt
    echo $index$vs$index2 >>conc_corr_00.txt

    #index through all the different combos
    while [ $index -le 58 ]
    do
        index=$((index+1))
        index2=$((index2+1))
        ./corcpptest $first$index$end $first$index2$end >> conc_corr_00.txt
        echo $index$vs$index2 >>conc_corr_00.txt
    done
    
    #if this input
elif [ $userin == "ERP05" ];
then
    #make the correlation files
    first="EEG_DATA/ERP/ERP05/ERP05."
    index=1
    index2=2
    end=".txt"
    vs=" vs. "

        ./corcpptest $first$index$end $first$index2$end > conc_corr_05.txt
        echo $index$vs$index2 >>conc_corr_05.txt

    #loop through all the different combos
    while [ $index -le 58 ]
    do
        index=$((index+1))
        index2=$((index2+1))
        ./corcpptest $first$index$end $first$index2$end >> conc_corr_05.txt
        echo $index$vs$index2 >>conc_corr_05.txt

    done
    
fi



