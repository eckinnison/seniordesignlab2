#!/bin/sh
##Emma Claire Kinnison
##2/28/21
##comments:This is my shell script for lab 2 part 4 part 

echo "Which gene do you want to check?"

read userin

#read in everything 

if grep -Fxq "$userin" "expressed_genes_total_"$1".txt" #check for the user input
then
    echo "Expressed"
else
    if grep -Fxq "$userin" "suppressed_genes_total_"$1".txt"  #check for the user input
    then
        echo "Surppressed"
    else
        if grep -Fxq "$userin" "stationary_genes_total_"$1".txt"  #check for the user input
        then
            echo "Stationary"
        else                        #if it failed
            echo "Not a gene"
        fi
    fi
fi

