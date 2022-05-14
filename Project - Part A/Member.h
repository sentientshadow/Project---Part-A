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

#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member
{
public:
	Member() : points(0) {}
	Member(std::string firstName, std::string lastName) :
		firstName(firstName), lastName(lastName),
		memberId(0), points(0) {}
	
	//Accessor functions
	std::string getLastName();
	int getID() const;
	int getPoints() const;
	
	//funtions 
	void addPoints(int);
	void setID(int);
	void printMember() const;

private:
	int memberId; // member's ID
	int points; // member's points
	std::string firstName; //first name of member
	std::string lastName; //last name of member
};
#endif // !MEMBER_H

