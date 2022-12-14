#pragma once

#include <iostream>
#include <vector>
using namespace std;
template <class T> class Edge;

template<typename T>
class Node {
private:
	T data;
	int index;
	std::vector<Edge<T>*> adjVec;

public:
	Node() {
		index = -1;
	}
	Node(T dat) {
		this->data = dat;
		index = -1;
	}
	
	void changeIndex(int id) {
		this->index = id;
	}
	void addEdge(Node* dest, int weight = 0) {
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
		return index;
	}
	friend std::ostream& operator << (std::ostream& os, Node<T>* node) {
		vector<Edge<T>*> v = node->getEdge();
		int index = node->getIndex();
		T data = node->getData();
		os << index << " " << data << ": ";
		for (int i = 0; i < v.size(); i++) {
			os << "(" << v[i]->getDest()->getIndex() << "," << v[i]->getDest()->getData() << ") ";
		}
		os << std::endl;
		return os;
	}
	void deleteEdge(int index) {
		for (int i = 0; i < adjVec.size(); i++) {
			if (adjVec[i]->getDest()->getIndex() == index) {
				adjVec.erase(adjVec.begin() + i);
			}
		}
	}
	void deleteEdge(Node* dest) {
		
		for (int i = 0; i < adjVec.size(); i++) {
			if (adjVec[i]->getDest() == dest) {
				adjVec.erase(adjVec.begin() + i);
			}
		}
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
	int getWeight() {
		return weight;
	}
	Edge(Node<T>* s=nullptr, Node<T>* d=nullptr, int w=0) {
		this->source = s;
		this->dest = d;
		this->weight = w;
	}

	bool operator < (const Edge& edge) {
		return this->weight < edge.getWeight();
	}
};
