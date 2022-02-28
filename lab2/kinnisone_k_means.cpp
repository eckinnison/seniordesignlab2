#include "kinnisone_pre_processing.hpp"
#include "kinnisone_stats.hpp"
#include "kinnisone_vector_ops.hpp"
#include "kinnisone_k_means.hpp"
#include <math.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
std::ifstream myfile;
std::ifstream myfile2;

/*
This sets up all the variables so they can be modified in this file
*/
meanie::cluster::cluster(){
    this->name;
    this->mean=0;
    this->distance=0;
    this->cluster_data;
}

void meanie::cluster::set_cluster_mean(float data){
    this->mean=data;
}

float meanie::cluster::get_cluster_mean(){
    return this->mean;
}

void meanie::cluster::set_distance(float data){
    this->distance= abs(data - this->mean);
}

float meanie::cluster::get_distance(){
    return this->distance;
}


void meanie::cluster::set_name(std::string namer){
    this->name=namer;
}

std::string meanie::cluster::get_name(){
    return this->name;
}

std::ofstream expressedfile;
std::ofstream suppressedfile;
std::ofstream stationaryfile;


int main(int argc, char** argv){
    tryme::hell calc;

    meanie::cluster suppressed_cluster;
    meanie::cluster stationary_cluster;
    meanie::cluster expressed_cluster;

    float suppressed_cluser_mean= -0.5;
    float stationary_cluser_mean=  0;
    float expressed_cluser_mean=  0.5;

    std::string lograt_file;
    std::string gene_file;
    gene_file="gene_list.txt";
    if(argv[1]!=NULL){
        lograt_file=argv[1];
    }
    else{
        std::cout<<"Error: No input file\n";
            return 1;
    }  
    myfile.open(lograt_file);
    myfile2.open(gene_file);

    if((myfile.is_open())&&(myfile2.is_open())){
        
        std::istream_iterator<float> start(myfile), end;    //get the red data for file one
        std::vector<float> data(start, end);
        std::istream_iterator<std::string> start2(myfile2), end2;    //get the red data for file one
        std::vector<std::string> data2(start2, end2);

        float suppressed_distance;
        float stationary_distance;
        float expressed_distance;
        float new_clust_mean1;
        float new_clust_mean2;
        float new_clust_mean3;
        float criteria=1;

        std::vector<float> cluster1;
        std::vector<float> cluster2;
        std::vector<float> cluster3;
        std::vector<float> expressed;
        std::vector<float> stationary;
        std::vector<float> suppressed;
       // printf("initialized\n");

        while(criteria>0.0001){ 
         //   printf("got here\n");

            cluster1.clear();
            cluster2.clear();
            cluster3.clear();
            expressed.clear();
            stationary.clear();
            suppressed.clear();
          
            //loop through each cluster
            for(int j=0;j<data.size();j++){     //tab through all the data to sort it
                       

                suppressed_cluster.set_cluster_mean(suppressed_cluser_mean);
                suppressed_cluster.set_distance(data[j]);
                suppressed_distance=suppressed_cluster.get_distance();
            
                
                stationary_cluster.set_cluster_mean(stationary_cluser_mean);
                stationary_cluster.set_distance(data[j]);
                stationary_distance=stationary_cluster.get_distance();

                    
                expressed_cluster.set_cluster_mean(expressed_cluser_mean);
                expressed_cluster.set_distance(data[j]);
                expressed_distance=expressed_cluster.get_distance();
            

                if((suppressed_distance<stationary_distance)&&(suppressed_distance<expressed_distance)){
                    if(cluster1.size()==0){
                        cluster1.insert(cluster1.begin(), data[j]);
                        suppressed.insert(suppressed.begin(),j);
                        //printf("here7\n");
                    }
                    else{
                        vector<float>::iterator testing1= cluster1.insert(cluster1.end(), 1, data[j]);    //load the bucketvals with the array values
                        vector<float>::iterator testing4= suppressed.insert(suppressed.end(), 1, j);    //load the bucketvals with the array values

                    }
                }
                else if((stationary_distance<=suppressed_distance)&&(stationary_distance<=expressed_distance)){
                    if(cluster2.size()==0){
                        cluster2.insert(cluster2.begin(), data[j]);
                        stationary.insert(stationary.begin(),j);
                        //printf("here8\n");
                    }
                    else{
                        vector<float>::iterator testing2= cluster2.insert(cluster2.end(), 1, data[j]);    //load the bucketvals with the array values
                        vector<float>::iterator testing5= stationary.insert(stationary.end(), 1, j);    //load the bucketvals with the array values

                    }
                }
                else{
                    if(cluster3.size()==0){
                        cluster3.insert(cluster3.begin(), data[j]);
                        expressed.insert(expressed.begin(),j);                            
                        //printf("here8\n");
                    }
                    else{
                        vector<float>::iterator testing3= cluster3.insert(cluster3.end(), 1, data[j]);    //load the bucketvals with the array values
                        vector<float>::iterator testing6= expressed.insert(expressed.end(), 1, j);    //load the bucketvals with the array values
                    }
                }  
                
            }
            
            //calc new means
            calc.set_mean(cluster1);
            new_clust_mean1=calc.get_mean();
            calc.set_mean(cluster2);
            new_clust_mean2=calc.get_mean();
            calc.set_mean(cluster3);
            new_clust_mean3=calc.get_mean();

            //printf("New mean 1: %f\n",new_clust_mean1 );
            //printf("New mean 2: %f\n",new_clust_mean2 );
            //printf("New mean 3: %f\n",new_clust_mean3 );
            criteria=abs(suppressed_cluser_mean-new_clust_mean1)+abs(stationary_cluser_mean-new_clust_mean2)+abs(expressed_cluser_mean-new_clust_mean3);
            suppressed_cluser_mean=new_clust_mean1;
            stationary_cluser_mean=new_clust_mean2;
            expressed_cluser_mean=new_clust_mean3;
        }
        printf("Final mean 1: %f\n",suppressed_cluser_mean );
        printf("Final mean 2: %f\n",stationary_cluser_mean );
        printf("Final mean 3: %f\n",expressed_cluser_mean );
           
        expressedfile.open("expressed_genes.txt");
        suppressedfile.open("suppressed_genes.txt");
        stationaryfile.open("stationary_genes.txt");
        int a=0;
        int b=0;
        int c=0;

        for (int z=0; z<data.size(); z++){
            if(z==expressed[a]){
                expressedfile<<data2[z]<<"\n";
                a++;
            }
            else if(z==suppressed[b]){
                suppressedfile<<data2[z]<<"\n";
                b++;
            }
            else if(z==stationary[c]){
                stationaryfile<<data2[z]<<"\n";
                c++;
            }
        }
        expressedfile.close();
        suppressedfile.close();
        stationaryfile.close();
        

    }
    else{
        if(!(myfile.is_open())){
            std::cout<<"Error: .dat file cant be found\n";
            return 1;
        }
    }
    printf("done\n");

    return 0;
}