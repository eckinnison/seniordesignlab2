#!/bin/sh
##Emma Claire Kinnison
##2/28/21
##comments:This is my shell script for lab 2 part 4 part a


echo "Which timepoints do you want to check? Please enter a number 0-6"

read userin


#check for correct input
while [ ! $userin == "0" ] && [ ! $userin == "1" ] && [ ! $userin == "2" ] && [ ! $userin == "3" ] && [ ! $userin == "4" ] && [ ! $userin == "5" ] && [ ! $userin == "6" ];
do
    echo "Please try again!"
    echo "Enter a number between 0 and 6!"
    read userin
done  

if [ $userin == "0" ]
then 
    second=0
fi

if [ $userin == "1" ]
then 
    second=1
fi

if [ $userin == "2" ]
then 
    second=2
fi

if [ $userin == "3" ]
then 
    second=3
fi

if [ $userin == "4" ]
then 
    second=4
fi

if [ $userin == "5" ]
then 
    second=5
fi

if [ $userin == "6" ]
then 
    second=6
fi


data="datafiles/datafiles/"
green="green_"
green_back="green_background_"
red="red_"
red_back="red_background_"
gene="gene_list.txt"
dat=".dat"
log_rat="log_ratio_"
index=0
input="input"

while [ $index -le $second ]
do
     ./preprocess $data$red$index$dat $data$red_back$index$dat  $data$green$index$dat  $data$green_back$index$dat $log_rat$index$dat $second
    
    let "index++"
done

index=0
while [ $index -le $second ]
do
     ./cluster $log_rat$index$dat
    if [ $index == 0 ]
    then
        cat "expressed_genes.txt">"expressed_genes_total.txt" 
        cat "suppressed_genes.txt">"suppressed_genes_total.txt" 
        cat "stationary_genes.txt">"stationary_genes_total.txt" 
    else
        cat "expressed_genes.txt">>"expressed_genes_total.txt" 
        cat "suppressed_genes.txt">>"suppressed_genes_total.txt" 
        cat "stationary_genes.txt">>"stationary_genes_total.txt" 
    fi
    let "index++"
done

index=0


bash kinnisone_genequery.sh
