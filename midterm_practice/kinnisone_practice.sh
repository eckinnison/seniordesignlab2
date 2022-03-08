#!/bin/sh
##Emma Claire Kinnison
##3/8/21
##comments:This is my shell script the midterm

if  [ ! -d  "midterm2022" ]
then
    cp /lab/bien4290/midterm2022 -r /home/kinnise/Lab0_C_code/midterm
fi

cd midterm2022

cd Straightforward


echo $(ls) >>"test.txt"
num_rows=0

while IFS= read -r fields; do
    file[num_rows]=${fields[$num_rows]}
    echo "${file[$num_rows]}"

    ((num_rows=num_rows+1))
done< "test.txt"

echo "${file[$num_rows]}"
echo "$num_rows}"
