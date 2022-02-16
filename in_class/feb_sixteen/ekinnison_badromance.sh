#!/bin/sh
##Emma Claire Kinnison
##2/16/21
##comments:This is my script is about bash conditionals


Ohs="Oh-oh-oh-oh-oh, oh-oh-oh-oh, oh-oh-oh"
Caught="Caught in a bad romance"
Roma="Ra-ra-ah-ah-ah, Roma Roma-ma"
Gaga="Gaga, Ooh la-la"
Want="Want your bad romance"

for index in {1..10}
do

    if [ $index -eq 1 ]
    then
        echo $Ohs
    fi
    if [ $index -eq 2 ]
    then
        echo $Caught
    fi
    if [ $index -eq 3 ]
    then
        echo $Ohs
    fi
    if [ $index -eq 4 ]
    then
        echo $Caught
    fi
    if [ $index -eq 5 ]
    then
        echo $Roma
    fi
    if [ $index -eq 6 ]
    then
        echo $Gaga
    fi
    if [ $index -eq 7 ]
    then
        echo $Want
    fi
    if [ $index -eq 8 ]
    then
        echo $Roma
    fi
    if [ $index -eq 9 ]
    then
        echo $Gaga
    fi
    if [ $index -eq 10 ]
    then
        echo $Want
    fi
done
echo ""
while IFS= read -r line; do 
    if [[ $line == 'Iron Man 2' ]]
    then
    echo "$line"
    fi
    
done < good_movies.txt




