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

#ifndef RESERVATIONS_H
#define RESERVATIONS_H

#include <string>
#include "MemberList.h"
#include "HikeList.h"

const int RESERVATION_NUMBER = 50001;

class Node 
{
public:
	//Constructors
	Node() : reservationNumber(0), memberID(0), prev(nullptr), next(nullptr){}

	Node(int newReservation, int newMember, std::string& newHike, 
		Node* prevLink, Node* nextLink) :
		reservationNumber(newReservation), memberID(newMember),
			hikeName(newHike), prev(prevLink), next(nextLink) {}

	//Get Functions

	int getReservationNumber() const { return reservationNumber; }

	int getMemberID() const { return memberID; }

	std::string getHikeName() { return hikeName; }

	Node* getPrev() const { return prev; }

	Node* getNext() const { return next; }

	//Mutator Functions

	void setReservationNumber(int newReservNum) { reservationNumber = newReservNum; }

	void setMemberID(int newMember) { memberID = newMember; }
	
	void setName(std::string& newHike) { hikeName = newHike; }

	void setPrev(Node* prevLink) { prev = prevLink; }

	void setNext(Node* nextLink) { next = nextLink; }

	~Node(){}

private:
	int reservationNumber;
	int memberID;
	std::string hikeName;
	Node* next;
	Node* prev;
};

class Reservations
{
public:
	//Constructor to Default Values
	Reservations() : first(nullptr), last(nullptr), size(0){}

	int addReservation(int memberId, std::string& newHike);

	void cancelReservation(int reservNum);

	void printReservation(int reservNum, HikeList& listOfHikes,
		MemberList& listOfMembers);

	void clearList();

	~Reservations();
private:

	Node* findReservation(int reservNum);
	
	Node* first;
	Node* last;
	int size;
};

#endif