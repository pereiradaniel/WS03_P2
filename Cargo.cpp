#define _CRT_SECURE_NO_WARNINGS
#include "Cargo.h"
#include <cstring>

using namespace std;

namespace sdds
{
	void Cargo::initialize(const char* desc, double weight)
	{
		setDesc(desc);
		setWeight(weight);
	}

	
	const char* Cargo::getDesc() const
	{
		return cargo_description;
	};


	double Cargo::getWeight() const
	{	
		return cargo_weight;
	};

	
	void Cargo::setDesc(const char* description)
	{
		// a modifier that sets the description of the cargo. If the string is longer than MAX_DESC, accept only MAX_DESC characters.
		strcpy((*this).cargo_description, description);
	};


	void Cargo::setWeight(double weight)
	{
		(*this).cargo_weight = weight;
	};

}