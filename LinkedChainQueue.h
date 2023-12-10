#include"Node.h"
#include <iostream>
using namespace std;

template <typename T>
class CircularChainQueue {
private:
   
    Node<T>* rearPtr; 

public:
    CircularChainQueue()
    {
        rearPtr = nullptr;
    
    }
    ~CircularChainQueue() 
    {
        clear();
    }

    void enqueue(const T& newData)
    {
        Node<T>* newNode = new Node<T>(newData);
        if (isEmpty()) 
        {
            rearPtr = newNode;
            rearPtr->setNext(rearPtr); // Circular link
        }
        else
        {
            newNode->setNext(rearPtr->getNext());
            rearPtr->setNext(newNode);
            rearPtr = newNode;
        }
    }
    void dequeue() 
    {
        if (!isEmpty()) 
        {
            Node<T>* temp = rearPtr->getNext();
            if (temp == rearPtr) 
            {
                rearPtr = nullptr;
            }
            else 
            {
                rearPtr->setNext(temp->getNext());
            }
            delete temp;
        }
    }

    bool isEmpty() const 
    {
        return rearPtr == nullptr;
    }
    void clear() 
    {
        while (!isEmpty()) 
        {
            dequeue();
        }
    }
    void print() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        Node<T>* current = rearPtr->getNext();
        do 
        {
            cout << current->getData() << " ";
            current = current->getNext();
        } while (current != rearPtr->getNext());

        cout << endl;


    }
};

