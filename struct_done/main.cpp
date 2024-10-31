#include <iostream>
#include <string>
#include "Logger.h"

using namespace std;

class Book {
private:
    string title;
    string author;
    int pages;

public:

    Book() : title("Untitled"), author("Unknown"), pages(0) {
        Logger::info("Default constructor called");
    }

   
    Book(string t, string a, int p) : title(t), author(a), pages(p) {
        Logger::info("Parameterized constructor called for Book: " + title);
    }

  
    ~Book() {
        Logger::info("Destructor called for Book: " + title);
    }

    void setTitle(const string& t) {
        title = t;
        Logger::info("Title set to " + title);
    }

    void setAuthor(const string& a) {
        author = a;
        Logger::info("Author set to " + author);
    }

    void setPages(int p) {
        pages = p;
        Logger::info("Pages set to " + to_string(pages));
    }


    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    int getPages() const {
        return pages;
    }

  
    bool isLong() const {
        return pages > 300;
    }

   
    void displayInfo() const {
        cout << "Title: " << title << ", Author: " << author << ", Pages: " << pages << endl;
    }
};

int main() {
  
    Book book1;
    book1.displayInfo();

   
    Book book2("The Great Gatsby", "F. Scott Fitzgerald", 218);
    book2.displayInfo();

  
    book1.setTitle("1984");
    book1.setAuthor("George Orwell");
    book1.setPages(328);
    book1.displayInfo();

   
    if (book1.isLong()) {
        cout << book1.getTitle() << " is a long book." << endl;
    }
    else {
        cout << book1.getTitle() << " is not a long book." << endl;
    }

    
    return 0;
}
