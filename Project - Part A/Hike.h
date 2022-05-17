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

#ifndef HIKE_H
#define HIKE_H

#include <string>

class Hike
{

	friend std::ostream& operator<<(std::ostream&, const Hike&);

public:
	// only constructors can be defined inline, others must be in .cpp
	Hike() : duration(0), difficulty('e') {}

	Hike(const std::string& aLocation, const std::string& aHike,
		int theDuration, char theDifficulty) :
		location(aLocation), hike(aHike), 
		duration(theDuration), difficulty(theDifficulty) {}
	bool operator<(const Hike& userHike) const
	{
		if (userHike.location > this->location)
		{
			return true;
		}
	}
	
	// Getters
	std::string getLocation() const;

	std::string getHike() const;

	int getDuration() const;

	char getDifficulty() const;

	// destructor
	~Hike() {};

private:
	std::string location;
	std::string hike;
	int duration; 
	char difficulty;

};
#endif



