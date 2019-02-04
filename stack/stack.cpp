//=========================================================
//HW#: HW1P1 stack
//Your name: Omar Gonzlez Martinez
//Complier:  g++
//File type: stack implementation file
//=========================================================

using namespace std;  
#include <iostream>
#include "stack.h"

//PURPOSE:  Constructor must initialize top to be -1 to begin with.
stack::stack()
{ top = -1;} // indicate an empty stack }
  
//PURPOSE:  Destructor does not have to do anything since this is a static array.
stack::~stack()
{} // nothing to do }
  
//PURPOSE:  checks top and returns true if empty, false otherwise.
////ALGORITHM: If the element top is equal to -1 then the array is empty and will return true
//     otherwise the function will return false 
bool stack::isEmpty()
{ if (top == -1)
    return true;
  else
    return false; 
}
    
//PURPOSE: checks top and returns true if full, false otherwise.
//ALGORITHM: If top is equal to one less than the element then the array is full and will return true
//     otherwise the function will return false      
bool stack::isFull()
{ if (top == MAX-1 )
    return true;
  else
    return false;
}
  
//PURPOSE: calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
//PARAMETER: pass the element (elem) to be pushed 
void stack::push(el_t elem)
{ if (isFull())
    {
      throw Overflow();
    }
  else
    { top++; el[top] = elem; }
}
 
//PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
//  Otherwise, removes an element from el and gives it back.
//PARAMETER: provide a holder (elem) for the element popped (pass by ref)
//ALGORITHM: Using if else to check if the stack is empty. If stack is empty then nothing can be popped, throw Underflow
//    else the stcak is is not empty and the top element in the stack will be removed and returned pass by ref
void stack::pop(el_t& elem)
{ if (isEmpty())
    {
      throw Underflow();
    }
  else { elem = el[top]; top--;}  
}
 
// PURPOSE: calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
//PARAMETER: provide a holder (elem) for the element (pass by ref)
////ALGORITHM: Using if else to check if the stack is empty. If the stack is empty then nothing can be done so throw Underflow
//    else the stack is not empty and the current top element in the stack will be returned using pass by redf
void stack::topElem(el_t& elem)
{ if (isEmpty())
    {
      throw Underflow();
    }
  else { elem = el[top]; }
}
 
//PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
//          Otherwise, diplays the elements vertically.
//ALGOITHM: if the stack is empty cout empty
//     else Using a for loop to display each element in the stack starting from the last 
void stack::displayAll()
{  if (isEmpty())
    cout << "[ empty ]" << endl;
  else for (int i=top; i>=0; i--)
    { cout << el[i] << endl; }
  cout << "--------------" << endl;
}
 
 
//PURPOSE: pops all elements from the stack to make it empty if it is not empty yet.
//ALGOITHM: Using a while loop to remove each of the elements in the stack one
//    by one unit top equals -1   
void stack::clearIt()
{
  el_t x;      //element that when be pop
  
  while(top != -1)
    {
      pop(x);
    }
}
