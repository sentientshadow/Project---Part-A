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

#include "Hike.h"
#include <string>
#include <iostream>



std::ostream& operator<<(std::ostream& out, const Hike& obj)
{
	// output
	out << "\t" << obj.hike << " (" << obj.location << ")" << "\n\t  Difficulty: ";

	// convert char obj.difficulty to string
	if (obj.difficulty == 'e')
	{
		out << "easy";
	}
	else if (obj.difficulty == 'm')
	{
		out << "moderate";
	}
	else
	{
		out << "strenuous";
	}

	// finish output
	out << "\n\t  Duration: " << obj.duration << " day(s)" << std::endl;
	return out;
}

	
std::string Hike::getLocation() const
{
	return location;
}

std::string Hike::getHike() const
{
	return hike;
}

int Hike::getDuration() const
{
	return duration;
}

char Hike::getDifficulty() const
{
	return difficulty;
}

