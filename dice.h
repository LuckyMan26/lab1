#pragma once
#include <vector> 
#include<map>
#include <iostream>
class dice
{
private:
	int N;
	std::vector<double> vec;
	
public:
	dice();
	dice(int n, std::vector<double> v={});
	int get_N();
	std::vector<double> getProbabilities();
	friend std::istream& operator >> (std::istream& is, dice& d);
};

