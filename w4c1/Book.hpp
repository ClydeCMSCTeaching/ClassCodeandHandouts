#ifndef POINT_H
#define POINT_H

struct Book {
    // Constructor
    Book();
    Book(std::string title_, std::string author_, int year_);

    //getters
    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;

    //setter
    void setTitle(std::string title);

private:
    // data of the struct
    std::string title;
    std::string author;
    int year;
};

void Book::setTitle(std::string title) {
    this->title = title;
}

Book::Book() {
    title = "";
    author = "";
    year = 0;
}

Book::Book(std::string title_, std::string author_, int year_) {
    title = title_;
    author = author_;
    year = year_;
}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

int Book::getYear() const {
    return year;
}

std::ostream& operator<< (std::ostream& os, Book& b) {
    return os << "BOOK:" << "\n\t TITLE: " << b.getTitle()
               << "\n\tAuthor: " << b.getAuthor() << std::endl;
}

bool operator==(const Book& b1, const Book& b2 ) {
    return b1.getTitle() == b2.getTitle() and 
           b1.getAuthor() == b2.getAuthor() and 
           b1.getYear() == b2.getYear();
}

bool operator<(const Book& b1, const Book& b2) {
    if (b1.getAuthor() != b2.getAuthor()) {
        return b1.getAuthor() < b2.getAuthor();
    } else if (b1.getTitle() != b2.getTitle()) {
        return b1.getTitle() < b2.getTitle();
    } else {
        return b1.getYear() < b2.getYear();
    }
}

#endif