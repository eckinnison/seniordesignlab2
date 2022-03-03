#!/bin/sh
##Emma Claire Kinnison
##2/28/21
##comments:This is my shell script for lab 2 part 4 part a

#check for the user input
echo "Which timepoints do you want to check? Please enter a number 0-6"

read userin


#check for correct input
while [ ! $userin == "0" ] && [ ! $userin == "1" ] && [ ! $userin == "2" ] && [ ! $userin == "3" ] && [ ! $userin == "4" ] && [ ! $userin == "5" ] && [ ! $userin == "6" ];
do
    echo "Please try again!"                        #try again
    echo "Enter a number between 0 and 6!"
    read userin
done  

if [ $userin == "0" ]                   #set up all the variables in int form instead of string
then 
    second=0
fi

if [ $userin == "1" ]                   #set up all the variables in int form instead of string
then 
    second=1
fi

if [ $userin == "2" ]                   #set up all the variables in int form instead of string
then 
    second=2
fi

if [ $userin == "3" ]                   #set up all the variables in int form instead of string
then 
    second=3
fi

if [ $userin == "4" ]                   #set up all the variables in int form instead of string
then 
    second=4
fi

if [ $userin == "5" ]                   #set up all the variables in int form instead of string
then 
    second=5
fi

if [ $userin == "6" ]                   #set up all the variables in int form instead of string
then 
    second=6
fi


data="datafiles/datafiles/"         #make the string variables
green="green_"
green_back="green_background_"
red="red_"
red_back="red_background_"
gene="gene_list.txt"
dat=".dat"
log_rat="log_ratio_"
index=0
input="input"
echo "Summary file" > "overall_summary.txt"

while [ $index -le $second ]        #make the while loop
do
     ./preprocess $data$red$index$dat $data$red_back$index$dat  $data$green$index$dat  $data$green_back$index$dat $log_rat$index$dat $second
     cat $log_rat$index$dat > $log_rat$indput$dat       #run preprocess and print it to the files
       echo "This is time point #$index" >> "overall_summary.txt"       #print to the files
       echo " "
       echo "Time Stamp $index"
     ./cluster $log_rat$indput$dat >> "overall_summary.txt"     #run the cluster

        cat "expressed_genes.txt">"expressed_genes_total_"$index".txt"      #print to the files
        cat "suppressed_genes.txt">"suppressed_genes_total_"$index".txt" 
        cat "stationary_genes.txt">"stationary_genes_total_"$index".txt" 

        echo "Number of expressed Genes:" >>"overall_summary.txt"           #print to the files
        wc -l < "expressed_genes_total_"$index".txt" >>"overall_summary.txt"
        echo "Number of suppressed Genes:" >>"overall_summary.txt"
        wc -l < "suppressed_genes_total_"$index".txt" >>"overall_summary.txt"
        echo "Number of stationary Genes:" >>"overall_summary.txt"
        wc -l < "stationary_genes_total_"$index".txt" >>"overall_summary.txt"

        bash kinnisone_genequery.sh "$index"            #run the gene querey

    let "index++"
done

    

