#pragma once
#include <vector> 
#include<map>

class dice
{
private:
	int N;
	std::vector<double> vec;
	
public:
	dice(int n, std::vector<double> v={});
	int get_N();
	std::vector<double> getProbabilities();

};

