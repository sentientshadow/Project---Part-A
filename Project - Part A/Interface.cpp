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
		<< "\t8. Exit\n";
}