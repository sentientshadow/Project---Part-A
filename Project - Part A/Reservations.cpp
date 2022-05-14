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
#include <algorithm>
#include <iomanip>
#include "Reservations.h"

int Reservations::addReservation(int memberId, std::string hikeName)
{
	if (size == 0) {
		first = new Node(RESERVATION_NUMBER, memberId, hikeName, nullptr, last);
		last = first;
		size++;
	}
	else {
		last->setNext(new Node(RESERVATION_NUMBER, memberId,
			hikeName, last, nullptr));
		last = last->getNext();
		size++;
	}
	return RESERVATION_NUMBER;
}

 void Reservations::cancelReservation(int reservNumb) 
{
	 if (size == 0) {
		 delete first;
		 first = nullptr;
		 last = nullptr;
		 size--;
	}
	 else {
		 auto canceledRes = findReservation(reservNumb);
		 canceledRes->getPrev()->setNext(canceledRes->getNext());
		 canceledRes->getNext()->setPrev(canceledRes->getPrev());
		 delete canceledRes;
		 canceledRes = nullptr;
		 size--;
	 }
}

void Reservations::printReservation(int reservNumb, HikeList listOfHikes,
	MemberList listOfMembers)
{
	auto iterRes = findReservation(reservNumb);
	listOfHikes.printByHikeName(iterRes->getHikeName());

	int membPoints = listOfMembers.getPoints(iterRes->getMemberID());
	double hikePrice = listOfHikes.getPrice(iterRes->getHikeName());
	cout <<  "\n" << "\t" << "Discounted price using points : " << fixed <<
		setprecision(2) << (hikePrice - (membPoints / 100));

}

void Reservations::clearList()
{
	auto iterList = first;
	while (first != nullptr) 
	{
		first = first->getNext();
		delete iterList;
		iterList = first;
	}
	size = 0;
	last = nullptr;
}

Node* Reservations::findReservation(int reservNumb)
{
	auto iter = first;
	auto reservIter = ++last;
	while (iter != last) 
	{
		if (iter->getReservationNumber() == reservNumb) {
			reservIter = iter;
		}
		iter++;
	}
	return reservIter;
}

Reservations::~Reservations() {
	clearList();
}