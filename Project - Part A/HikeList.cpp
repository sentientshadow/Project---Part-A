/*
*	Team Wizards
*	
*	Lance, Shadow
*	Delgado, Steven
*	Vu, Nhi
*	Lam, Dat
*	
*	Spring 2022
*	CS A250 - C++ 2
*	Project: Hiking in the US
*/

#include <iostream>
#include <iomanip>
#include <map>
#include "Hikelist.h"

using namespace std;

void HikeList::addHike(const Hike& addedHike, double hikePrice)
{
	hikeMultimap.insert(pair<Hike, double>(addedHike, hikePrice));
}

void HikeList::addHike(const string& location, const string& nameOfHike, int duration,
	char difficulty, double price)
{
	Hike newHike(location, nameOfHike, duration, difficulty);
	hikeMultimap.insert(pair<Hike, double>(newHike, price));
}

double HikeList::getPrice(const string& hikeName) const 
{
	auto requestedHike = find_if(hikeMultimap.begin(), hikeMultimap.end(),
		[&hikeName](pair<Hike,double> wantedHike)
		{return (wantedHike.first).getHike() == hikeName; });
	return (*requestedHike).second;
}

void HikeList::printAllLocations() const
{
	auto it = hikeMultimap.begin();
	while (it != hikeMultimap.end()){
		if (static_cast<int>(hikeMultimap.count((*it).first)) > 1) {
			cout << "\t" << ((*it).first).getLocation() << endl;
			it = hikeMultimap.upper_bound((*(it)).first);
		}
		else {
			cout << "\t" << ((*it).first).getLocation() << endl;
			it++;
		}
		
	}
}

void HikeList::printByLocation(const string& location) const
{
	auto iter = hikeMultimap.begin();
	while (iter != hikeMultimap.end()) {
		auto requestedHike = find_if(iter, hikeMultimap.end(),
			[&location](pair<Hike, double> wantedHike)
			{return (wantedHike.first).getLocation() == location; });
		iter = requestedHike;
		if (requestedHike != hikeMultimap.end()) {
			cout << ((*requestedHike).first);
			cout << "\t" << "  Price (per Person): $ " << fixed << setprecision(2)
				<< this->getPrice(((*requestedHike).first).getHike()) << endl;
			iter = ++requestedHike;
		}
	}

	
}

void HikeList::printByDuration(int duration) const
{
	multimap<int, string> tempMap;
	auto iterHike = hikeMultimap.begin();
	while (iterHike != hikeMultimap.end()) {
		tempMap.insert(pair<int,string>((*iterHike).first.getDuration(), (*iterHike).first.getLocation()));
		iterHike++;
	}
	for_each(tempMap.begin(), tempMap.end(), [](pair<int, string> hike)
		{cout <<"\t" << "(" << hike.first << ") " << hike.second << endl; });
}

void HikeList::printByDifficulty(char difficulty) const 
{
	auto iterHike = hikeMultimap.begin();
	for (int i = 0; i < static_cast<int>(hikeMultimap.size()); ++i) {
		if ((*iterHike).first.getDifficulty() == difficulty) {
			cout << "\t" << "(" << difficulty << ") " << (*iterHike).first.getHike() << ", "
				<< (*iterHike).first.getLocation() << endl;
		}
		iterHike++;
	}
}

void HikeList::printByPrice() const
{
	multimap<double, pair<string, string>> tempMap;

	auto iterHike = hikeMultimap.begin();
	while (iterHike != hikeMultimap.end()) {
		tempMap.emplace((*iterHike).second, pair<string, string>((*iterHike).first.getHike(),
			(*iterHike).first.getLocation()));
		iterHike++;
	}

	auto iterTemp = tempMap.begin();
	for (int i = 0; i < static_cast<int>(tempMap.size()); ++i) {
		cout << "\t" << "$ ";
		cout.width(8); cout << fixed << right << setprecision(2) << (*iterTemp).first;
		cout << " - " << (*iterTemp).second.first << ", ("<< (*iterTemp).second.second 
			<< ")" << endl;
		iterTemp++;
	}
}

void HikeList::printByHikeName(const string& hikeName) const
{
	auto requestedHike = find_if(hikeMultimap.begin(), hikeMultimap.end(),
		[&hikeName](pair<Hike, double> wantedHike)
		{return (wantedHike.first).getHike() == hikeName; });
	cout << ((*requestedHike).first);
	cout << "\t" <<  "  $" << fixed << setprecision(2)
		<< this->getPrice(((*requestedHike).first).getHike()) << endl;
}

void HikeList::clearList()
{
	hikeMultimap.erase(hikeMultimap.begin(), hikeMultimap.end());
}