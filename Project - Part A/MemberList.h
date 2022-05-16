/*
    Wizards Team

    Lane, Shadow
    Delgado, Steven
    Vu, Nhi
    Lam, Dat

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/


#ifndef MEMBERLIST_H
#define MEMBERLIST_H

#include <string>
#include <iostream>
#include <set>
#include "Member.h"

using namespace std;

const int STARTING_ID = 111;

class MemberList
{

public:
    MemberList();

    void addMember(const string&, const string&);
    void addMember(const string&, const string&, const int);
    int getLastID() const;

    int getPoints(const int) const;
    void printMember(int, const string&) const;

    void clearList();


    ~MemberList();

private:

    set<Member*> listOfMember;
};
#endif
