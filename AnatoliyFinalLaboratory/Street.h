#ifndef STREET
#define STREET

#include <future>
#include "House.h"
#include <bits/stdc++.h>
#include "MyException.h"
#include <iostream>
#include <unordered_set>
#include "HouseHandler.h"


class Street {
    int amount = 0;
    bool isEmpty = true;
    int mostBiggestHouse = 0;
    std::unordered_set<House, HouseHandler> setsHouse;
    
    public: 
        
        Street();
        
        Street(House house);
        
        std::unordered_set<House, HouseHandler> getHouses();
        
        void setHouses(std::unordered_set<House, HouseHandler> setsHouse);
        
        int getAmount() const;
        
        int getMostBiggestHouse() const;
        
        void addHouse(std::string material, int number, int height, std::string color);
        
        void sortStreet();
        
        bool findByNumber(int number);
        
        void convertHouse(int number);
        
        void deleteHouse(int number);
        
        void writeToFile();
        
        void readFromFile();
    
        friend std::ostream& operator<< (std::ostream &out, const Street &street);
    
        ~Street();
};

#endif