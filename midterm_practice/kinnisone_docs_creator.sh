#!/bin/sh
##Emma Claire Kinnison
##3/7/21
##comments:This is my shell script the midterm


echo "the passed arguments are:"
echo $@
echo "the total number of arguments is:"
echo $#

if [ -f "$@" ]                   #set up all the variables in int form instead of string
then
    echo "this file exists"

else
    echo "this file doesnt exist"
fi
 
num_rows=0;
while IFS=, read -ra fields; do
    data[$num_rows]=fields[$num_rows];
    ((num_rows=num_rows+1))
    echo "here"
done < "$@"

i=0

#$(echo grep -Fen "/*" "kinnisone_k_means.hpp")
if [ grep -Fen "/*" "$@" ]
then
    echo "dskjfg"
    while [ grep -Fen "*/" "$@" ]
    do
        echo "here $fileds[$i]"
        ((i=i+1))

    done
    echo "hi"
    

else
    echo "blaaaaaaa"    
fi
echo "lkjhgf"