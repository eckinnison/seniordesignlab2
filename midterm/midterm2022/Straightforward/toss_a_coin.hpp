
#include <string>
#include <vector>
#include "valley_of_plenty.hpp"


#ifndef COIN
#define COIN

namespace witcher{

    class TossACoin{
        public:
            TossACoin();
            std::string getCoin();
            std::vector<std::string> getChorus();
        private:
            ValleyOfPlenty valley;
    };
}
#endif