#pragma once
#include "Node.h"
template <class T>

class LinkedStack 
{
private:
    Node<T>* top;
public:
    LinkedStack() 
    {
        top = nullptr;
    }
    bool isEmpty()
    {
        if (top == nullptr)
            return false;
        else
            return true;
    }
 
    void push(const T& val) 
    {
        if (top == nullptr) 
        {
            top = new Node<T>;
            top->getNext() = nullptr;
            top->data = val;
        }
        else 
        {
            Node<T>* temp = new Node<T>;
            temp->data = val;
            top->getNext() = temp;
            top = temp;
        }
    }
    bool pop(T& TopEntry)
    {
        if (top == nullptr) 
        {
            cout << "Stack is empty" << endl;
            return false;
        }
        else 
        {
            
            Node<T>* temp = top;
            top = top->getNext();
            TopEntry = temp->getItem();
            delete temp;
        }
    }

};
