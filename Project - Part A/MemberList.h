#ifndef MEMBERLIST_H
#define MEMBERLIST_H

#include <string>
#include <iostream>
#include <set>
#include <algorithm>
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
    std::set<Member> listOfMember;
};
#endif
