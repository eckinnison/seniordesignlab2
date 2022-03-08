#include <iostream>
#include "thehob.hpp"
#include "mowin.hpp"

int main(){


	Remix::TheHobbit hobbitObject;
	std::string hobstr = hobbitObject.getLyrics();

	Original::Nerdy mowin;
	std::string segstr = mowin.getSegway();

	std::cout << "\n\""<< hobstr << "\"\nis a whopping: " << hobstr.length() << " characters long!\n\n";

	std::cout << "\n\"" <<segstr << "\"\nis a crazy: " << segstr.length() << " characters long!\n";

}

