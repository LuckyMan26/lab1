#pragma once
#include "dice.h"
class DiceSet
{
private: 
	int size;
	std::vector<dice> v;
	std::map<int, double> sumProbability;
	void find_possible_sums(std::vector<dice>& v, std::map<int, double>& m);
public:
	DiceSet(int s);
	DiceSet(std::vector<dice> vec);
	std::vector<dice> getSet();
	void getSumProbability();
	friend std::ostream& operator << (std::ostream & os, DiceSet & s);

};

