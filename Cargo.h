#ifndef SDDS_CARGO_H
#define SDDS_CARGO_H

namespace sdds
{
	const int MAX_DESC = 20;
	const double MAX_WEIGHT = 777.555;
	const double MIN_WEIGHT = 44.2222;

	class Cargo
	{
		char cargo_description[MAX_DESC + 1];  // +1 for null terminator.
		double cargo_weight;

	public:
		void initialize(const char* desc, double weight);
		const char* getDesc() const;
		double getWeight() const;
		void setDesc(const char* description);
		void setWeight(double weight);
	};
}

#endif