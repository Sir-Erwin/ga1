#ifndef DLINKEDLIST_H_
#define DLINKEDLIST_H_

#include <iostream>
#include <cmath>

#include "barcode.h"

template <typename T = bar>
struct Node {
	T data;
	Node<T>* next;
	Node<T>* prev;

	void print() {
		std::cout << data;
	}
};

template <typename T = bar>
class DLinkedList {
private:
	Node<T>* head;
	Node<T>* tail;

public:
	DLinkedList() {
		head = nullptr;
		tail = nullptr;
	};

	void RemoveHead() {
		if (head == nullptr) return;
		Node<T>* temp = head;
		if (head->next == nullptr)
			head = nullptr;
		else {
			head = head->next;
			head->prev = nullptr;
		}
		delete temp;
	};

	void RemoveTail() {
		if (tail == nullptr) return;
		else if (size() == 1) RemoveHead();
		Node<T>* temp = tail;
		if (tail->prev == nullptr)
			tail = nullptr;
		else {
			tail = tail->prev;
			tail->next = nullptr;
		}
		delete temp;
	};

	/*
	void Remove(int index) {
	  if (isEmpty()) return;
	  if (index == 0) RemoveHead();
	  else if (index >= size()) RemoveTail();
	  else {
		Node<T>* temp = head;
		int i = 0;
		while (i < index and temp->next != nullptr) {
		  temp=temp->next;
		  i++;
		}
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		delete temp;
	  }
	}; */

	void add(T data) {
		AddTail(data);
	}

	void add(std::string str) {
		T t(str);
		add(t);
	}

	void AddHead(T data) {
		Node<T>* val = new Node<T>;
		val->data = data;
		val->prev = nullptr;
		if (isEmpty()) {
			tail = val;
			head = val;
			val->next = nullptr;
		}
		else {
			val->next = head;
			head->prev = val;
		}
		head = val;
	};

	bool isEmpty() {
		return head == nullptr;
	}

	void AddTail(T data) {
		if (isEmpty()) {
			AddHead(data);
			return;
		}

		else {
			Node<T>* val = new Node<T>;
			val->data = data;
			val->next = nullptr;
			val->prev = tail;
			tail->next = val;
			tail = tail->next;
		}
	};

	void Add(int index) {
		Node<T>* del = 0;
	};

	/*
	T& operator[](int index) const {
	  if (index >= size()) return tail->data;
	  Node<T> *temp = head;
	  int i = 0;
	  while (i < index) {
		temp=temp->next;
		i++;
	  }
	  return temp->data;
	}; */ // Does The Size Function work? It kinda looks iffy...


	std::size_t size(Node<T>* temp) {
		if (temp == nullptr) return 0;
		return size(temp->next) + 1;
	};

	std::size_t size() {
		return size(head);
	};

	/*
	void printBackwards() {
	  Node<T>* temp = tail;
	  while (temp != nullptr) {
		temp->print();
		std::cout << ", ";
		temp = temp->prev;
	  }
	}; */ /*
	void printForwards() {
	  Node<T>* temp = head;
	  while (temp != nullptr) {
		temp->print();
		std::cout << ", ";
		temp = temp->next;
	  }
	}; */

	Node<T>* getHead() {
		return head;
	}

	Node<T>* getTail() {
		return tail;
	}

	void RecurBubbleSort(Node<T>* curHead, Node<T>* node) {
		if (node == 0) return;
		if (node->next == nullptr) {
			if (curHead->next == nullptr) {
				return;
			}
			else {
				RecurBubbleSort(curHead->next, curHead->next);
			}
		}
		else {
			if (node->data.name.size() > node->next->data.name.size()) {
				/* Manual monkey swap. 🐒🐒🐒🐒🐒🐒🐒🐒🐒🐒🐒🐒🐒🐒🐒 */
				T temp = node->data;
				node->data = node->next->data;
				node->next->data = temp;
			}

			else if (node->data.name.size() == node->next->data.name.size()) {
				if (node->data.name > node->next->data.name) {
					/* Manual monkey swap. 🐒🐒🐒🐒🐒🐒🐒🐒🐒🐒🐒🐒🐒🐒🐒 */
					T temp = node->data;
					node->data = node->next->data;
					node->next->data = temp;
				}
			}

			RecurBubbleSort(curHead, node->next);
		}
	}

	void RecurBubbleSort() {
		for(int i = 0; i < sqrt(size(getHead())) + 1; i++)
			RecurBubbleSort(getHead(), getHead());
	}

	bool checkDuplicates(Node<T>* node) {
		if (node == 0) return false;
		if (node->next == 0)
			return false;

		//std::cout << node->data.name << " " << node->next->data.name << std::endl;

		bool status = false;

		if (node->data.name == node->next->data.name) {
			node->data.count++;
			Node<>* temp = node->next;
			node->next = node->next->next;
			delete temp;
			status = true;
		}

		return status || checkDuplicates(node->next);;
	}

	void checkDuplicates() {
		while (checkDuplicates(getHead()));
	}
};

#endif
