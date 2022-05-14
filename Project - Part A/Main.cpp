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

#include "Hike.h"
#include "Member.h"
#include "MemberList.h"
#include "HikeList.h"
#include <iostream>

using namespace std;

int main() {
	// Test Case: Hike Output
	Hike test("Montana", "Glacier", 6, 's');
	cout << test << endl;

	// Test Case: HikeList

	// Test Case: Member
	Member mem("Grandma", "Gatewood");
	mem.setID(100);
	mem.addPoints(25876);
	mem.printMember();
	
	// Test Case: MemberList
	MemberList listMember;

	listMember.addMember("Grandma", "Gatewood", 25876);
	listMember.printMember(111, "Gatewood");


	return 0;
}
