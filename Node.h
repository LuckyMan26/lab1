#pragma once

#include <iostream>
#include <vector>
using namespace std;
template <class T> class Edge;

template<typename T>
class Node
{
private:
	T data;
	int index;
	std::vector<Edge<T>*> adjVec;
	
public:
	Node(T dat) {
		this->data = dat;
		index = -1;
	}
	void changeIndex(int id) {
		this->index = id;
	}
	void addEdge(Node* dest,int weight=0) {
		Edge<T>* edge = new Edge<T>(this, dest, weight);
		adjVec.push_back(edge);
	}
	friend std::istream& operator >> (std::istream& is, Node<T>& node) {
		std::cout << "Enter data" << std::endl;
		is >> Node.data;
		return is;
	}
	vector<Edge<T>*> getEdge() {
		return this->adjVec;
	}
	
	T getData() {
		return this->data;
	}
	int getIndex() {
		return this->index;
	}
	friend std::ostream& operator << (std::ostream& os, Node<T>* node) {
		vector<Edge<T>*> v = node->getEdge();
		int index = node->getIndex();
		T data = node->getData();
		for (int i = 0; i < v.size(); i++) {
			os << "("<< v[i]->getDest()->getIndex() << ") ";
		}
		os << std::endl;
		return os;
	}
};
template <typename T>
class Edge {
	Node<T>* source;
	Node<T>* dest;
	int weight;
public:
	Node<T>* getSource() {
		return source;
	}
	Node<T>* getDest() {
		return dest;
	}
	Edge(Node<T>* s=nullptr, Node<T>* d=nullptr, int w=0) {
		this->source = s;
		this->d = dest;
		this->weight = w;
	}

};
