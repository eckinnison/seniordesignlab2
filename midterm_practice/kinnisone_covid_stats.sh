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
num_rows1=1

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


    ((num_rows=num_rows+1))
done < "owid-covid-data.csv"




#https://linuxhint.com/check-the-number-of-arguments-in-bash/#:~:text=The%20%24%23%20special%20variable%20always,to%20any%20specific%20Bash%20script.
echo "the passed arguments are:"
echo $@
echo "the total number of arguments is:"
echo $#

index=0

month=0
sum=0
while [ $index -le $num_rows ]
do
    if [ $@ == "${location[$index]}" ] 
    then
        if [[ "2020-02" == *"${data[$index]}"* ]]
        then
            month=0
            echo "pre ${sum[$month]}"
            echo "pre2 ${new_cases_per_million[$index]}"

            echo "${sum[$month]} + ${new_cases_per_million[$index]}" | bc -l 
            echo  "${sum[$month]}"
            #(("$sum[$month]"=("${sum[$month]}" + "${new_cases_per_million[$index]}" | bc -l))
            echo "here"

        # elif [[ "2020-03" == *"${data[$index]}"* ]]
        # then 
        #     month=1
        #     ((sum[$month]=sum[$month]+${new_cases_per_million[$index]}))
        #     echo "here1"

        # elif [[ "2020-04" == *"${data[$index]}"* ]]
        # then 
        #     month=2
        #     ((sum[$month]=sum[$month]+${new_cases_per_million[$index]})) 
        #     echo "here2"

        # elif [[ "2020-05" == *"${data[$index]}"* ]]
        # then 
        #     month=3
        #     ((sum[$month]=sum[$month]+${new_cases_per_million[$index]})) 
        #     echo "here3"
        else  
            true
        fi
    else
        true
    fi

    ((index=index+1))

done