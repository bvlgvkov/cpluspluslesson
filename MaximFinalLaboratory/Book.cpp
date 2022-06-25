#include "Book.h"

using namespace std;

Book::Book(string author, string name, int pages, string genre)
{
    this->author = author;
    this->name = name;
    this->pages = pages;
    this->genre = genre;
};

Book::Book(string author, string name, int pages)
{
    this->author = author;
    this->name = name;
    this->pages = pages;
};

Book::Book(const Book &p1)
{
    this->author = p1.author;
    this->name = p1.name;
    this->pages = p1.pages;
    this->genre = p1.genre;
}

Book &Book::operator=(const Book &p1)
{
    this->author = p1.author;
    this->name = p1.name;
    this->pages = p1.pages;
    this->genre = p1.genre;

    return *this;
}

int Book::getPages() const
{
    return this->pages;
}

string Book::getName() const
{
    return this->name;
}

void Book::changeAuthor(string author)
{
    this->author = author;
}

void Book::changeGenre(string genre)
{
    this->genre = genre;
}

void Book::changePages(int pages)
{
    this->pages = pages;
}

Book::~Book()
{
    cout << "Delete Book " << this->name << endl;
};

bool operator<(const Book &x, const Book &y)
{
    return x.getPages() < y.getPages();
}

ostream &operator<<(ostream &out, const Book &book)
{
    out << "Book " << book.author << " " << book.name << " " << book.pages << " " << book.genre;

    return out;
};

bool operator==(const Book &book1, const Book &book2)
{
    return ((book1.name == book2.name) && (book1.author == book2.author) &&
            (book1.pages == book2.pages) && (book1.genre == book2.genre));
};