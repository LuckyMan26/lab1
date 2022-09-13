#include "dice.h"
#include <map>
dice::dice(int n, std::vector<double> v)
{
	this->N = n;
	if (v.empty()) {
		for (int i = 0; i < N; i++) {
			vec.push_back(static_cast<double>(1 / N));
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
void find_possible_sums(std::vector<dice> v) {
	
}

