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
	{
		memberInserted->setID(STARTING_ID);
	}
	else
	{
		memberInserted->setID(STARTING_ID + listOfMember.size());
	}
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
	auto iterLastID = listOfMember.end();
	iterLastID--;
	return (*iterLastID)->getID();
}


void MemberList::printMember(const int myID, const string& myLastName) const
{
	set<Member*>::iterator it = listOfMember.begin();
	set<Member*>::iterator itEnd = listOfMember.end();
	auto searchID = find_if(it, itEnd, [=](Member* m)
		{
			return (m->getID() == myID && m->getLastName() == myLastName);
		});
	if (searchID != itEnd)
	{
		(*searchID)->printMember();
		cout << "\tMembership # " << (*searchID)->getID() << endl;
	}
}

int MemberList::getPoints(const int myID) const
{
	set<Member*>::iterator iterSearchID = listOfMember.begin();
	set<Member*>::iterator iterEnd = listOfMember.end();
	auto seachPoints = find_if(iterSearchID, iterEnd, [=](Member* m)
		{
			return (m->getID() == myID);
		});
	return (*seachPoints)->getPoints();
}

void MemberList::clearList()
{
	listOfMember.clear();
}

MemberList::~MemberList()
{
	clearList();
}
