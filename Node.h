#pragma once
template <typename T, typename PriorityType = int>
class Node
{
private:
    T data;
    PriorityType priority;
    Node* next;

public:
    Node(const T& newData, const PriorityType& newPriority)
    {
        data = newData;
        next = nullptr;
        priority = newPriority;
    
    }

    
    T getData() const
    {
        return data;
    }

 
    Node* getNext() const
    {
        return next;
    }

   
    void setNext(Node* newNext) 
    {
        next = newNext;
    }
    void setPriority(const PriorityType& newPriority)
    {
        priority = newPriority;
    }
    PriorityType getPriority() const 
    {
        return priority;
    }

};

