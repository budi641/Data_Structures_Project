#pragma once

template <typename T>
class ArrayQueue
{

private:
	
	int front;
	 
	int rear;
	
	T* arr;

	int size;
	
	int MaxSize;

public:

	ArrayQueue()
	{

	}
	
	ArrayQueue(int maxSize)
	{
		MaxSize = maxSize;
		arr = new T[MaxSize];
		front = rear = -1;
		size = 0;
	}

	bool isEmpty()
	{
		if (front == -1&& rear== -1)
			return true;
		else
			return false;
	}


	bool dequeue(T &topElement)
	{
		
		if (isEmpty())
		{
			return false;
			
		}
		topElement = arr[front];
		front = (front + 1) % MaxSize;
		size--;
		return true;
	}


	bool enqueue(T &element)
	{
		
		if (!isEmpty())
		{
			return false;
		}

		rear = (rear + 1) % MaxSize;
		arr[rear] = element;
		size++;

		return true;
	}
	
};


