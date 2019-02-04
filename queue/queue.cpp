//=========================================================
//HW#: HW1P1 queue
//Your name: Omar Gonzalez Martinez
//Complier:  g++ compiler
//File type: queue implementation file
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"  

//PUPOSE:  Constructor initialize count, frontr to 0  and rear to -1 
queue::queue()
{
  count = 0;
  front = 0;
  rear = -1;
}

//destructor 
queue::~queue()
{}     //Does nothing

// PURPOSE: To check if the queue is empty
//AlGORITHM: returns true if count is equal to 0, otherwise false
bool queue::isEmpty()
{
  if(count == 0)
    {return true;}
  else
    {return false;}
}

// PURPOSE: to check if the queue is full
//AIGORITHM: if count is equal to the MAX_SIZE return true
//         otherwise false
bool queue::isFull()
{
  if(count == MAX_SIZE)
    {return true;}
  else
    {return false;}
}

// PURPOSE: To add an element  to the queue
// PAREMETER: provide the element (newElem) to be added
//AIGORITHM: if full, throws an exception Overflow
// if not full, enters an element at the rear, count is increment   
void queue::add(el_t newElem)
{
  if(isFull())
    {throw Overflow();}
  else
    {
      rear  =(rear +1)% MAX_SIZE;
      el[rear] = newElem;
      count++;
    }
}

// PURPOSE: To remove the element and change front to the next slot 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
//AlGORITHM: if empty, throw Underflow 
// if not empty, removes the front element to give it back
void queue::remove(el_t& removedElem)
{
  if(isEmpty())
    {throw Underflow();}
  else
    {
      removedElem = el[front];
      front = (front +1) %MAX_SIZE;
      count--;
    }
}

// PURPOSE: To return the front element passby ref
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
//AlGORITHM: //if empty, throws an exception Underflow 
// if not empty, give back the front element (but does not remove it) 
void queue::frontElem(el_t& theElem)
{
  if(isEmpty())
    {throw Underflow();}
  else 
    {theElem = el[front];}
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{return count;}

// PURPOSE: display everything in the queue horizontally from front to rear
// enclosed in []
//AlGORITHM: if the queue is empty display "empty"
//      elseUsing a for loop to display each element in the queue
void queue::displayAll()
{ 
  if(isEmpty())
    {cout << "[ empty ]" << endl;}
  else
    {
      cout << "[";
      int x = front;       //variable used to move through the queue
      for(int i = 0; i < count; i++)
        {
          cout << el[x]  << " ";
          x = (x+1) % MAX_SIZE;
        }
      cout << "]" << endl;
    }
}

// PURPOSE: To move the front element to the back
//AlGORITHM: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//doing remove followed by add.
void queue::goToBack()
{
  if(isEmpty())
    {throw Underflow();}
  else 
    {
      el_t x;      // element that will be removed and then added to the top
      remove(x);
      add(x);
    }
}
