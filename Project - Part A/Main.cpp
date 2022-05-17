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
#include "HikeReader.h"
#include "ReservationReader.h"
#include "MemberReader.h"
#include "Interface.h"
#include "Reservations.h"
#include <iostream>

using namespace std;

int main() 
{
	/*Test Case : Hike Output
	Hike test("Montana", "Glacier", 6, 's');
	cout << test << endl;


	// Test Case: Member
	Member mem("Grandma", "Gatewood");
	mem.setID(100);
	mem.addPoints(25876);
	mem.printMember();
	
	// Test Case: MemberList
	MemberList listMember;

	listMember.addMember("Grandma", "Gatewood", 25876);
	listMember.printMember(111, "Gatewood");
	*/
	HikeList mainHikeList = HikeList();
	getHikeData(mainHikeList);
	MemberList mainMemberList = MemberList();
	getMemberData(mainMemberList);
	Reservations mainReservations = Reservations();
	
	/*
	mainHikeList.printAllLocations();
	cout << "\n";
	mainHikeList.printByDifficulty('e');
	cout << "\n";
	mainHikeList.printByDuration(2);
	cout << "\n";
	mainHikeList.printByLocation("California");
	cout << "\n";
	mainHikeList.printByPrice();
	cout << "\n";
	mainHikeList.printByHikeName("Yosemite");
	*/

	displayMenu();
	processReservation(mainHikeList, mainMemberList, mainReservations);

	return 0;
}
