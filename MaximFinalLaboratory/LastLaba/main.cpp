#include "Library.h"

using namespace std;

int main()
{
    int option = 0;
    Library library;
    try
    {
        while (true)
        {
            if (option == 0)
            {
                cout << "Choose the option: " << endl;
                cout << "1. Create Book" << endl;
                cout << "2. Find Book by Name" << endl;
                cout << "3. Convert Genre for Book" << endl;
                cout << "4. Print All Books" << endl;
                cout << "5. Sort books" << endl;
                cout << "6. Delete Book From Library" << endl;
                cout << "7. Read library from file" << endl;
                cout << "8. Write library to file" << endl;
                cout << "10. Exit" << endl;
                option = -1;
            }

            cin >> option;
            if (option == 1)
            {
                string author, name, genre;
                int pages;
                cout << "Author" << endl;
                cin >> author;
                cout << "Name" << endl;
                cin >> name;
                cout << "Pages" << endl;
                cin >> pages;
                cout << "Genre" << endl;
                cin >> genre;
                library.addBook(author, name, pages, genre);
                option = 0;
            }
            else if (option == 2)
            {
                cout << "Write name of Book" << endl;
                string name;
                cin >> name;
                library.findByName(name);
                option = 0;
            }
            else if (option == 3)
            {
                cout << "Write name of Book" << endl;
                string name;
                cin >> name;
                library.convertBook(name);
                option = 0;
            }
            else if (option == 4)
            {
                cout << library;
                option = 0;
            }
            else if (option == 5)
            {
                library.sortLibrary();
                option = 0;
            }
            else if (option == 6)
            {
                cout << "Write name of Book" << endl;
                string name;
                cin >> name;
                auto a1 = std::async(&Library::deleteBook, &library, name);
                option = 0;
            }
            else if (option == 7)
            {
                auto a2 = std::async(&Library::readFromFile, &library);
                option = 0;
            }
            else if (option == 8)
            {
                auto a3 = std::async(&Library::writeToFile, &library);
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