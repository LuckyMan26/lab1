#pragma once
#include "Node.h"
#include <vector>
using namespace std;
template<typename T>
class Graph
{
private:
	std::vector<Node<T>*> vertices;
	
public:
	int getNumberOfVertices() {
		return vertices.size();
	}
	void addVertice(Node<T>* node) {
		int index=getNumberOfVertices();
		node.changeIndex(inedx + 1);
		vertices.push_back(node);
		cout << node->getData() << endl;
	}
	void addEdge(T& source,T& dest) {
		std::vector<Node<T>*> nodeSource;
		std::vector<Node<T>*> nodeDest;

		for (int i = 0; i < vertices.size(); i++) {
			if (vertices[i].data == source) {
				nodeSource.push_back(vertices[i]);
			}
			if (vertices[i].data == dest) {
				nodeDest.push_back(vertices[i]);
			}
		}
		for (int i = 0; i < nodeSource.size(); i++) {
			for (int j = 0; j < nodeDest.size(); j++) {
				nodeSource[i]->addEdge(nodeDest[j]);
			}
		}
	}
	vector<Node<T>*> getVertice() {
		return vertices;
	}
	
	friend std::ostream& operator << (std::ostream& os, Graph<T>& g) {
		vector<Node<T>*> vec=g.getVertice();
		for (int i = 0; i < vec.size(); i++) {
			os << (vec[i]);
		}
		return os;

	}
};

