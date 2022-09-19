#pragma once
#include "Node.h"
#include <vector>
template<typename T>
class Graph
{
private:
	std::vector<Node<T>*> vertices;
public:
	Graph(std::vector<Node<T>*> v = {}) {
		for (int i = 0; i < v.size(); i++) {
			vertices.push_back(v[i]);
		}
		
	}
	void add_vertice(Node<T>* node) {
		vertices.push_back(node);
	}
	void add_edge(int beg, int end) {
		Node<T>* temp = vertices[beg];
		Node<T>* temp1 = vertices[end];
		Node<T>* tmp = new Node<T>(vertices[end]->getData(), nullptr);
		T d = vertices[end]->getData();
		temp->append(tmp);
		Node<T>* tmp1 = new Node<T>(vertices[beg]->getData(), nullptr);
		temp1->append(tmp1);
	}
	friend std::ostream& operator << (std::ostream& os, Graph& graph) {
		for (int i = 0; i < graph.vertices.size(); i++) {
			Node<T>* temp = graph.vertices[i];
			temp = temp->next;
			os << i << ": ";
			while (temp) {
				os << temp->getData() <<" ";
				temp = temp->next;
			}
			os << std::endl;
			
		}
		return os;
	}
	void delete_edge(int index_beg, int index_end) {
		Node<T>* beg = vertices[index_beg];
		Node<T>* endd = vertices[index_end];
		T data = vertices[index_end]->getData();
		T d = vertices[index_beg]->getData();
		Node<T>* begg = new Node<T>(vertices[index_beg]);
		Node<T>* prev=new Node<T>(nullptr);

		while (beg) {
			if (beg->getData() == data) {
				if (beg->next) {
					prev->next = beg->next;
					delete beg;
					break;
				}
				else {
					prev ->next = nullptr;
					delete beg;
					break;

				}
				
			}
			prev = beg;
			beg = beg->next;
			
		}
		while (endd) {
			if (endd->getData() == d) {
				if (endd->next) {
					prev->next = endd->next;
					delete endd;
					break;
				}
				else {
					prev->next = nullptr;
					delete endd;
					break;
				}

			}
			prev = endd;
			endd = endd->next;
		}
	}
	void delete_vertice(int index) {
		Node* temp = this->vertices[index];
		Node* tmp = this->vertices[index];
		while (temp) {
			for (int i = 0; i < this->vertices.size(); i++) {
				if (this->vertices[i] == temp->data) {
					this->delete_edge(i, index);
					break;
				}
			}
			temp = temp->next;
		}
	}
	
};

