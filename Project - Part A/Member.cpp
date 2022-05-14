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

#include "Member.h"
#include <string>
#include <iostream>
using namespace std;

void Member::setID(int id)
{
	memberId = id;
}

int Member::getID() const
{
	return memberId;
}

void Member::addPoints(int point)
{
	points += point;
}

int Member::getPoints() const
{
	return points;
}

string Member::getLastName()
{
	return lastName;
}

void Member::printMember() const
{
	cout << "\n\t" << lastName << ", " << firstName << "\n";
	cout << "\tPoints available: " << points << endl;
}