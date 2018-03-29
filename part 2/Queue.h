//
// Original is copyrighted, source avaliable to instructors on request
// Modifications by M. Molodowitch


// Template Queue class definition
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cassert>
#include "Node.h"

using namespace std;

template< class ItemType >
class Queue {
public:
   Queue();      // constructor
   ~Queue();     // destructor
   bool enqueue( const ItemType & );
   bool front( ItemType & );
   bool dequeue(  );
   bool isEmpty() const;
   bool isFull() const;

private:
   Node< ItemType > *queuePtr;  // pointer to first node
   Node< ItemType > *rearPtr;  // pointer to last node

};

// Default constructor
template< class ItemType >
Queue< ItemType >::Queue() 
{
	queuePtr = nullptr;
	rearPtr = nullptr;
}

// Destructor
template< class ItemType >
Queue< ItemType >::~Queue()
{
	Node< ItemType > *tempPtr;
	
	while ( queuePtr != nullptr)
	{
		tempPtr = queuePtr;         
        queuePtr = queuePtr->nextPtr;
        delete tempPtr;
    }

	rearPtr = nullptr;
}


// Insert a node at the front of the Queue
template< class ItemType >
bool Queue< ItemType >::enqueue( const ItemType &value )
{
   Node< ItemType > *newPtr = new Node< ItemType>( value );

   if (newPtr == nullptr)		//failure to allocate new node
	   return false;
   else {

	  if ( rearPtr == nullptr )   // Queue is empty
         queuePtr = newPtr;
	  else
		 rearPtr->nextPtr = newPtr; // Queue is not empty

	  rearPtr = newPtr;
      
	  return true;		// enqueue is successful
   }
}
template< class ItemType >
bool Queue< ItemType >::front( ItemType &value )
{
   if ( isEmpty() )             // List is empty
      return false;             // getting front item is unsuccessful
   else {

	  value = queuePtr->info;  // value is set to the front item in the queue

      return true;            // successful in getting front item
   }
}


// Delete a node from the front of the list
template< class ItemType >
bool Queue< ItemType >::dequeue(  )
{
   if ( isEmpty() )             // List is empty
      return false;             // delete unsuccessful
   else {
      Node< ItemType > *tempPtr = queuePtr;

      queuePtr = queuePtr->nextPtr;

	  if (queuePtr == nullptr)
		  rearPtr = nullptr;

      delete tempPtr;
      return true;            // delete is successful
   }
}


// Is the Queue empty?
template< class ItemType > 
bool Queue< ItemType >::isEmpty() const
	{ return (queuePtr == nullptr); }

// Is the Queue full?
template< class ItemType > 
bool Queue< ItemType >::isFull() const 
{
	Node< ItemType > *newPtr = new Node< ItemType >;

   if (newPtr == nullptr)		//failure to allocate new node
	   return true;

   else {
	   delete newPtr;
	   return false;
   }
}



#endif


