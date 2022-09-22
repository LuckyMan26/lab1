#pragma once
#include "TreeNode.h"
template<typename T>
class Tree
{
	TreeNode<T>* root;
public:
	void  print(TreeNode<T> node_to_print) {
		if (!node_to_print) {
			node_to_print = this->root;
			if (!node_to_print) {
				std::cout << "Empty tree" << std::endl;
				return;
			}
		}
		std::cout << node_to_print->data << "(";
		TreeNode* current = node_to_print->first_child;
		while (current) {
			print(current);
			current = current->next;
			if (current) { std::cout << ", "; }
		}
		std::cout << ")";
		if (node_to_print == this->root) {
			std::cout << std::endl;
		}
	}
	void add_child_node(TreeNode<T>* parent, TreeNode<T>* child) {
		child->parent = parent;
		vector<TreeNode<T>*> vec=parent->getSons();
		vec.push_back(child);
	}
	void add(T data, TreeNode<T>* parent=nullptr) {
		TreeNode* new_node = new TreeNode(data);
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

		return new_node;
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

		return new_node;
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

