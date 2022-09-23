#pragma once
#include <iostream>
#include <vector>
#include "Node.h"
using namespace std;
template <typename T>
class TreeNode
{
	T data;
	TreeNode<T>* parent;
	vector<TreeNode<T>*> sons;
public:
	TreeNode() {
		this->parent = nullptr;
		this->sons = nullptr;
	}
	TreeNode(T data, TreeNode<T>* p = nullptr, vector<TreeNode<T>*> sons = {}) {
		this->data = data;
		this->parent = p;
		this->sons = sons;
	}
	TreeNode(Node<T>* node) {
		vector<Edge<T>*> vec=node->getEdge();
		
	}
	vector< TreeNode<T>*>& getSons() {
		return sons;
	}
	TreeNode<T>* getParent() {
		return parent;
	}
	T getData() {
		return data;
	}
	void changeParent(TreeNode<T>* p) {
		this->parent = p;
	}
	void addSon(TreeNode<T>* s) {
		sons.push_back(s);
	}
};

