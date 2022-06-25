#include "Street.h"
#include "House.h"


using namespace std;


int main() {
    int option = 0;
    Street street;
    try
    {
        while (true)
        {   
            if (option == 0)
            {
                cout << "Choose the option: " << endl;
                cout << "1. Create House" << endl;
                cout << "2. Find House by Number" << endl;
                cout << "3. Convert Color for House" << endl;
                cout << "4. Print All Houses" << endl;
                cout << "5. Sort Houses" << endl;
                cout << "6. Delete House From Number" << endl;
                cout << "7. Read Street from file" << endl;
                cout << "8. Write Street to file" << endl;
                cout << "10. Exit" << endl;
                option = -1;
            }

            cin >> option;
            if (option == 1)
            {
                string material, color;
                int height, number;
                cout << "Material" << endl;
                cin >> material;
                cout << "Number" << endl;
                cin >> number;
                cout << "Height" << endl;
                cin >> height;
                cout << "Color" << endl;
                cin >> color;
                street.addHouse(material, number, height, color);
                
                option = 0;
            }
            else if (option == 2)
            {
                cout << "Write number of House" << endl;
                int number;
                cin >> number;
                street.findByNumber(number);
                option = 0;
            }
            else if (option == 3)
            {
                cout << "Write number of House" << endl;
                int number;
                cin >> number;
                street.convertHouse(number);
                option = 0;
            }
            else if (option == 4)
            {
                cout << street;
                option = 0;
            }
            else if (option == 5)
            {
                street.sortStreet();
                option = 0;
            }
            else if (option == 6)
            {
                cout << "Write number of House" << endl;
                int number;
                cin >> number;
                auto a1 = std::async(&Street::deleteHouse, &street, number);
                option = 0;
            }
            else if (option == 7)
            {
                auto a2 = std::async(&Street::readFromFile, &street);
                option = 0;
            }
            else if (option == 8)
            {
                auto a3 = std::async(&Street::writeToFile, &street);
                option = 0;
            }
            else if (option == 10)
            {
                cout << "GoodBye" << endl;
                break;
            }
            else
            {
                throw invalid_argument("Type menu");
            }
        };
    }
    catch (invalid_argument &e)
    {
        cout << "Access denied - Wrong type of variations: " << e.what() << endl;
    }
    catch (MyException &ex)
    {
        cout << "Unable to open file: " << ex.what() << endl;
    }

    return 0;
}