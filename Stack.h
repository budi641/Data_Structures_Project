#pragma once
#include "Node.h"
template<typename T>
class Stack 
{
	int size = 0;
	Node<T>* Head;
public:

	void Push(T val) {
		Node<T>* temp = new Node<T>(val);
		if (size == 0)
			Head = temp;
		else {
			temp->setNext(Head);
			Head = temp;
		}
		size++;
	}

	T Peek() { return Head->getItem(); }

	T Pop() {
		T item = Head->getItem();
		Head = Head->getNext();
		size--;
		return item;
	}
	bool IsEmpty() { return (size == 0); }
	int Size() { return size; }
};

