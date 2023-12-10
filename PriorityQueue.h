#include <iostream>
#include "Node.h"
using namespace std;

template <typename T, typename PriorityType = int>
class PriorityQueue 
{
private:
    Node<T, PriorityType>* frontPtr;
    Node<T, PriorityType>* rearPtr;

public:
    PriorityQueue()
    {
        frontPtr = nullptr;
        rearPtr = nullptr;
    
    }
    ~PriorityQueue()
    {
        clear();
    }

    void enqueue(const T& newData, const PriorityType& newPriority) 
    {
        Node<T, PriorityType>* newNode = new Node<T, PriorityType>(newData, newPriority);

        if (isEmpty() || newPriority > frontPtr->getPriority()) 
        {
            newNode->setNext(frontPtr);
            frontPtr = newNode;
        }
        else 
        {
            Node<T, PriorityType>* current = frontPtr;
            while (current->getNext() != nullptr && newPriority <= current->getNext()->getPriority()) {
                current = current->getNext();
            }
            newNode->setNext(current->getNext());
            current->setNext(newNode);
        }

        
        if (isEmpty()) 
        {
            rearPtr = frontPtr;
        }
    }

    void dequeue() 
    {
        if (!isEmpty()) 
        {
            Node<T, PriorityType>* temp = frontPtr;
            frontPtr = frontPtr->getNext();
            delete temp;

            
            if (frontPtr == nullptr) 
            {
                rearPtr = nullptr;
            }
        }
    }

    T front() const {
        if (!isEmpty()) 
        {
            return frontPtr->getData();
        }
        
        return T();
    }

    bool isEmpty() const 
    {
        return frontPtr == nullptr;
    }

    void clear() {
        while (!isEmpty()) 
        {
            dequeue();
        }
    }

    void print() const 
    {
        Node<T, PriorityType>* current = frontPtr;
        while (current != nullptr) 
        {
            cout << "Data: " << current->getData() << " Priority: " << current->getPriority() << endl;
            current = current->getNext();
        }
    }
};

