/*************************************************************************
** Author            : Nathan Philburn
** Program           : Linked List Implementation
** Date Created      : 4/17/2025
** Date Last Modified: 4/17/2025
** Usage             : No command line arguments
** Problem:
** Develop a MyList template class that utilizes the provided Node class from listtools.h.
** The MyList class, which contains only a Node<T>* head, must implement:
**   - insertHead(T theData)
**   - deleteHead() which returns the stored data element.
**   - search(T &target) to check if an element exists.
**   - display() to output all elements.
**
** The main function uses a Profile struct, overloads operators ==, !=, and <<,
** and reads input from "presidentsWstates.txt" to populate the list.
*************************************************************************/
#include <iostream>
#include "myList.h"
using namespace std;

struct Profile
{
    string fullname;
    string state;
    bool operator==( Profile rhs)
    {if (fullname==rhs.fullname) return true; return false; }
    bool operator!=(Profile rhs)
    {if (fullname!=rhs.fullname) return true; return false; }
};
ostream& operator<< (ostream &out, Profile &user)
{
    out << user.fullname<<"--" <<user.state;
    return out;
};
int main() {
    return 0;
}