// lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include <vector>
#include "dice.h"
#include "DiceSet.h"
#include "Node.h"
#include "Graph.h"
using namespace std;




int main()
{
	DiceSet s(3);
	DiceSet s1(2);
	cout << s;
	cout << endl;
	cout << s1;
	cout << (s < s1) << endl;
	std::vector<Node<int>*> v;
	for (int i = 0; i < 6; i++) {
		Node<int>* node=new Node<int>(i);
		v.push_back(node);
	}
	for (int i = 0; i < 6; i++) {
		cout << v[i]->getData() << std::endl;
	}
	Graph<int> g(v);
	g.add_edge(0, 1);
	g.add_edge(0, 2);
	g.add_edge(2, 3);
	g.add_edge(3, 5);
	cout << g;
	g.delete_edge(0, 1);
	cout << g;
}

