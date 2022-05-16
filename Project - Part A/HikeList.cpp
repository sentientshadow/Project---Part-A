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
#include <map>
#include "Hikelist.h"

using namespace std;

//Adds a hike to the list from the provided Hike and Price
void HikeList::addHike(const Hike& addedHike, double hikePrice)
{
	hikeMultimap.insert(pair<Hike, double>(addedHike, hikePrice));
}


//Creates a hike adds to the list with given Price
void HikeList::addHike(const string& location, 
	const string& nameOfHike, int duration,
	char difficulty, double price)
{
	Hike newHike(location, nameOfHike, duration, difficulty);
	hikeMultimap.insert(pair<Hike, double>(newHike, price));
}


//Returns the double for the price of the requested hike
double HikeList::getPrice(const string& hikeName) const 
{
	auto requestedHike = std::find_if(hikeMultimap.begin(), hikeMultimap.end(),
		[&hikeName](pair<Hike,double> wantedHike)
		{return (wantedHike.first).getHike() == hikeName; });
	return requestedHike->second;
}

//Prints all locations in alphabetical order
void HikeList::printAllLocations() const
{
	auto iter = hikeMultimap.begin();
	int mapSize = static_cast<int>(hikeMultimap.count(iter->first));
	while (iter != hikeMultimap.end())
	{
		if ( mapSize> 1) {
			cout << "\t" << (iter->first).getLocation() << endl;
			iter = hikeMultimap.upper_bound(iter->first);
		}
		else {
			cout << "\t" << (iter->first).getLocation() << endl;
			iter++;
		}
		
	}
}

//Prints all hike in the requested location
void HikeList::printByLocation(const string& location) const
{
	auto iter = hikeMultimap.begin();
	while (iter != hikeMultimap.end()) 
	{
		auto requestedHike = std::find_if(iter, hikeMultimap.end(),
			[&location](pair<Hike, double> wantedHike)
			{return (wantedHike.first).getLocation() == location; });
		iter = requestedHike;
		if (requestedHike != hikeMultimap.end()) {
			cout << (requestedHike->first);
			cout << "\t" << "  Price (per Person): $ " << fixed << setprecision(2)
				<< this->getPrice((requestedHike->first).getHike()) << endl;
			iter = ++requestedHike;
		}
	}

	
}


//Prints all hikes in order of duration from lowest to highest
void HikeList::printByDuration() const
{
	multimap<int, string> tempMap;
	auto iterHike = hikeMultimap.begin();
	while (iterHike != hikeMultimap.end())
	{
		tempMap.insert(pair<int, string>(iterHike->first.getDuration(),
			iterHike->first.getLocation()));
		iterHike++;
	}
	for_each(tempMap.begin(), tempMap.end(), [](pair<int, string> hike)
		{cout << "\t" << "(" << hike.first << ") " << hike.second << endl; });
}

//Prints all hikes with the requested duration
void HikeList::printByDuration(int duration) const
{
	multimap<int, string> tempMap;
	auto iterHike = hikeMultimap.begin();
	while (iterHike != hikeMultimap.end()) 
	{
		if (iterHike->first.getDuration() == duration) {
			tempMap.insert(pair<int, string>(iterHike->first.getDuration(),
				iterHike->first.getLocation()));
		}
		iterHike++;
	}
	for_each(tempMap.begin(), tempMap.end(), [](pair<int, string> hike)
		{cout <<"\t" << "(" << hike.first << ") " << hike.second << endl; });
}


//Prints all hikes with the requested difficulty
void HikeList::printByDifficulty(char difficulty) const 
{
	auto iterHike = hikeMultimap.begin();
	for (int i = 0; i < static_cast<int>(hikeMultimap.size()); ++i) 
	{
		if (iterHike->first.getDifficulty() == difficulty) {
			cout << "\t" << "(" << difficulty << ") " << iterHike->first.getHike()
				<< ", " << iterHike->first.getLocation() << endl;
		}
		iterHike++;
	}
}

//Prints all hikes in order of how the are priced
void HikeList::printByPrice() const
{
	multimap<double, pair<string, string>> tempMap;

	auto iterHike = hikeMultimap.begin();
	while (iterHike != hikeMultimap.end()) 
	{
		tempMap.emplace(iterHike->second, pair<string, string>(iterHike->first.getHike(),
			(iterHike->first.getLocation())));
		iterHike++;
	}

	auto iterTemp = tempMap.begin();
	for (int i = 0; i < static_cast<int>(tempMap.size()); ++i)
	{
		cout << "\t" << "$ ";
		cout.width(8); cout << fixed << right << setprecision(2) << iterTemp->first;
		cout << " - " << iterTemp->second.first << ", ("<< iterTemp->second.second 
			<< ")" << endl;
		iterTemp++;
	}
}

//Prints all the info of the requested Hike
void HikeList::printByHikeName(const string& hikeName) const
{
	auto requestedHike = std::find_if(hikeMultimap.begin(), hikeMultimap.end(),
		[&hikeName](pair<Hike, double> wantedHike)
		{return (wantedHike.first).getHike() == hikeName; });
	cout << (requestedHike->first);
	cout << "\t" <<  "  $" << fixed << setprecision(2)
		<< this->getPrice((requestedHike->first).getHike()) << endl;
}

// Clears all entries of the list
void HikeList::clearList()
{
	hikeMultimap.erase(hikeMultimap.begin(), hikeMultimap.end());
}