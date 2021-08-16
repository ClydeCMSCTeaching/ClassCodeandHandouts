#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Book.hpp"
#include "ChildrensBook.hpp"
#include "sllist.hpp"

void bookExample() {
    Book b1 = Book("the title2", "author", 1923);
    Book b2 = Book("the title1", "author", 1923);


    std::vector<Book> mybooks;
    mybooks.push_back(b1);
    mybooks.push_back(b2);

    for (auto& item: mybooks) {
        std::cout << item;
    }

    std::sort(mybooks.begin(), mybooks.end());

    for (auto& item: mybooks) {
        std::cout << item;
    }
}

void ChildrensBookExample() {
    ChildrenBook b = ChildrenBook("hello", "dan", 1923, 5);
    Book b1 = Book("hello", "dan", 1923);

    std::cout << b;
    std::cout << b1;

}


void llistExample() {
    sllist_node<ChildrenBook> node;

    ChildrenBook b1 = ChildrenBook("dan's other book", "dan", 1923, 5);
    ChildrenBook b2 = ChildrenBook("hello", "dan", 1923, 5);


    node.myitem = b1;
    node.append(b2);

    std::cout << "first: " << node.myitem << "\n next is: " << node.next->myitem;
    
}


int main() {
    // ChildrensBookExample();


    llistExample();
}