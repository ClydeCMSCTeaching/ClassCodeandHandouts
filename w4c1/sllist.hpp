#ifndef SLLIST_HPP
#define SLLIST_HPP



template<typename T>
struct sllist_node {
    sllist_node* next;
    T myitem;

    sllist_node();
    ///append
    void append(T item);
};

template<typename T>
sllist_node<T>::sllist_node() {
    next = nullptr;
}

template<typename T>
void sllist_node<T>::append(T item) {
    sllist_node<T> *new_node = new sllist_node<T>;
    new_node->myitem = item;
    sllist_node<T> *pos = this;

    while(pos->next != NULL) {
        pos = pos->next;
    }

    pos->next = new_node;
}




#endif