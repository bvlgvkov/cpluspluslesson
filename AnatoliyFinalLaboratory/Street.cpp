#include <algorithm>
#include <thread>
#include <mutex>
#include <fstream>
#include "Street.h"

using namespace std;

mutex mut;

Street::Street(){}

Street::Street(House house)
{
    setsHouse.insert(house);
    amount++;
    isEmpty = false;
    mostBiggestHouse = max(mostBiggestHouse, house.getHeight());
}

unordered_set<House, HouseHandler> Street::getHouses()
{
    return setsHouse;
}

void Street::setHouses(unordered_set<House, HouseHandler> setsHouse)
{
    this->setsHouse = setsHouse;
}

int Street::getAmount() const
{
    return amount;
}

int Street::getMostBiggestHouse() const
{
    return mostBiggestHouse;
}

void Street::addHouse(string material, int number, int height, string color)
{
    setsHouse.emplace(material, number, height, color);
    amount++;
    isEmpty = false;
    mostBiggestHouse = max(mostBiggestHouse, height);
}

void Street::sortStreet()
{   
    vector<House> housesAfterSort(setsHouse.begin(), setsHouse.end());
    
    sort(housesAfterSort.begin(), housesAfterSort.end());
    cout << "Sort has been finished" << endl;
    
    for (auto i = housesAfterSort.begin(); i != housesAfterSort.end(); i++)
        cout << *i << endl;
}

bool Street::findByNumber(int number)
{
    for (auto it = setsHouse.begin(); it != setsHouse.end(); ++it) {
        if (it->getNumber() == number) {
            cout << "The House " << number << " had been found:" << endl;
            cout << *it << endl;
            
            return true;
        }
    }

    cout << "The House " << number << " didn't find" << endl;
    return false;
}

void Street::convertHouse(int number)
{
    bool house = findByNumber(number);
    
    if (house) {
        string color;
        cout << "Write a new Color for the House" << endl;
        cin >> color;
        for (auto it = setsHouse.begin(); it != setsHouse.end(); ++it)
            if (it->getNumber() == number) {
                string material = it->getMaterial();
                int height = it->getHeight();
                
                deleteHouse(number);
                addHouse(material, number, height, color);
            }
                
            
        cout << "The Color had been changed" << endl;
    }
}

void Street::deleteHouse(int number)
{
    lock_guard<mutex> lock(mut);
    bool check = findByNumber(number);
    if (check) {
        for (auto it = setsHouse.begin(); it != setsHouse.end(); ++it)
            if (it->getNumber() == number) {
                it = setsHouse.erase(it);
                break;
            }
        
        cout << "The House had been deleted" << endl;
    }
}

void Street::writeToFile()
{
    lock_guard<mutex> lock(mut);
    ofstream myfile("write.txt");
    if (myfile.is_open())
    {
        myfile << amount << "\n";
        myfile << *this;
        myfile.close();
        cout << "The file has been created" << endl;
    }
    else
        throw MyException("File doesn't create");
}

void Street::readFromFile()
{
    lock_guard<mutex> lock(mut);
    string material, color;
    int height, number;
    string line;
    string delimiter = " ";
    ifstream myfile("write.txt");
    if (myfile.is_open())
    {
        getline(myfile, line);
        int amount = stoi(line);
        while (getline(myfile, line))
        {
            size_t pos = 0;
            string token;
            int counter = 0;
            while ((pos = line.find(delimiter)) != string::npos)
            {
                token = line.substr(0, pos);
                if (counter == 1)
                    material = token;
                else if (counter == 2)
                    number = stoi(token);
                else if (counter == 3)
                    height = stoi(token);

                line.erase(0, pos + delimiter.length());
                counter++;
            }

            color = line;
            addHouse(material, number, height, color);
        }
        myfile.close();
        cout << "The file has been read" << endl;
    }
    else
        throw MyException("File doesn't exist");
}

Street::~Street()
{
    setsHouse.clear();
    cout << "Delete Street" << endl;
};

ostream &operator<<(ostream &out, const Street &street)
{
    for (auto i = street.setsHouse.begin(); i != street.setsHouse.end(); i++)
        out << *i << endl;

    return out;
};