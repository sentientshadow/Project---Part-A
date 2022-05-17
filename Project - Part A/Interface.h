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

#include "HikeList.h"
#include "MemberList.h"
#include "Reservations.h"

#include <string>
#include <iostream>

void displayMenu();

void processReservation(HikeList& hikeList, MemberList& memberList, Reservations& reservations);

void chooseByLocation(HikeList& hikeList, MemberList& memberList, Reservations& reservations);

void chooseByDuration(HikeList& hikeList, MemberList& memberList, Reservations& reservations);

void chooseByDifficulty(HikeList& hikeList, MemberList& memberList, Reservations& reservations);

void chooseByPrice(HikeList& hikeList, MemberList& memberList, Reservations& reservations);

int askIfMember(MemberList& memberList);

int addNewMember(MemberList& memberList);

void makeReservation(HikeList& hikeList, MemberList& memberList, Reservations& reservations);

void viewReservation(HikeList& hikeList, MemberList& memberList, Reservations& reservations);

void cancelReservation(HikeList& hikeList, MemberList& memberList, Reservations& reservations);

void askToReserve(HikeList& hikeList, MemberList& memberList, Reservations& reservations);

#endif