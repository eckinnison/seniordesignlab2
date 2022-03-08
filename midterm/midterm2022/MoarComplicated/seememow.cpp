#include <iostream>
#include "thehob.hpp"
#include "mowin.hpp"

int main(){

std::cout << std::boolalpha; // This line converts all console outputs of boolean values to their text representations...

Remix::TheHobbit hobbitObject;
std::string hobstr = hobbitObject.getLyrics();

Original::Nerdy mowin;
std::string segstr = mowin.getSegway();

std::cout << "Does:\n\n\"" << hobstr << "\"\ncontain the word \"taking\"? " << (hobstr.find("taking")!=std::string::npos) << "!\n\n";

std::cout << "Does:\n\n\"" << segstr << "\"\ncontain the word \"taking\"? " << (segstr.find("taking")!=std::string::npos) << "!\n\n";


}

