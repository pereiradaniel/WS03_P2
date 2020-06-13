// I have done all the coding by myselfand only copied the code that my professor
// provided to complete my workshopsand assignments.
//
// Name:			Daniel Pereira
// Seneca email:	dppereira@myseneca.ca
// Student ID:		037747078
// Date:  Wednesday, 10/June/2020

#ifndef SDDS_CARGO_H
#define SDDS_CARGO_H

namespace sdds
{
	const int MAX_DESC = 20;

	struct Cargo
	{
		char cargo_description[MAX_DESC + 1];  // +1 for null terminator.
		double cargo_weight;
	};
}

#endif