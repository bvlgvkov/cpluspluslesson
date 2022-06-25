#include <algorithm>
#include <thread>
#include <mutex>
#include <fstream>
#include "Library.h"


using namespace std;

mutex mut;

Library::Library()
{
    if (amount == 0)
        books.reserve(16);
}

Library::Library(Book book)
{
    if (amount == 0)
        books.reserve(16);

    books.push_back(book);
    amount++;
    isEmpty = false;
    mostBiggestBook = max(mostBiggestBook, book.getPages());
}

vector<Book> Library::getBooks()
{
    return books;
}

void Library::setBooks(vector<Book> books)
{
    this->books = books;
}

int Library::getAmount() const
{
    return amount;
}

int Library::getMostBiggestBook() const
{
    return mostBiggestBook;
}

void Library::addBook(string author, string name, int pages, string genre)
{
    books.emplace_back(author, name, pages, genre);
    amount++;
    isEmpty = false;
    mostBiggestBook = max(mostBiggestBook, pages);
}

void Library::sortLibrary()
{
    sort(books.begin(), books.end());
    cout << "Sort has been finished" << endl;
}

Book *Library::findByName(string name)
{
    for (auto &book : books)
    {
        if (name == book.getName())
        {
            cout << "The Book " << name << " had been found:" << endl;
            cout << book << endl;
            return &book;
        }
    }

    cout << "The Book " << name << " didn't find" << endl;
    return nullptr;
}

void Library::convertBook(string name)
{
    Book *book = findByName(name);
    if (book != nullptr)
    {
        string genre;
        cout << "Write a new Genre for the book" << endl;
        cin >> genre;
        book->changeGenre(genre);
        cout << "The genre had been changed" << endl;
    }
}

void Library::deleteBook(string name)
{
    lock_guard<mutex> lock(mut);
    Book *book = findByName(name);
    if (book != nullptr)
    {
        books.erase(std::remove(books.begin(), books.end(), *book));
        cout << "The Book had been deleted" << endl;
    }
}

void Library::writeToFile()
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

void Library::readFromFile()
{
    lock_guard<mutex> lock(mut);
    string author, name, genre;
    int pages;
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
                    author = token;
                else if (counter == 2)
                    name = token;
                else if (counter == 3)
                    pages = stoi(token);

                line.erase(0, pos + delimiter.length());
                counter++;
            }

            genre = line;
            addBook(author, name, pages, genre);
        }
        myfile.close();
        cout << "The file has been read" << endl;
    }
    else
        throw MyException("File doesn't exist");
}

Library::~Library()
{
    books.clear();
    cout << "Delete Library" << endl;
};

ostream &operator<<(ostream &out, const Library &library)
{
    for (auto i = library.books.begin(); i != library.books.end(); i++)
        out << *i << endl;

    return out;
};