#pragma once
#include "TreeNode.h"
#include "Node.h"
#include "Graph.h"
#include <queue>
template<typename T>
int posInVector(vector<pair<int, bool>> visited, Node<T>* node) {
	for (int i = 0; i < visited.size(); i++) {
		if (visited[i].first == node->getIndex()) {
			return i;
			break;
		}
	}
}
template<typename T>
class Tree
{
	TreeNode<T>* root;
	
public:
	
	void convertToTree(Graph<T> g,Tree<T>& t, vector<pair<int, bool>> visited,Node<T>* cur=nullptr,TreeNode<T>* f=nullptr) {
		if (cur == nullptr) {
			vector<Node<T>*> node = g.getVertice();
			TreeNode<T>* treeNode = new TreeNode<T>(node[0]->getData());
			int pos = posInVector(visited, node[0]);

			convertToTree(g, t, visited,node[0]);
		}
		else if (cur != nullptr) {
			cout<<cur->getData()<<endl;
			vector<Edge<T>*> e;
			e = cur->getEdge();
			TreeNode<T>* treeNode = new TreeNode<T>(cur->getData(), f);
			int pos = posInVector(visited, cur);
			visited[pos].second = true;
			t.addNode(treeNode, f);
			for (int i = 0; i < e.size(); i++) {
				pos = posInVector(visited, e[i]->getDest());
				if (!visited[pos].second) {

					convertToTree(g, t,visited,e[i]->getDest(),treeNode);
				}
			}
			
		}
	}
	Tree() {
		root = nullptr;
	}
	Tree(Graph<T> g) {
		Tree<T> res;
		this->convertToTree(g, res);
	}
	void  print(TreeNode<T>* node_to_print=nullptr) {
		if (!node_to_print) {
			node_to_print = this->root;
			if (!node_to_print) {
				std::cout << "Empty tree" << std::endl;
				return;
			}
		}
		std::cout << node_to_print->getData() << "(";
	
		vector<TreeNode<T>*> vec = node_to_print->getSons();
		for (int i = 0;i<vec.size();i++) {
			this->print(vec[i]);
			
			if ((vec[i])) { std::cout << ", "; }
		}
		std::cout << ")";
		if (node_to_print == this->root) {
			std::cout << std::endl;
		}
	}
	void add_child_node(TreeNode<T>* parent, TreeNode<T>* child) {
		child->changeParent(parent);

		parent->addSon(child);
		
	}
	void add(T data, TreeNode<T>* parent=nullptr) {
		TreeNode<T>* new_node = new TreeNode<T>(data,parent);
		if (parent == nullptr) {
			if (this->root) {
				
				add_child_node(root, new_node);
			}
			else {
				this->root = new_node;
			}
		}
		else {
			add_child_node(parent, new_node);
		}

	}
	void addNode(TreeNode<T>* data, TreeNode<T>* parent = nullptr) {
		
		if (parent == nullptr) {
			if (this->root) {
				add_child_node(root, data);
			}
			else {
				this->root = data;
			}
		}
		else {
			add_child_node(parent, data);
		}

	}
	void deleteNode(TreeNode<T>* node) {
		if (node->getParent()) {
			TreeNode<T>* parent = node->getParent();
			vector<TreeNode<T>*> vec=node->getSons();
			vector<TreeNode<T>*> vec1 = parent->getSons();
			for (int i = 0; i < vec.size(); i++) {
				vec1.push_back(vec[i]);
			}
		}
		else {
			cout << "You have deleted root\nYour tree has been successfully deleted\n";
			delete root;
		}
	}
};

