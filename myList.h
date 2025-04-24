#ifndef MYLIST_H
#define MYLIST_H
#include <iostream>
#include <stdexcept>

template <class T>
class Mylist;

template<class T>
class Node {
    friend class Mylist<T>;         //allows mylist class to access private members
private:
    T data;
    Node<T>* next;              //pointer to next node
public:
    Node(const T& d, Node<T>* n=nullptr):data(d), next(n){}      //constructor holding d and pointing to n
};
template<class T>
class Mylist {
    Node<T>* head;
public:
    Mylist():head(nullptr){}            //constructor to initialize empty list
    ~Mylist() {                     //destructor to delete nodes
        while (head) {
            deleteHead();
        }
    }
    void insertHead(const T& thedata) {         //add a new element at front
        head=new Node<T>(thedata, head);
    }
    T deleteHead() {                //removes front node and returns its data
        if (!head)
            throw std::runtime_error("Error: list is empty.");
        Node<T>* old=head;
        T retval=head->data; //retrieval
        head=head->next;        //unlocks the node
        delete old;
        return retval;
    }
    bool search(T& target) {       //looks for target in the list
        Node<T>* current=head;
        while (current){
            if (current->data==target) {
                target=current->data;
                return true;
            }
            current=current->next;
        }
        return false;
    }
    void display() const{        //prints every element in the list
        Node<T>* current=head;
        while (current) {
            std::cout<<current->data<<std::endl;
            current=current->next;
        }
    }
};
#endif //MYLIST_H
