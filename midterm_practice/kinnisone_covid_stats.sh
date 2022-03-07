#!/bin/sh
##Emma Claire Kinnison
##3/5/21
##comments:This is my shell script the midterm



if [ ! -f "owid-covid-data.csv" ]                   #set up all the variables in int form instead of string
then
    wget https://raw.githubusercontent.com/owid/covid-19-data/master/public/data/owid-covid-data.csv -c covid_data.csv
fi


    #echo "Record is : $line" < owid-covid-data.csv

arr_csv=() 
#while IFS= read -r line 
#do
 #   arr_csv+=("$line")
#done < owid-covid-data.csv

#echo "Displaying the contents of array mapped from csv file:"
#index=0

#echo "Record at index-${index} : $arr_csv[@]"

num_rows=0
num_rows_start=0
num_rows_end=0
#https://www.xmodulo.com/read-column-data-text-file-bash.html#:~:text=To%20read%20column%20data%20from%20a%20file%20in%20bash%2C%20you,%2Dof%2Dfile%20is%20reached.
while IFS=, read -ra fields; do
    location[num_rows]=${fields[2]}
    date[num_rows]=${fields[3]}
    total_cases[num_rows]=${fields[4]}
    new_cases[num_rows]=${fields[5]}
    new_cases_smoothed[num_rows]=${fields[6]}
    total_deaths[num_rows]=${fields[7]} 
    new_deaths[num_rows]=${fields[8]}
    new_deaths_smoothed[num_rows]=${fields[9]}
    total_cases_per_million[num_rows]=${fields[10]} 
    new_cases_per_million[num_rows]=${fields[11]} 

    if [[ ${location[num_rows]} == *"$@"* ]]
    then
        if [ ! $num_rows_start = 0 ]
        then
            true
        else
           num_rows_start=$num_rows 
           echo "blah $num_rows_start"
        fi    
    fi


    if [ $num_rows_start -gt 0 ]
    then
        if [[ ${location[num_rows]} -ne $@ ]]
        then
            num_rows_end=$(echo "$num_rows-1" | bc -l )

                       echo "$num_rows_end"

        fi
    fi
    ((num_rows=num_rows+1))
done < "owid-covid-data.csv"




#https://linuxhint.com/check-the-number-of-arguments-in-bash/#:~:text=The%20%24%23%20special%20variable%20always,to%20any%20specific%20Bash%20script.
echo "the passed arguments are:"
echo $@
echo "the total number of arguments is:"
echo $#

index=0
sum=0
echo "pre $sum"


sum=0.0
month=0
for (( index=$num_rows_start;index<$num_rows_end;index++))
do
        echo "here $sum"

    
        echo "$sum + ${new_cases_per_million[$index]}"
        echo "${new_cases_per_million[$index]}"
        sum=$(echo "$sum + ${new_cases_per_million[$index]}" | bc -l )
    

done