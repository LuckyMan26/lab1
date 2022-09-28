// lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


#include <iostream>
#include <map>
#include <vector>
#include "dice.h"
#include "DiceSet.h"
#include "Node.h"
#include "Graph.h"
#include "Algorrithm.h"
#include "Tree.h"
#include <typeinfo>

using namespace std;

int main(int argc,char** argv)
{
	std::vector<double>  v;

	std::vector<double>  v1;

	std::vector<double>  v2;
	for (int i = 0; i < 5; i++) {
		v.push_back(0.2);
	}
	dice d(5, v);
	for (int i = 0; i < 2; i++) {
		v1.push_back(0.5);
	}
	for (int i = 0; i < 4; i++) {
		v2.push_back(0.25);
	}
	dice d1(2, v1);
	dice d2(4, v2);
	std::vector<dice> vec;
	vec.push_back(d);
	vec.push_back(d1);
	DiceSet s1(vec);
	vec.push_back(d2);
	DiceSet s2(vec);
	map<int, double> m{ {2,0.1},{3,0.2},{4,0.2},{5,0.2},{6,0.2},{7,0.1} };;
	cout <<(s1<s2) << endl;
	/*Node<int>* node = new Node<int>(0);
	Node<int>* node1= new Node<int>(1);
	Node<int>* node2= new Node<int>(2);
	Node<int>* node3= new Node<int>(3);
	Node<int>* node4= new Node<int>(4);
	Graph<int> g;
	
	g.addVertice(node);
	g.addVertice(node1);
	g.addVertice(node2);
	g.addVertice(node3);
	g.addVertice(node4);
	
	cout << g << endl;

	g.addEdge(0, 1);
	g.addEdge(2, 3);
	g.addEdge(1, 3);

	cout << g << endl;
	cout << g.isAcyclic() << endl;
	g.addEdge(0, 3);
	g.addEdge(4, 3);
	g.addEdge(6, 3);
	cout << g << endl;
	cout << g.isAcyclic() << endl;
	Graph<int> g1;
	Algorithm<int> alg;
	g1 = alg.Kruskal(g);
	cout << "Kruskal: " << endl;
	cout << g1 << endl;

	Tree<int> tree;
	tree.add(2);
	tree.add(3);
	tree.add(4);
	tree.add(5);
	tree.print();

	Tree<int> res;
	vector<Node<int>*> n = g1.getVertice();
	
	vector<pair<int, bool>> visited;
	for (int i = 0; i < n.size(); i++) {
		visited.push_back({n[i]->getIndex(), false});
	}
	res.convertToTree(g1, res,visited);
	res.print();*/
}

