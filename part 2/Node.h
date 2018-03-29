// Original source attribution available
// Modified by M. Molodowitch

// Node template definition: each Node object contains data and a pointer to the following node.
// For use in linked lists and in linked list implementations of a stack and a queue.

#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template< class ItemType > class Stack;  // forward declarations
template< class ItemType > class Queue;

template<class ItemType>
class Node {
   friend class Stack< ItemType >; // make Stack a friend
   friend class Queue< ItemType >; // make Queue a friend
public:
   Node( const ItemType & );  // constructor
   Node();
   ItemType getInfo() const;      // return data in the node
private:
   ItemType info;                 // data
   Node< ItemType > *nextPtr; // pointer to the next node in the list
};

// Constructor
template<class ItemType>
Node< ItemType >::Node( const ItemType & value)
{
	info = value; 
	nextPtr = NULL;
}

template<class ItemType>
Node< ItemType >::Node( )
{
	nextPtr = NULL;
}


// Return a copy of the data in the node
template< class ItemType >
ItemType Node< ItemType >::getInfo() const 
{ 
	return info; 
}

#endif


