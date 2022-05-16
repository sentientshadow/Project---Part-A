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

#ifndef HikeList_H
#define HikeList_H

#include <iostream>
#include <map>
#include <algorithm>
#include "Hike.h"

class HikeList 
{
public:
	//Constructor
	HikeList(){};

	//Mutator Functions
	void addHike(const Hike& addedHike, double hikePrice);
	void addHike(const std::string& location, const std::string& nameOfHike,
		int duration, char difficulty, double price);
	
	// Access Function
	double getPrice(const std::string& hikeName) const;

	//Print Functions
	void printAllLocations() const;
	
	void printByLocation(const std::string& location) const;

	void printByDuration() const;

	void printByDuration(int duration) const;

	void printByDifficulty(char difficulty) const;

	void printByPrice() const;

	void printByHikeName(const std::string& hikeName) const;

	void clearList();

private:
	std::multimap<Hike, double> hikeMultimap;
};

#endif HikeList_H