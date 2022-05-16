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

#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include <iostream>

void displayMenu();

void processReservation(std::string& HikeList, int& MemberList, int& Reservations);

void chooseByLocation(std::string& HikeList, int& MemberList, int& Reservations);

void chooseByDuration(std::string& HikeList, int& MemberList, int& Reservations);

void chooseByDifficulty(std::string& HikeList, int& MemberList, int& Reservations);

void chooseByPrice(std::string& HikeList, int& MemberList, int& Reservations);

void askIfMember(int& MemberList);

void addNewMember(int& MemberList);

void makeReservation(std::string& HikeList, int& MemberList, int& Reservations);

void viewReservation(std::string& HikeList, int& MemberList, int& Reservations);

void cancelReservation(std::string& HikeList, int& MemberList, int& Reservations);

void askToReserve(std::string& HikeList, int& MemberList, int& Reservations);

#endif