#ifndef HOUSE
#define HOUSE

#include <string>
#include <iostream>
#include <unordered_set>

class House {
    
    std::string material;
    int number;
    int height;
    std::string color = "Black";
    
    public:
        House(std::string material, int number, int height, std::string color);
        
        House(std::string material, int number, int height);
        
        House(const House& p1);
        
        House& operator=(const House& p1);

        int getHeight() const;
        
        int getNumber() const;
        
        std::string getMaterial() const;
        
        ~House();
    
    
    friend std::ostream& operator<< (std::ostream &out, const House &house);
    
    friend bool operator==(const House &house1, const House &house2);
};

bool operator<(const House &x, const House &y);

#endif



