#ifndef LIBRARY
#define LIBRARY

#include <vector>
#include <future>
#include "Book.h"
#include "MyException.h"

class Library {
    int amount = 0;
    bool isEmpty = true;
    int mostBiggestBook = 0;
    std::vector<Book> books;
    public: 
        Library();
        
        Library(Book book);
        
        std::vector<Book> getBooks();
        
        void setBooks(std::vector<Book> books);
        
        int getAmount() const;
        
        int getMostBiggestBook() const;
        
        void addBook(std::string author, std::string name, int pages, std::string genre);
        
        void sortLibrary();
        
        Book* findByName(std::string name);
        
        void convertBook(std::string name);
        
        void deleteBook(std::string name);
        
        void writeToFile();
        
        void readFromFile();
    
        friend std::ostream& operator<< (std::ostream &out, const Library &library);
    
        ~Library();
};

#endif