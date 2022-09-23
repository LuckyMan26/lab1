#pragma once
#include "Node.h"
#include <vector>
using namespace std;
template<typename T>
Node<T>* createNode(int id) {
	Node<T>* node=new Node<T>;
	
	node->changeIndex(id);
	return node;
}
template<typename T>
class Graph
{
private:
	std::vector<Node<T>*> vertices;
	bool isCyclicUtil(int v, bool* visited, int parent)
	{
		visited[v] = true;
		vector<Edge<T>*> vec = vertices[v]->getEdge();
		for(int i=0;i<vec.size(); i++)
		{
			if (!visited[vec[i]->getDest()->getIndex()])
			{
				if (isCyclicUtil(vec[i]->getDest()->getIndex(), visited, v))
					return true;
			}

			else if (vec[i]->getDest()->getIndex() != parent) {
				return true;
			}
			
		}
		return false;
	}
	
public:
	int findParent(int x, int vis[], int root[]) {
		if (vis[x])
			return root[x];

		vis[x] = 1;
		root[x] = x;
		vector<Node<T>*> v;
		int tmp;
		for (int i = 0; i < v.size(); i++) {
			if (v[i]->getIndex() == x) {
				tmp = i;
			}
		}
		root[x] = findParent(v[tmp]->getIndex(), vis, root);
		return root[x];
	}
	Graph() {
		vertices = {};
	}
	Graph(int size) {
		Node<T>* node=new Node<T>;
		for (int i = 0; i < size; i++) {
			vertices.push_back(createNode<T>(i));
	}
		vertices.resize(size);
	}
	int getNumberOfVertices() {
		return vertices.size();
	}
	void addVertice(Node<T>* node) {
		int index=getNumberOfVertices();
		node->changeIndex(index);
		vertices.push_back(node);
	}
	void addEdge(T source,T dest,int weight=0) {
		std::vector<Node<T>*> nodeSource;
		std::vector<Node<T>*> nodeDest;
		
		for (int i = 0; i < vertices.size(); i++) {
			if (vertices[i]->getData() == source) {
				nodeSource.push_back(vertices[i]);
			}
			if (vertices[i]->getData() == dest) {
				nodeDest.push_back(vertices[i]);
			}
		}
		if (nodeSource.empty()) {
			
			Node<T>* node=new Node<T>(source);
			this->addVertice(node);
			nodeSource.push_back(node);
		}
		if (nodeDest.empty()) {
			Node<T>* node = new Node<T>(dest);
			this->addVertice(node);
			nodeDest.push_back(node);
		}
		
		for (int i = 0; i < nodeSource.size(); i++) {
			for (int j = 0; j < nodeDest.size(); j++) {
				nodeSource[i]->addEdge(nodeDest[j],weight);
			}
		}
		for (int i = 0; i < nodeDest.size(); i++) {
			for (int j = 0; j < nodeSource.size(); j++) {
				nodeDest[i]->addEdge(nodeSource[j]);
			}
		}
	
	}
	
	vector<Node<T>*> getVertice() {
		return vertices;
	}
	void deleteByIndex(int indexSource, int indexDest) {
		int beg, end;
		for (int i = 0; i < vertices.size(); i++) {
			if (vertices[i]->getIndex() == indexSource) {
				vertices[i]->deleteEdge(indexDest);
			}
			if (vertices[i]->getIndex() == indexDest) {
				vertices[i]->deleteEdge(indexSource);
			}
		}
	}

	friend std::ostream& operator << (std::ostream& os, Graph<T>& g) {
		vector<Node<T>*> vec=g.getVertice();
	
		for (int i = 0; i < vec.size(); i++) {
			os << (vec[i]);
		}
		return os;
	}
	void addEdge(Node<T>* source, Node<T>* dest,int weight=0) {
		source->addEdge(dest,weight);
		dest->addEdge(source, weight);

	}
	void deleteEdge(T source, T dest) {
		std::vector<Node<T>*> nodeSource;
		std::vector<Node<T>*> nodeDest;

		for (int i = 0; i < vertices.size(); i++) {
			if (vertices[i]->getData() == source) {
				nodeSource.push_back(vertices[i]);
			}
			if (vertices[i]->getData() == dest) {
				nodeDest.push_back(vertices[i]);
			}
		}
		for (int i = 0; i < nodeSource.size(); i++) {
			for (int j = 0; j < nodeDest.size(); j++) {
				nodeSource[i]->deleteEdge(nodeDest[j]);
			}
		}
		for (int i = 0; i < nodeDest.size(); i++) {
			for (int j = 0; j < nodeSource.size(); j++) {
				nodeDest[i]->deleteEdge(nodeSource[j]);
			}
		}
	}
	void deleteVertice(T source) {
		vector<Node<T>*> v;
		vector<Edge<T>*> edge;
		for (int i = 0; i < vertices.size(); i++) {
			edge = vertices[i]->getEdge();
			for (int j = 0; j < edge.size(); j++) {
				if (edge[j]->getDest()->getData() == source) {
					deleteEdge(vertices[i]->getData(), source);
				}
			}
		}
		for (int i = 0; i < vertices.size(); i++) {
			if (vertices[i]->getData() == source) {
				vertices.erase(vertices.begin() + i);
			}
		}
	}
	bool isAcyclic() {

				bool* visited = new bool[vertices.size()];
				for (int i = 0; i < vertices.size(); i++)
					visited[i] = false;

				for (int i = 0; i < vertices.size(); i++)
				{
					if (!visited[i] && vertices[i]->getIndex() == i) {
						if (isCyclicUtil(i, visited, -1)) {
							return false;
						}
					}
				}
				return true;
			}
};

