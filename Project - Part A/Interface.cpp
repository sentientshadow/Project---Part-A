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


#include <iostream>
#include <iomanip>
#include <string>
#include "Interface.h"


using namespace std;

void displayMenu()
{
	cout << string(51, '*')
		<< "\n\t\tHIKING IN THE US\n"
		<< string(51, '*')
		<< "\n\n\t1. Browse by Location\n"
		<< "\t2. Browse by duration\n"
		<< "\t3. Browse by difficulty\n"
		<< "\t4. Browse by price\n"
		<< "\t5. Make a reservation\n"
		<< "\t6. View reservation\n"
		<< "\t7. Cancel reservation\n"
		<< "\t8. Exit\n" << endl;
}

void processReservation(HikeList& hikeList, MemberList& memberList, Reservations& reservations)
{
	string userInput;

	while (userInput != "8")
	{
		cout << "Please make a selection: ";
		cin >> userInput;
		cout << "\n";

		if (userInput == "1")
		{
			chooseByLocation(hikeList, memberList, reservations);
			system("Pause");
			displayMenu();
		}
		else if (userInput == "2")
		{
			chooseByDuration(hikeList, memberList, reservations);
			system("Pause");
			displayMenu();
		}
		else if (userInput == "3")
		{
			chooseByDifficulty(hikeList, memberList, reservations);
			system("Pause");
			displayMenu();
		}
		else if (userInput == "4")
		{
			chooseByPrice(hikeList, memberList, reservations);
			system("Pause");
			displayMenu();
		}
		else if (userInput == "5")
		{
			makeReservation(hikeList, memberList, reservations);
			system("Pause");
			displayMenu();
		}
		else if (userInput == "6")
		{
			viewReservation(hikeList, memberList, reservations);
			system("Pause");
			displayMenu();
		}
		else if (userInput == "7")
		{
			cancelReservation(hikeList, memberList, reservations);
			system("Pause");
			displayMenu();
		}

		else if (userInput == "8")
		{
			cout << "Thank you for visiting!\n";
		}
	}
}

void chooseByLocation(HikeList& hikeList, MemberList& memberList, Reservations& reservations)
{
	hikeList.printAllLocations();
	cout << "\nChoose a location: ";
	string userLocation;
	cin >> userLocation;
	cout << "\n";
	hikeList.printByLocation(userLocation);

	askToReserve(hikeList, memberList, reservations);
}

void chooseByDuration(HikeList& hikeList, MemberList& memberList, Reservations& reservations)
{
	cout << "\t(days)\n";
	hikeList.printByDuration();
	cout << "\nHow many days are you considering? ";
	int userDays = 0;
	cin >> userDays;
	cout << "\n";
	hikeList.printByDuration(userDays);
	cout << "\n";
	askToReserve(hikeList, memberList, reservations);
}

void chooseByDifficulty(HikeList& hikeList, MemberList& memberList, Reservations& reservations)
{
	cout << "Choose difficulty level:\n\n"
	<< "\te. easy\n"
	<< "\tm. moderate\n"
	<< "\ts. strenuous\n\n"
	<< "Your choice: ";
	char userDifficulty = 'e';
	cin >> userDifficulty;

	cout << "\n\t(difficulty level)\n";
	hikeList.printByDifficulty(userDifficulty);
	cout << "\n";

	askToReserve(hikeList, memberList, reservations);
}

void chooseByPrice(HikeList& hikeList, MemberList& memberList, Reservations& reservations)
{
	hikeList.printByPrice();
	cout << "\n";
	askToReserve(hikeList, memberList, reservations);
}


void askToReserve(HikeList& hikeList, MemberList& memberList, Reservations& reservations)
{
	cout << "Would you like to make a reservation? (y/n) ";
	string userReservation;
	cin >> userReservation;
	cout << "\n";

	if (userReservation == "y")
	{
		makeReservation(hikeList, memberList, reservations);
	}
}

void makeReservation(HikeList& hikeList, MemberList& memberList, Reservations& reservations)
{
	int memberID = askIfMember(memberList);
	cout << "\nWhich hike would you like to reserve? ";
	string hikeName;
	cin >> hikeName;
	cout << "\n";

	hikeList.printByHikeName(hikeName);
	cout << setprecision(2)
		<< "\n\tDiscounted Price using points: $"
		<< hikeList.getPrice(hikeName) - (memberList.getPoints(memberID) / 100)
		<< "\n\n\tBefore proceeding, please make a note of your reservation number."
		<< "\n\t  Reservation #: "
		<< reservations.addReservation(memberID, hikeName) // returns reservation number
		<< "\n\n( *** Will continue to scheduling and payment. *** )\n\n";
}

void viewReservation(HikeList& hikeList, MemberList& memberList, Reservations& reservations)
{
	cout << "\nEnter reservation #: ";
	int userReserveNum = 0;
	cin >> userReserveNum;
	reservations.printReservation(userReserveNum, hikeList, memberList);
	cout << "\n";
}

void cancelReservation(HikeList& hikeList, MemberList& memberList, Reservations& reservations)
{
	cout << "Enter a reservation #: ";
	int userReserveNum = 0;
	cin >> userReserveNum;
	cout << "\n";
	reservations.printReservation(userReserveNum, hikeList, memberList);
	cout << "\n\nAre you sure you want to cancel this reservation? (y/n) ";
	char userConfirm = 'n';
	cin >> userConfirm;

	if (userConfirm == 'y')
	{
		cout << "\nReservation " << userReserveNum << " has been cancelled.\n";
		reservations.cancelReservation(userReserveNum);
	}
}

int askIfMember(MemberList& memberList)
{
	cout << "Are you a member? (y/n) ";
	string userIsMember;
	cin >> userIsMember;
	cout << "\n";
	int memberID = 0;
	
	if (userIsMember == "y")
	{
		cout << "What is your member ID number? ";
		cin >> memberID;
		cout << "\nWhat is your last name? ";
		string lastName;
		cin >> lastName;
		memberList.printMember(memberID, lastName);
	}
	else
	{
		addNewMember(memberList);
		memberID = memberList.getLastID();
	}
	return memberID;
}

int addNewMember(MemberList& memberList)
{
	cout << "\tLet's add you to the member list!\n"
		<< "\t\tWhat is your first name? ";
	string firstName;
	cin >> firstName;
	cout << "\t\tWhat is your last name? ";
	string lastName;
	cin >> lastName;

	memberList.addMember(firstName, lastName);
	cout << "\n\tWelcome to the club!"
		<< "\n\t\tYour member ID number is: "
		<< memberList.getLastID()
		<< "\n";

	return memberList.getLastID();
}