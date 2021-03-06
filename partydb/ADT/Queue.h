// Queue.h
// Lab 2b: Queue ADT
// CIS 22C F2016: Adrian Marroquin, Matthew Tso

#ifndef STACKADT_QUEUE_H
#define STACKADT_QUEUE_H

#include "List.h"

#define T_DATA template <typename DataType>

T_DATA
class Queue : protected List<DataType>
{
public:
	~Queue();

	/**
	 * Expose isEmpty
	 */
	bool isEmpty();

	/**
	 * Expose getLength
	 */
	int getLength();

	/**
	 * Adds an item to the top of the list.
	 */
	bool enqueue(const DataType& item);

	/**
	 * Removes an item from the end of the list
	 * (the item that the tail is pointing to)
	 */
	DataType dequeue();
};

#include "Queue.cpp"
#endif