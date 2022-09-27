#include "dice.h"
#include <map>
#include <chrono>
#include <ctime>
dice::dice()
{
	N = 0;
	vec = {};
}
dice::dice(int n, std::vector<double> v)
{
	this->N = n;
	if (v.empty()) {
		for (int i = 0; i < N; i++) {
			vec.push_back(static_cast<double>(1) / static_cast<double>(N));
		}
	}
	for (int i = 0; i < v.size(); i++) {
		vec.push_back(v[i]);
	}
}
int dice::get_N()
{
	return N;
}
std::vector<double> dice::getProbabilities()
{
	std::vector<double> v;
	for (int i = 0; i < vec.size(); i++) {
		v.push_back(vec[i]);
	}
	return v;
}



std::istream& operator>>(std::istream& is, dice& d)
{
	std::cout << "Enter number of faces" << std::endl;
	int n;
	is >> n;
	dice d_temp(n);
	d = d_temp;
	return is;
}

bool operator==( dice& d,  dice& d1)
{
	if (d.get_N() != d1.get_N()) {
		return false;
	}
	else {
		std::vector<double> v = d1.getProbabilities();
		std::vector<double> v1 = d.getProbabilities();

		for (int i = 0; i < v.size(); i++) {
			if (v[i] != v1[i]) {
				return false;
			}

		}
	}
	return true;;
}
