#ifndef CHILDRENSBOOK_HPP
#define CHILDRENSBOOK_HPP

#include "Book.hpp"


//a childrens book IS a book.
// in addition it HAS a minimum age
struct ChildrenBook : Book {

    //constructor 
    ChildrenBook();
    ChildrenBook(std::string title_, 
                std::string author_, 
                int year_, int min_age) : Book(title_,
                                               author_, 
                                               year_), 
                                          min_age(min_age) {};

    bool canRead(int year) const;
    int getAge() const;
private:
    int min_age;
};

ChildrenBook::ChildrenBook() {
    min_age = 1;
}

int ChildrenBook::getAge() const{
    return min_age;
}

bool ChildrenBook::canRead(int year) const {
    return (year >= min_age);
}

std::ostream& operator<< (std::ostream& os, ChildrenBook& b) {
    return os << static_cast<Book&>(b) << "\tMin Age: " << b.getAge() << std::endl;
}


#endif