#!/bin/sh
##Emma Claire Kinnison
##2/8/21
##comments:This is my shell script for lab 1

echo "Which concentration would you like? ERP00 or ERP05?"

read userin


while [ ! $userin == "ERP00" ] && [ ! $userin == "ERP05" ];
do
    echo "Please try again!"
    echo "ERP00 or ERP005"
    read userin
done    



if [ $userin == "ERP00" ];
then




fi


if [ $userin == "ERP05" ];
then



    
fi
