/***********************************************************
** Author            : Nathan Philburn
** Program           : HW5
** Date Created      : 4/17/2025
** Date Last Modified: 4/24/2025
** Usage             : No command line arguments
** Problem:
** Read "presidentsWstates.txt" into Profile structs, insert
** each at head of Mylist<Profile>, display all and then search
** for a specific president from the list.
***********************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
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
    Mylist<Profile> pMylist;        //holds profile objects
    ifstream file("presidentsWstates.txt");
    if (!file) {
        cerr<<"Error: Could not open presidentsWstates.txt"<<endl;
        return 1;
    }
    string line;
    Profile temp;
    while(getline(file, line)) {            //reads each line
        stringstream ss(line);
        getline(ss, temp.fullname, '\t');
        getline(ss, temp.state, '\t');
        pMylist.insertHead(temp);
    }
    cout<<"List contents:"<<endl;       //displays all presidents
    pMylist.display();
    cout<<endl;

    temp.fullname="John F. Kennedy";
    temp.state.clear();
    if (pMylist.search(temp)) {
        cout<<"President found: "<<temp<<endl;
    }else{
        cout<<"President not found: "<<temp.fullname<<endl;
    }
    return 0;
}