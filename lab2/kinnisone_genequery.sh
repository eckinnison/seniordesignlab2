#!/bin/sh
##Emma Claire Kinnison
##2/28/21
##comments:This is my shell script for lab 2 part 4 part 

echo "Which gene do you want to check?"

read userin

if grep -Fxq "$userin" "expressed_genes_total_"$1".txt"
then
    echo "Expressed"
else
    if grep -Fxq "$userin" "suppressed_genes_total_"$1".txt"
    then
        echo "Surppressed"
    else
        if grep -Fxa "$userin" s"tationary_genes_total_"$1".txt"
        then
            echo "Stationary"
        else
            echo "Not a gene"
        fi
    fi
fi

