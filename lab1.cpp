// lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include "dice.h"
using namespace std;


void find_possible_sums(std::vector<dice>& v, std::map<int, double>& m) {
	if (v.size() == 0) {
		return;
		
	}
	else {
		std::vector<double> elems = v[0].getProbabilities();
		std::map<int, double> m_new;
		std::pair<std::map<int, double>::iterator, bool> ret;
		if (m.empty()) {
			for (int i = 0; i < elems.size(); i++) {
				m_new.insert(std::pair<int,double>(i + 1, elems[i]));
			}
			
			for (auto i = m_new.begin(); i != m_new.end(); ++i) {
				cout << i->first << " " << i->second << endl;
			}
			cout << endl;
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
int main()
{
	vector<dice> v;
	dice d(4);
	map<int, double> m;
	for (int i = 0; i < 2; i++) {
		v.push_back(d);
	}
	find_possible_sums(v, m);
	for (auto it = m.begin(); it != m.end(); ++it) {
		cout << it->first << " " << it->second << endl;
	}
}

