#include "DiceSet.h"

void DiceSet::find_possible_sums(std::vector<dice>& v, std::map<int, double>& m)
{
	
		if (v.size() == 0) {
			return;

		}
		else {
			std::vector<double> elems = v[0].getProbabilities();
			std::map<int, double> m_new;
			std::pair<std::map<int, double>::iterator, bool> ret;
			if (m.empty()) {
				for (int i = 0; i < elems.size(); i++) {
					m_new.insert(std::pair<int, double>(i + 1, elems[i]));
				}

				
				std::cout << std::endl;
			}
			else {
				for (auto it = m.begin(); it != m.end(); ++it) {
					for (int j = 0; j < elems.size(); j++) {
						ret = m_new.insert(std::pair<int, double>((it->first + j + 1), it->second * elems[j]));
						if (ret.second == false) {
							ret.first->second += it->second * elems[j];
						}
					}
				}
			}
			v.erase(v.begin());
			m = m_new;
			m_new.clear();
			find_possible_sums(v, m);
		}


}

DiceSet::DiceSet(int s)
{
    dice d;
    for (int i = 0; i < s; i++) {

        std::cin >> d;
        v.push_back(d);
    }
    this->size = s;
	
}

DiceSet::DiceSet(std::vector<dice> vec)
{
    v = vec;
    this->size = vec.size();
}

std::vector<dice> DiceSet::getSet()
{
    std::vector<dice> res;
    for (int i = 0; i < res.size(); i++) {
        res.push_back(v[i]);
    }
    return res;
}

void DiceSet::getSumProbability()
{
	std::vector<double> vec;
	
	find_possible_sums(v, sumProbability);
	
}

std::ostream& operator<<(std::ostream& os, DiceSet& s)
{
	for (auto it = s.sumProbability.begin(); it != s.sumProbability.end(); ++it) {
		os << it->first << " " << it->second << std::endl;
	}
	return os;
}
