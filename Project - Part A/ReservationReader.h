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

#include "Reservations.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string RESERVATION_FILE = "reservations_database.txt";

void createHikeList(ifstream& infile, Reservations& reservationList)
{
	int memberId = 0;
	string newHike;

	while (!infile.eof())
	{
		infile >> memberId >> newHike;
		reservationList.addReservation(memberId, newHike);
	}
}

void getHikeData(Reservations& reservationList)
{
	ifstream infile;

	infile.open(RESERVATION_FILE);

	if (!infile)
	{
		cerr << RESERVATION_FILE << " does not exist." << endl;
		exit(1); // terminates program
	}

	createHikeList(infile, reservationList);

	infile.close();
}
