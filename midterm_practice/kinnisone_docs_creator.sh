#!/bin/sh
##Emma Claire Kinnison
##3/7/21
##comments:This is my shell script the midterm


echo "the passed arguments are:"
echo $@
echo "the total number of arguments is:"
echo $#

if [ -f "$1" ]                   #set up all the variables in int form instead of string
then
    echo "this file exists"
else
    echo "this file doesnt exist"
fi
 
num_rows=0;
while read -r fields; do
    data[num_rows]=$fields;
    ((num_rows=num_rows+1))
done < "2020_test_data/test_data/batch_backend.hpp"

echo "$num_rows"
flag=0
header_index_start=0
header_index_end=0

for (( index=0;index<$num_rows;index++))
do
    if [ $flag = 0 ]
    then
        if [[ "${data[$index]}" == *"/*"* ]]
        then
            header_index_start=$index
            flag=1
        fi
    fi
    if [ $flag = 1 ]
    then
        if [[ "${data[$index]}" == *"*/"* ]]
        then
            header_index_end=$index
            index=$(echo "$num_rows+1" | bc -l )
        fi
    fi
    
done

echo "index s $header_index_start"
echo "index E $header_index_end"

for(( i=$header_index_start;i<=$header_index_end;i++))
do
    echo ${data[$i]} | sed 's/'/'//' | sed 's/*//'">>"$1_documentation.txt"
    echo "${data[$i]}"
done


flag=0
place=0
for (( index=$header_index_end;index<$num_rows;index++))
do 
    if [ $flag = 0 ]
    then
        if [[ "${data[$index]}" == *"/*"* ]]
        then
            counter[place]=$index
            flag=1
            place=$(echo "$place+1" | bc -l )
        elif [[ "${data[$index]}" == *"//"* ]]
        then
            counter[place]=$index
            flag=2
            place=$(echo "$place+1" | bc -l )
        fi
    fi
    if [ $flag = 1 ]
    then
        if [[ "${data[$index]}" == *"*/"* ]]
        then
            counter[place]=$index
            flag=0
            place=$(echo "$place+1" | bc -l )
        fi
    fi
    if [ $flag = 2 ]
    then
        if [[ "${data[$index]}" == *"//"* ]]
        then
            true
        else
            index=$(echo "$index-1" | bc -l )
            counter[place]=$index
            flag=0
            place=$(echo "$place+1" | bc -l )
            index=$(echo "$index+1" | bc -l )

        fi
    fi

done


for(( i=0;i<=$place;i++))
do
        echo "">>"$1_documentation.txt"
    for(( j=${counter[$i]};j<=${counter[$i+1]};j++))
    do
        
        echo "${data[$j]}">>"$1_documentation.txt"
        echo "${data[$j]}"


    done
    i=$(echo "$i+1" | bc -l )


done
