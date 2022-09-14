#pragma once

#include <iostream>
template<typename T>
class Node
{
private:
	T data;
	Node* next;
	
public:
	
	Node(Node<T>* n=nullptr) {
		this->next = n;
	}
	Node(T d, Node<T>* n=nullptr) {
		this->data = d;
		this->next = n;
	}
	void append(Node<T>* d) {
		Node<T>* temp = new Node<T>();
		temp = this;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = d;
	}
	friend std::istream& operator >> (std::istream& is, Node<T>& node) {
		std::cout << "Enter data" << std::endl;
		is >> Node.data;
	}
	T getData() {
		return data;
	}
	Node* getNext() {
		return this->next;
	}
};

