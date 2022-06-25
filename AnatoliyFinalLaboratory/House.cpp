#include "House.h"

using namespace std;



House::House(string material, int number, int height, string color)
{
    this->material = material;
    this->number = number;
    this->height = height;
    this->color = color;
};

House::House(string material, int number, int height)
{
    this->material = material;
    this->number = number;
    this->height = height;
};

House::House(const House &p1)
{
    this->material = p1.material;
    this->number = p1.number;
    this->height = p1.height;
    this->color = p1.color;
}

House &House::operator=(const House &p1)
{
    this->material = p1.material;
    this->number = p1.number;
    this->height = p1.height;
    this->color = p1.color;

    return *this;
}

int House::getHeight() const
{
    return this->height;
}

int House::getNumber() const
{
    return this->number;
}

std::string House::getMaterial() const
{
    return this->material;
}

House::~House()
{
    cout << "Delete House " << this->number << endl;
};

bool operator<(const House &x, const House &y)
{
    return x.getHeight() < y.getHeight();
}

ostream &operator<<(ostream &out, const House &house)
{
    out << "House " << house.material << " " << house.number << " " << house.height << " " << house.color;

    return out;
};

bool operator==(const House &house1, const House &house2)
{
    return ((house1.number == house2.number) && (house1.material == house2.material) &&
            (house1.height == house2.height) && (house1.color == house2.color));
};