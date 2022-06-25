#ifndef HOUSEHANDLER
#define HOUSEHANDLER


#include "House.h"

class HouseHandler {
    std::hash<int> ihash;
    
    public:
        size_t operator()(const House& ob) const;
};


#endif
