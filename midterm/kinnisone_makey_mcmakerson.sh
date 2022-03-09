#!/bin/sh
##Emma Claire Kinnison
##3/8/21
##comments:This is my shell script the midterm

#get the directory if its not already there
if  [ ! -d  "midterm2022" ]
then
    cp /lab/bien4290/midterm2022 -r /home/kinnise/Lab0_C_code/midterm
fi

#check for an input
if [ $1 ]
then
    cd "$1"
else
    echo "no filepath"
    exit 1
fi

#check for a makefile
if [ -f "makefile" ]
then
    true
else
    touch "makefile"
fi
#get the output to a file
#echo "">"test.txt"
echo "$(ls)">"test.txt"






#get the filenames into a variable
num_rows=0
while read -r fields; do

    if [[ "$fields" == *".cpp"* ]]
    then
        cpp[num_rows_cpp]=$fields;
        ((num_rows_cpp=num_rows_cpp+1))
    elif [[ "$fields" == *".hpp"* ]]
    then
        hpp[num_rows_hpp]=$fields;
        ((num_rows_hpp=num_rows_hpp+1))
    else
        true
    fi
    #data[num_rows]=$fields;
done < "test.txt"






#get all the contents of the data into a variable for each file (cpp)
#num_rows_cpp is also the number of ofiles
numfile_rows_cpp=0
main_file=0
file_index_cpp[0]=0
for (( index=0;index<$num_rows_cpp;index++))
do
    include_file[index]=" "
    while read -r fields; do
        cppfile[file_rows_cpp]=$fields;
        if [[ "${cppfile[$file_rows_cpp]}" == *"#include"* ]]
        then
            if [[ "${cppfile[$file_rows_cpp]}" == *".hpp"* ]]
            then
                include_file[index]+=$(echo "${cppfile[$file_rows_cpp]}" | sed 's/#include //g'  | sed 's/["]//g')
                include_file[index]+=" "
                #echo "1 $index ${include_file[$index]}"
            elif [[ "${cppfile[$file_rows_cpp]}" == *".cpp"* ]]
            then
                include_file[index]+=$(echo "${cppfile[$file_rows_cpp]}" | sed 's/#include //g'  | sed 's/["]//g')
                include_file[index]+=" " 
                #echo "2 $index ${include_file[$index]}"
           
            else    
                true
            fi   
        fi
        if [[ "${cppfile[$file_rows_cpp]}" == *"main"* ]]
        then
            main_file=$index
        fi
        ((file_rows_cpp=file_rows_cpp+1))
    done < "${cpp[$index]}"
    ((index=index+1))
    file_index_cpp[$index]=$numfile_rows_hpp
    ((index=index-1))
    o_names[$index]=${cpp[$index]::-4}
done

#check for the contents of the hpps to have other hpps
numfile_rows_hpp=0
file_index_hpp[0]=0
for (( index=0;index<$num_rows_hpp;index++))
do
    include_file_hpp[index]=" "

    while read -r fields; do
        hppfile[numfile_rows_hpp]=$fields;
        if [[ "${hppfile[$numfile_rows_hpp]}" == *"#include"* ]]
        then
            if [[ "${hppfile[$numfile_rows_hpp]}" == *".hpp"* ]]
            then
                for (( indexs=0;indexs<$num_rows_cpp;indexs++))
                do
                    echo "1 $indexs ${include_file[$indexs]}"
                    echo "2 $indexs ${hpp[$index]}"

                    if [[ "${include_file[$indexs]}" = *"${hpp[$index]}"* ]]
                    then
                        echo "${hppfile[$numfile_rows_hpp]}"
                        include_file[indexs]+=$(echo "${hppfile[$numfile_rows_hpp]}" | sed 's/#include //g'  | sed 's/["]//g')
                        include_file[indexs]+=" " 
                        echo "0000000000000"
                    fi
                done
                
                
                #echo "3 $index ${include_file_hpp[$index]}"
           
            elif [[ "${hppfile[$numfile_rows_hpp]}" == *".cpp"* ]]
            then
               # echo "4 $index ${include_file_hpp[$index]}"
                for (( indexs=0;indexs<$num_rows_cpp;indexs++))
                do
                    echo "3 $indexs ${include_file[$indexs]}"
                    echo "4 $indexs ${hpp[$index]}"
                    if [[ "${include_file[$indexs]}" = *"${hpp[$index]}"* ]]
                    then
                        include_file[indexs]+=$(echo "${hppfile[$file_rows_hpp]}" | sed 's/#include //g'  | sed 's/["]//g')
                        include_file[indexs]+=" " 
                    fi
                done
            else    
                true
            fi   
        fi
        ((numfile_rows_hpp=numfile_rows_hpp+1))
    done < "${hpp[$index]}"
    ((index=index+1))
    file_index_hpp[$index]=$numfile_rows_hpp
    ((index=index-1))
