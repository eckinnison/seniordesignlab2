#!/bin/sh
##Emma Claire Kinnison
##2/8/21
##comments:This is my shell script for lab 1

echo "Which concentration would you like for the histogram? ERP00 or ERP05?"

read userin


while [ ! $userin == "ERP00" ] && [ ! $userin == "ERP05" ];
do
    echo "Please try again!"
    echo "ERP00 or ERP005"
    read userin
done    



if [ $userin == "ERP00" ];
then
   
    first="EEG_DATA/ERP/ERP00/ERP00"
    index=1
    end=".txt"

    cat $first$index$end > catted_input.dat

    while [ $index -le 59 ]
    do
        index=$((index+1))
        cat $first$index$end >> catted_input.dat
    done
    first="EEG_DATA/ERP/ERP00/"
    filename="catted_input.dat"
    ./cppstatstest $first$filename 2>&1 | tee EEG_DATA/hist_out00.txt
    readlink -f hist_out00.txt
elif [ $userin == "ERP05" ];
then
    
    first="EEG_DATA/ERP/ERP05/ERP05."
    index=1
    end=".txt"

    cat $first$index$end > catted_input.dat

    while [ $index -le 59 ]
    do
        index=$((index+1))
        cat $first$index$end >> catted_input.dat
    done
    first="EEG_DATA/ERP/ERP05"
    filename="/catted_input.dat"
    ./cppstatstest $first$filename 2>&1 | tee EEG_DATA/hist_out05.txt
    readlink -f hist_out05.txt
fi

echo "Which concentration would you like for the correlation? ERP00 or ERP05?"

read userin


while [ ! $userin == "ERP00" ] && [ ! $userin == "ERP05" ];
do
    echo "Please try again!"
    echo "ERP00 or ERP005"
    read userin
done  

if [ $userin == "ERP00" ];
then
   
    first="EEG_DATA/ERP/ERP00/ERP00"
    index=1
    index2=2
    end=".txt"
    vs=" vs. "
    ./corcpptest $first$index$end $first$index2$end >conc_corr_00.txt
    echo $index$vs$index2 >>conc_corr_00.txt

    while [ $index -le 58 ]
    do
        index=$((index+1))
        index2=$((index2+1))
        ./corcpptest $first$index$end $first$index2$end >> conc_corr_00.txt
        echo $index$vs$index2 >>conc_corr_00.txt
    done
    
elif [ $userin == "ERP05" ];
then
    first="EEG_DATA/ERP/ERP05/ERP05."
    index=1
    index2=2
    end=".txt"
    vs=" vs. "

        ./corcpptest $first$index$end $first$index2$end > conc_corr_05.txt
        echo $index$vs$index2 >>conc_corr_05.txt

    while [ $index -le 58 ]
    do
        index=$((index+1))
        index2=$((index2+1))
        ./corcpptest $first$index$end $first$index2$end >> conc_corr_05.txt
        echo $index$vs$index2 >>conc_corr_05.txt

    done
    
fi



