// I have done all the coding by myselfand only copied the code that my professor
// provided to complete my workshopsand assignments.
//
// Name:			Daniel Pereira
// Seneca email:	dppereira@myseneca.ca
// Student ID:		037747078
// Date:  Wednesday, 10/June/2020

#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H
#include "Cargo.h"

namespace sdds
{
	const int MAX_NAME = 30;

	class Train
	{
		private:
			char train_name[MAX_NAME + 1];
			int train_id;
			Cargo* cargo_unit;

		public:
			void initialize(const char*, int id);
			bool isValid() const;
			void display() const;
			void loadCargo(Cargo);
			void unloadCargo();
			bool swapCargo(Train& other);
			bool increaseCargo(double weight);
			bool decreaseCargo(double weight);
	};
}

#endif