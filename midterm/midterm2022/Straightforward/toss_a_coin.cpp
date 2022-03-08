#include "toss_a_coin.hpp"

witcher::TossACoin::TossACoin(){
    // A friend of humanityyyeeeeeeeeEEEEE!
}

std::string witcher::TossACoin::getCoin(){
    return "Toss a coin to your Witcher";
}


std::vector<std::string> witcher::TossACoin::getChorus(){
    std::vector<std::string> refrain;

    refrain.push_back(this->getCoin());
    refrain.push_back(valley.getValley());
    refrain.push_back(valley.getValley() + valley.getOh());
    refrain.push_back(this->getCoin());
    refrain.push_back(valley.getValley());

    return refrain;
}