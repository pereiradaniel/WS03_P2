// I have done all the coding by myselfand only copied the code that my professor
// provided to complete my workshopsand assignments.
//
// Name:			Daniel Pereira
// Seneca email:	dppereira@myseneca.ca
// Student ID:		037747078
// Date:  Wednesday, 10/June/2020

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
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
		strcpy(cargo_unit->cargo_description, car.cargo_description);
		cargo_unit->cargo_weight = car.cargo_weight;
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
				cout << "Cargo: " << cargo_unit->cargo_description << endl << "Weight: " << cargo_unit->cargo_weight << endl;
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
}
