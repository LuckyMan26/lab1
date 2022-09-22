// lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include <vector>
#include "dice.h"
#include "DiceSet.h"
#include "Node.h"
#include "Graph.h"
#include "Algorrithm.h"
#include "Tree.h"
using namespace std;

int main()
{
	Node<int>* node=new Node<int>(0);
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
}

