#include "MemberList.h"

MemberList::MemberList()
{
	set<Member> mymember;
}

void MemberList::addMember(const string& firstName, const string& lastName)
{
	Member memberInserted(firstName, lastName);	
	if (listOfMember.size() == 0)	
		memberInserted.setID(STARTING_ID);
	else			
		memberInserted.setID(getLastID() + 1);	
	listOfMember.insert(memberInserted);
}

void MemberList::addMember(const string& firstName, const string& lastName, const int points)
{
	Member memberInserted(firstName, lastName);
	memberInserted.addPoints(points);
	if (listOfMember.size() == 0)
		memberInserted.setID(STARTING_ID);
	else
		memberInserted.setID(getLastID() + 1);
	listOfMember.insert(memberInserted);

}

int MemberList::getLastID() const
{
	set<Member>::iterator it;
	it = prev(listOfMember.end());
	Member b = *it;
	return b.getID();
}


int MemberList::getPoints(const int myID) const
{
	const auto id = myID;
	set<Member>::iterator it = std::find_if(listOfMember.begin(), listOfMember.end(), [=](Member& m) {return m.getID() == id; });

	Member b = *it;
	
	return b.getPoints();
}


void MemberList::printMember(const int myID, const string& myLastName) const
{
	const auto id = myID;
	const auto lastname = myLastName;
	set<Member>::iterator it = std::find_if(listOfMember.begin(), listOfMember.end(), [=](Member& m) 
		{return m.getID() == id && m.getLastName() == lastname; });

	Member b = *it;

	printMember();
	cout << "Points available: " << b.getPoints();
	cout << "Membership # " << b.getID();


}

MemberList::~MemberList() {}