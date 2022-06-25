#ifndef BOOK
#define BOOK

#include <string>
#include <iostream>

class Book {
    std::string author;
    std::string name;
    int pages;
    std::string genre = "Unknown";
    
    public:
        Book(std::string author, std::string name, int pages, std::string genre);
        Book(std::string author, std::string name, int pages);
        
        Book(const Book& p1);
        
        Book& operator=(const Book& p1);

        int getPages() const;
        
        std::string getName() const;
    
        void changeAuthor(std::string author);
        void changeGenre(std::string genre);
        
        void changePages(int pages);
        ~Book();
    
    
    friend std::ostream& operator<< (std::ostream &out, const Book &book);
    
    friend bool operator== (const Book &book1, const Book &book2);
};

bool operator<(const Book &x, const Book &y);

#endif



