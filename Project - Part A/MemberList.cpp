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


#include "MemberList.h"
#include "Member.h"

MemberList::MemberList()
{

	set<Member*> listOfMember;
}

void MemberList::addMember(const string& firstName, const string& lastName)
{	
	Member* memberInserted = new Member(firstName, lastName);
		
	if (listOfMember.size() == 0)
		memberInserted->setID(STARTING_ID);
	else
		memberInserted->setID(getLastID() + 1);
	

	listOfMember.insert(memberInserted);
}


void MemberList::addMember(const string& firstName, const string& lastName, const int points)
{
	Member* memberInserted = new Member(firstName, lastName);
	memberInserted->addPoints(points);

	if (listOfMember.size() == 0)
	{
		memberInserted->setID(STARTING_ID);
	}
	else
	{
		memberInserted->setID(listOfMember.size() + STARTING_ID);
	}
		
	listOfMember.insert(memberInserted);
}

int MemberList::getLastID() const
{		
	auto it = listOfMember.end();
	--it;
	Member* b = *it;

	return b->getID();
}

void MemberList::printMember(const int myID, const string& myLastName) const
{

	set<Member*>::iterator it = std::find_if(listOfMember.begin(), listOfMember.end(), [=](Member* m)
		{
			return m->getID() == myID && m->getLastName() == myLastName; 
		});
	if (it != listOfMember.end())
	{
		Member* b = *it;
		b->printMember(); 
		cout << "\tMembership # " << b->getID() << endl;
	}
	
}

int MemberList::getPoints(const int myID) const
{
	const auto id = myID;
	set<Member*>::iterator it = std::find_if(listOfMember.begin(), listOfMember.end(), [=](Member* m) 
		{
			return m->getID() == id; 
		});

	Member* b = *it;

	return b->getPoints();
}

void MemberList::clearList()
{
	listOfMember.clear();
}

MemberList::~MemberList()
{
	clearList();
}

