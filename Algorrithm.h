#pragma once
#include "Graph.h"
#include <algorithm>
template<typename T>
Node<T>* createNode(int id,T data) {
    Node<T>* node = new Node<T>(data);

    node->changeIndex(id);
    return node;
}
template<typename T>
bool isInVector(vector<Edge<T>*> v,Edge<T>* data) {
    for (int i = 0; i < v.size(); i++) {
        if ((v[i]->getDest() == data->getDest())&&(v[i]->getSource() == data->getSource())||((v[i]->getDest() == data->getSource()) && (v[i]->getSource() == data->getDest()))) {
            return true;
        }
    }
    return false;
}
template<typename T>
class Algorithm
{
private:
	Graph<T> Spanning_Tree;
public:
	Graph<T> Kruskal(Graph<T> g) {
        vector<Node<T>*> v;
        vector<Edge<T>*> temp;
        vector<Edge<T>*> res;
        Node<T>* tmp;
        int size = g.getNumberOfVertices();
        v = g.getVertice();
        for (int i = 0; i < size; i++) {
            temp = v[i]->getEdge();
                for (int j = 0; j < temp.size(); j++) {
                    if (!isInVector(res, temp[j])) {
                        res.push_back(temp[j]);
                    }
                }
            
        }
        sort(res.begin(),res.end());
        for (int i = 0; i < res.size(); i++) {
            cout << res[i]->getSource()->getData()<<" "<< res[i]->getDest()->getData() << endl;
        }
        Graph<T>  graph;
        for (int i = 0; i < size; i++) {
            graph.addVertice(createNode(v[i]->getIndex(),v[i]->getData()));
        }
        Edge<T> e;
        while (!res.empty()) {
            graph.addEdge(res[0]->getSource()->getData(), res[0]->getDest()->getData(), res[0]->getWeight());
            if (!graph.isAcyclic()) {
                graph.deleteByIndex(res[0]->getSource()->getIndex(), res[0]->getDest()->getIndex());

            }
            res.erase(res.begin());
        }
        return graph;
	}
};

