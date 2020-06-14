#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Train.h"

using namespace std;

namespace sdds
{
	void Train::initialize(const char* name, int id)
	{
		// Detect if train has default values:
		if (name == nullptr || id < 1 || name[0] == '\0')
		{
			// If not default values, then set:
			train_name[0] = '\0';
			train_id = 0;
		}
		else
		{
			// If train has default values:
			strcpy(train_name, name);
			train_id = id;
		}
		// Set cargo_unit to nullptr:
		cargo_unit = nullptr;
	}

	
	bool Train::isValid() const
	{
		// Set bool to true by default:
		bool valid = true;
		
		// Detect if train is invalid:
		if (train_name[0] == '\0' || train_id < 1)
		{
			// If train is invalid, set bool value to false:
			valid = false;
		}
		// Return bool value:
		return valid;
	}

	
	void Train::loadCargo(Cargo car)
	{
		// Detect if cargo exists:
		if (cargo_unit != nullptr)
		{
			// If cargo exists, delete before loading next cargo:
			delete cargo_unit;
			cargo_unit = nullptr;
		}

		// Load new cargo:
		cargo_unit = new Cargo;	// Set this.cargo_unit to the new Cargo.
		this->cargo_unit->setDesc(car.getDesc());
		this->cargo_unit->setWeight(car.getWeight());

		// strcpy(cargo_unit->cargo_description, car.cargo_description);
		// cargo_unit->cargo_weight = car.cargo_weight;
	}


	void Train::unloadCargo()
	{
		// Detect if cargo exists:
		if (cargo_unit != nullptr)
		{
			// If cargo exists, delete:
			delete cargo_unit;
			cargo_unit = nullptr;
		}
	}

	
	void Train::display() const
	{
		cout << "***Train Summary***" << endl;
	
		// Detect if train is valid:
		if (isValid())
		{
			// If valid, print output:
			cout << "Name: " << train_name << endl << "ID: " << train_id << endl;
		
			// Detect if train has cargo:
			if (cargo_unit)
			{
				// If cargo exists, print output:
				cout << fixed << setprecision(2);
				cout << "Cargo: " << cargo_unit->getDesc() <<
				endl << "Weight: " << cargo_unit->getWeight() << endl;
			}
			else
			{
				// If train has no cargo, print message:
				cout << "No cargo on this train." << endl;
			}
		}
		else
		{
			// If train is invalid print message:
			cout << "This is an invalid train." << endl;
		}
	}

	
	bool Train::swapCargo(Train& other)
	{
		bool swapped = false;
		if (cargo_unit == nullptr || other.cargo_unit == nullptr)
		{
			swapped = false;
		}
		else
		{
			Cargo* temporary_cargo = cargo_unit;
			cargo_unit = other.cargo_unit;
			other.cargo_unit = temporary_cargo;
			swapped = true;
		}
		return swapped;
	};
	
	bool Train::increaseCargo(double weight)
	{
		bool increased = false;
		
		// Detect if valid cargo_unit or if already at MAX_WEIGHT:
		if (cargo_unit == nullptr || cargo_unit->getWeight() == MAX_WEIGHT)
		{
			// Cannot increaseCargo:
			increased = false;
		}
		else
		{
			// Detect if the new cargo will exceed MAX_WEIGHT:
			if (cargo_unit->getWeight() + weight > MAX_WEIGHT)
			{
				cargo_unit->setWeight(MAX_WEIGHT);
			}
			else
			{
				// Add the new cargo full weight if it does not exceed the MAX:
				cargo_unit->setWeight(cargo_unit->getWeight() + weight);
			}
			increased = true;
		}
		return increased;
	};


	bool Train::decreaseCargo(double weight)
	{
		bool decreased = false;

		// Detect if valid cargo_unit or if already at MIN_WEIGHT:
		if (cargo_unit == nullptr || cargo_unit->getWeight() == MIN_WEIGHT)
		{
			decreased = false;
		}
		else
		{
			// If enough cargo is removed to reach MIN_WEIGHT:
			if (cargo_unit->getWeight() - weight < MIN_WEIGHT)
			{
				cargo_unit->setWeight(MIN_WEIGHT);
			}
			else
			{
				// If removal of weight doesn't reach MIN_WEIGHT:
				cargo_unit->setWeight(cargo_unit->getWeight() - weight);
			}
			decreased = true;
		}
		return decreased;
	};
}