done



#we have the file number that has main -> these make .o files/executable one last
#we have the line numbers of the files that need includes ->grep out everything but the file name, store in array->done
#we have the file names of the cpp ->parse into .o ->->got the .o_names
#put into make file



#make the final string
# for (( index=0;index<$num_rows_cpp;index++))
# do
#     final_includes[index]+=${include_file[$index]}
#     final_includes[index]+=" "
#     echo "5 ${final_includes[$index]}"
#     for (( indexhpp=0;indexhpp<$num_rows_hpp;indexhpp++))
#     do
#         if [[ "${include_file[$index]}" = *"${hpp[$indexhpp]}"* ]]
#         then
#             final_includes[index]+=${include_file_hpp[$indexhpp]}
#             echo "Index: $index Indexhpp: $indexhpp file#INC ${final_includes[$index]}"
#         fi
    

#     done
# done

for (( index=0;index<$num_rows_cpp;index++))
do
    final_includes[index]+=${include_file[$index]}
    final_includes[index]+=" "
    echo "6 $index ${final_includes[$index]}"
    for (( indexhpp=0;indexhpp<$num_rows_hpp;indexhpp++))
    do
        if [[ "${include_file_hpp[$index]}" = *"${hpp[$indexhpp]}"* ]]
        then
            final_includes[index]+=${include_file_hpp[$indexhpp]}
            echo "Index: $index Indexhpp: $indexhpp file#INC ${final_includes[$index]}"
        fi
    

    done
done


######################
#creating make file
#woot!!!woot!!!
######################


includes_index=0
for (( index=0;index<$num_rows_cpp;index++))
do
    if [ $main_file = $index ]
    then
        true
    else
        ((index2=index+1))
        echo -n "${o_names[$index]}.o: ${cpp[$index]}">>"makefile"
        # for (( inc=${includes_perfile[$index]};inc<=${includes_perfile[$index2]}; inc++))
        # do
        #     echo -n " ${include_file[$inc]}">>"makefile"
        # done
        echo -n "${final_includes[$index]}">>"makefile"
        ((inc=inc+1))

        echo " ">>"makefile"
        
        echo -e "\t \t \t g++ -c $^">>"makefile"
    fi
    echo " ">>"makefile"

done

#do the main at the bottom

    echo -n "${o_names[$main_file]}.o: ${cpp[$main_file]}">>"makefile"
    for (( index=0;index<$num_rows_cpp;index++))
    do
        if [ $main_file = $index ]
        then
            true
        else
            echo -n " ${o_names[$index]}.o">>"makefile"
        fi
    done
    echo "">>"makefile"
    echo -e "\t \t \t g++ -c $^">>"makefile"
    echo -e "\t \t \t g++ -o ${o_names[$main_file]} $^">>"makefile"
    echo "">>"makefile"


###make the all part
echo -n "all: ">>"makefile"
for (( index=0;index<$num_rows_cpp;index++))
do
    if [ $main_file = $index ]
    then 
        true
    else
        echo -n "${o_names[$index]}.o ">>"makefile"
    fi

done

echo -n "${o_names[$main_file]}.o ">>"makefile"
echo "">>"makefile"
echo "">>"makefile"

#make the clean part
    echo "clean: ">>"makefile"
    echo -e "\t rm -f *.o">>"makefile"
    echo -e "\t rm -f *.gch">>"makefile"
    echo -e "\t rm -f all">>"makefile"

make clean
make all

./${o_names[$main_file]}