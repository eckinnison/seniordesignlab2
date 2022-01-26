/*Name: Emma Claire Kinnison
Assignment: Lab 0
Date 1/25/22
Comments: This is the c file to sum the random numbers and output the resutle
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {


//this part makes the file readable and reads it
    FILE *fp;
    const char *filename= "random_numbers.txt";
    fp= fopen(filename, "r");
    int sum=0;
    int Array[20];

//scanning the values from the read into an array and then calcualting the sum
    for(int i=0; i<20;i++){
        fscanf(fp, "%d", &Array[i]);
       // printf("This is the array %d \n",  Array[i]);
        sum=sum +Array[i];
    }
    fclose(fp);

//printing out the sum into the NEW file

    FILE *fp2;
    const char *filename2= "Sum_rand_num_result.txt";
    fp2= fopen(filename2, "w");
    fprintf(fp2, "This is the sum %d\n", sum);
    
    fclose(fp2);
    
    return 0;
}
