#include <algorithm>
#include <thread>
#include <mutex>
#include <fstream>
#include "HouseHandler.h"


size_t HouseHandler::operator()(const House & ob) const {
    const size_t coef = 1234;
    return (coef * ihash(ob.getNumber()));
}

