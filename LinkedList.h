#pragma once
#include <iostream>
#include"Node.h"
using namespace std;

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    int count;

public:
    LinkedList() 
    {
        head = nullptr;
        count = 0;
    
    }

    ~LinkedList() 
    {
        while (head)
        {
            Node<T>* temp = head;
            head = head->getNext();
            delete temp;
        }
    }
    void setHead(Node<T>* newHead)
    {
        head = newHead;
    }

    void InsertEnd(T data) 
    {
        Node<T>* newNode = new Node<T>(data);
        if (!head) 
        {
            head = newNode;
        }
        else 
        {
            Node<T>* current = head;
            while (current->getNext())
            {
                current = current->getNext();
            }
            current->setNext(newNode);
        }
        count++;
    }

    void InsertBeg(T data) 
    {
        Node<T>* newNode = new Node<T>(data);
        newNode->setNext(head);
        head = newNode;
        count++;
    }

    bool Find(T data) 
    {
        Node<T>* current = head;
        while (current) {
            if (current->getData() == data) {
                return true;
            }
            current = current->getNext();
        }
        return false;
    }

    int CountOccurrence(T data) {
        int count = 0;
        Node<T>* current = head;
        while (current) {
            if (current->getData() == data) {
                count++;
            }
            current = current->getNext();
        }
        return count;
    }

    void DeleteFirst() {
        if (!head) {
            return;
        }

        Node<T>* temp = head;
        head = head->getNext();
        delete temp;
        count--;
    }

    void DeleteLast() {
        if (!head) {
            return;
        }

        if (head->getNext() == nullptr) {
            delete head;
            head = nullptr;
            count--;
            return;
        }

        Node<T>* current = head;
        Node<T>* previous = nullptr;
        Node<T>* lastNode = nullptr;

        while (current->getNext()) {
            previous = current;
            lastNode = current->getNext();
            current = current->getNext();
        }

        delete lastNode;
        if (previous) {
            previous->setNext(nullptr);
        }
        count--;
    }

    bool DeleteNode(T data) {
        if (!head) {
            return false;
        }

        if (head->getData() == data) {
            DeleteFirst();
            return true;
        }

        Node<T>* current = head;
        while (current->getNext()) {
            if (current->getNext()->getData() == data) {
                Node<T>* temp = current->getNext();
                current->setNext(temp->getNext());
                delete temp;
                count--;
                return true;
            }
            current = current->getNext();
        }

        return false;
    }

    bool DeleteNodes(T data) {
        bool deleted = false;
        while (DeleteNode(data)) {
            deleted = true;
        }
        return deleted;
    }

    void Merge(LinkedList<T>& L) {
        if (!L.head) {
            return;
        }

        if (!head) {
            head = L.head;
        }
        else {
            Node<T>* current = head;
            while (current->getNext()) {
                current = current->getNext();
            }
            current->setNext(L.head);
        }

        count += L.count;
        L.head = nullptr;
        L.count = 0;
    }

    void Reverse() {
        if (!head || !head->getNext()) {
            return;
        }

        Node<T>* current = head;
        Node<T>* prev = nullptr;
        Node<T>* next = nullptr;

        while (current) {
            next = current->getNext();
            current->setNext(prev);
            prev = current;
            current = next;
        }

        head = prev;
    }

    void RecPrint(Node<T>* ptr) {
        if (ptr == nullptr) {
            return;
        }

        cout << ptr.getData() << " -> ";
        RecPrint(ptr->getNext());
    }

    int getCount() const {
        return count;
    }

    Node<T>* getNodeByIndex(int index) {
        if (index < 0) {
            return nullptr;
        }

        Node<T>* current = head;
        int currentIndex = 0;

        while (current && currentIndex < index) {
            current = current->getNext();
            currentIndex++;
        }

        return current;
    }

    void PrintList(){
        Node<T>* current = head;
        while (current) 
        {
            cout << current->getData() << " -> ";
            current = current->getNext();
        }
    }
   
    pair<LinkedList<T>, LinkedList<T>> SignSplit()
    {
        LinkedList<T> Lneg;
        LinkedList<T> Lpos;

        Node<T>* current = head;
        Node<T>* previous = nullptr;

        while (current) {
            Node<T>* nextNode = current->getNext();

            if (current->getData() < 0) {
                if (previous) {
                    previous->setNext(nextNode);
                }
                else {
                    head = nextNode;
                }
                current->setNext(nullptr);
                Lneg.InsertEnd(current->getData());
                delete current;
            }
            else if (current->getData() > 0) {
                Lpos.InsertEnd(current->getData());
            }

            current = nextNode;
            if (current && current->getData() >= 0) {
                previous = current;
            }
        }

        return make_pair(Lneg, Lpos);
    }
    
    LinkedList<pair<T, int>>MakeDictionary() const {
        LinkedList<pair<T, int>> dictionary;

        Node<T>* current = head;

        while (current) {
            T data = current->getData();
            int count = CountOccurrence(data);

            bool found = false;
            Node<pair<T, int>>* dictCurrent = dictionary.getHead();
            while (dictCurrent) {
                if (dictCurrent->getData().first == data) {
                    found = true;
                    break;
                }
                dictCurrent = dictCurrent->getNext();
            }

            if (!found) {
                pair<T, int> dictEntry(data, count);
                dictionary.InsertEnd(dictEntry);
            }

            current = current->getNext();
        }

        return dictionary;
    }
    void clear() 
    {
        while (head) {
            Node<T>* temp = head;
            head = head->getNext();
            delete temp;
        }
        count = 0;
    }
  
    LinkedList<T>MergeSorted(LinkedList<T>& list1, LinkedList<T>& list2) 
    {
        LinkedList<T> mergedList;

        Node<T>* current1 = list1.getHead();
        Node<T>* current2 = list2.getHead();

        while (current1 && current2) {
            if (current1->getData() < current2->getData()) {
                mergedList.InsertEnd(current1->getData());
                list1.DeleteFirst();
                current1 = list1.getHead();
            }
            else {
                mergedList.InsertEnd(current2->getData());
                list2.DeleteFirst();
                current2 = list2.getHead();
            }
        }

        while (current1) {
            mergedList.InsertEnd(current1->getData());
            list1.DeleteFirst();
            current1 = list1.getHead();
        }

       
        while (current2) {
            mergedList.InsertEnd(current2->getData());
            list2.DeleteFirst();
            current2 = list2.getHead();
        }

        return mergedList;
    }
    
    LinkedList<T>SumLists(const LinkedList<T>& list1, const LinkedList<T>& list2) const {
        LinkedList<T> sumList;

        Node<T>* current1 = list1.getHead();
        Node<T>* current2 = list2.getHead();
        if (list1.getCount != list2.getCount)
        {
            return sumList.clear();
        }

        while (current1 && current2) {
            T sum = current1->getData() + current2->getData();
            sumList.InsertEnd(sum);

            current1 = current1->getNext();
            current2 = current2->getNext();
        }

     

        return sumList;
    }

    
    Node<T>* RecursionReverseHelper(Node<T>* current) {
        if (!current->getNext()) {
            // Return the current node as the new head in the reversed list
            return current;
        }

        // Recursively reverse the rest of the list
        Node<T>* restReversed = RecursionReverseHelper(current->getNext());

        // Reverse the link to the next node
        current->getNext()->setNext(current);
        current->setNext(nullptr);

        return restReversed;
    }
    
    void RecursionReverse() {
        if (!head || !head->getNext()) {
            // Base case: If the list is empty or has only one element, it's already reversed.
            return;
        }

        // Recursive case: Reverse the rest of the list
        Node<T>* restReversed = RecursionReverseHelper(head);

        // Update the head to the last element
        head->setNext(nullptr);
        head = restReversed;
    }
 
    void Reorder_X(const T& X) {
        if (!head || !head->getNext()) {
            // No need to reorder if the list is empty or has only one element.
            return;
        }

        LinkedList<T> lessThanOrEqualList;
        LinkedList<T> greaterList;

        Node<T>* current = head;

        while (current) {
            T data = current->getData();
            if (data <= X) {
                lessThanOrEqualList.InsertEnd(data);
            }
            else {
                greaterList.InsertEnd(data);
            }
            current = current->getNext();
        }

        // Merge the two lists
        head = lessThanOrEqualList.getHead();
        if (head) {
            Node<T>* lastNode = head;
            while (lastNode->getNext()) {
                lastNode = lastNode->getNext();
            }
            lastNode->setNext(greaterList.getHead());
        }
        else {
            head = greaterList.getHead();
        }

        // Clear the temporary lists
        lessThanOrEqualList.clear();
        greaterList.clear();
    }
   
    void ShiftLargest() {
        if (!head || !head->getNext()) {
            // No need to shift if the list is empty or has only one element.
            return;
        }

        Node<T>* current = head;
        Node<T>* previous = nullptr;
        Node<T>* largestNode = nullptr;

        while (current && current->getNext()) {
            if (current->getData() > current->getNext()->getData()) {
                if (!largestNode || current->getData() > largestNode->getData()) {
                    largestNode = current;
                }

                // Swap the current node and the next node
                Node<T>* temp = current->getNext();
                current->setNext(temp->getNext());
                temp->setNext(current);

                // Update the previous node's next pointer
                if (previous) {
                    previous->setNext(temp);
                }
                else {
                    // If the largest node is the head, update the head pointer
                    head = temp;
                }
            }

            // Move to the next pair of nodes
            previous = current;
            current = current->getNext();
        }

        // Ensure the largest node is at the end
        if (largestNode) {
            largestNode->setNext(nullptr);
        }
    }
    //The `ShiftLargest` function can be used to partially sort a linked list, but it is not an efficient sorting algorithm. 
    // To fully sort a linked list of N nodes, you would need to call it N-1 times, resulting in a time complexity of O(N^2).
    
    void LinkedList<T>::RemoveDuplicates() {
        if (!head || !head->getNext()) {
            // No need to remove duplicates if the list is empty or has only one element.
            return;
        }

        Node<T>* current = head;

        while (current) {
            Node<T>* runner = current;

            while (runner->getNext()) {
                if (runner->getNext()->getData() == current->getData()) {
                    // Duplicate found, remove the duplicate node
                    Node<T>* duplicate = runner->getNext();
                    runner->setNext(duplicate->getNext());
                    delete duplicate;
                }
                else {
                    runner = runner->getNext();
                }
            }

            current = current->getNext();
        }
    }
    Node<T>* getHead() const
    {
        return head;
    }

};





