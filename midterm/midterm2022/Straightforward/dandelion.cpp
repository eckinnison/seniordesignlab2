#include <string>
#include <iostream>
#include <vector>
#include "toss_a_coin.hpp"
#include "wolf.hpp"



int main(int argc, char *argv[]){

    witcher::WhiteWolf gerald;
    witcher::TossACoin coin;

    for(std::string line : gerald.getFirstVerse()){
        std::cout << line << std::endl;
    }
    std::cout << std::endl;
    for(std::string line : coin.getChorus()){
        std::cout << line << std::endl;
    }
    std::cout << std::endl;
    for(std::string line : gerald.getSecondVerse()){
        std::cout << line << std::endl;
    }
    std::cout << std::endl;
    for( int i=0; i<3; i++ ){
        for(std::string line : coin.getChorus()){
            std::cout << line << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}

