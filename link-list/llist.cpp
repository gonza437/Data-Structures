// ====================================================
//HW#: HW3P1 llist
//Your name: Omar Gonzalez Martinez
//Complier:  g++
//File type: llist implementation file
//=====================================================

using namespace std;

#include<iostream>
#include"llist.h" 

//PURPOSE: Constructor which will initialize front, rear, and count
//ALGORITHM: Initialize Front and Rear to be NULL and Count = 0.
//- This does not create any node.  The new list is empty.
llist::llist()
{
  Count = 0;
  Front = NULL;
  Rear = NULL;
}

//PURPOSE: Destructor which removes all the data in the list  
//ALGORITHM: While the list is not empty, call deleteFront repeatedly to delete all nodes.
//Please place a cout in this function "calling the llist desctructor."
llist::~llist()
{
  el_t x;      //local value used to store delete value
  while(!isEmpty())    //Using while loop   
    {deleteFront(x);}
  cout << "Calling the llist desctructor" << endl;
}
      
//PURPOSE: To check if the list is empty
//ALGORITHM: Return true if Front and Rear are both pointing to NULL and Count is 0.
// (all 3 conditions must be checked)
bool llist::isEmpty()
{
  if(Front ==NULL && Rear ==NULL && Count == 0)
    {return true;}
  else
    {return false;}
}


//PURPOSE: To display all the data in the link list
//ALGORITHM:Special case: if the list is empty, display [ empty ] )
//  - Regular case else: displays each element of the list horizontally starting from Front in [ ]
void llist::displayAll()
{
  if(isEmpty())
    {cout << "[ empty ]" << endl;}
  else
    {
      Node *p = Front;    //Local Node used in while loop to display elements in list
      while(p != NULL)    //Make p go to the one right before rear (using while)  
	{
	  cout << "[" << p->Elem << "] ";
	  p = p->Next;
	}
      cout << endl;
    }
}

//PURPOSE: To add a element into the back of the list
//PARAMETER: New element NewNum of type el_t  
//AlGORITHM: - Special case: if the first node, create a new node and make Front and Rear point to it. Place NewNum and Count is updated.
//           -  Regular: adds a new node at the rear and puts NewNum in the Elem field  of this new node. Count is updated.
void llist::addRear(el_t NewNum)
{
  if (isEmpty())
    { Front = Rear = new Node;}
  else
    {
      Rear->Next = new Node;
      Rear = Rear->Next;
    }

  Rear->Elem = NewNum;
  Rear->Next = NULL;
  Count++;
}

//PURPOSE: To add a element to the back of the list
//PARAMETER: New element NewNum of type el_t  
//AlGORITHM: Special case: if this is going to be the very first node, create a new node and make Front and Rear point to it. Place NewNum and Count is updated.
//           Regular: add a new node to the front of the list and Count is updated.
void llist::addFront(el_t NewNum)
{
  Node *x = new Node;    //Local value used to store Front when new elemnt is added
  x->Next = NULL;

  if(isEmpty())
    {Front = Rear = x;}
  else
    {  
      x->Next = Front;
      Front = x;
    }

  Front->Elem = NewNum;
  Count++;
}  

//PURPOSE: To delete the front element
//PARAMETER: Provide variable to received (pass by ref)  
//AlGORITHM: Error case: if the List is empty, throw Underflow
//     - Special case: if currently only one Node, give back the front node element through OldNum (pass by reference) and make sure both Front and Rear become NULL. Count is updated.
//     - Regular: give back the front node element through OldNum (pass by reference)  and also removes the front node.  Count is updated.
void llist::deleteFront(el_t& OldNum)
{
  if (isEmpty())
    {throw Underflow();}
  else if(Count == 1)
    {
      OldNum = Front->Elem;
      delete Front;
      Front = Rear = NULL;
    }
  else
    {
      OldNum = Front->Elem;
      Node *Second = Front->Next;       //Local value used to move Front to the next node when Front is deleted
      delete Front;
      Front = Second;
    }
  Count--;
}

//PURPOSE: To delete the last element in the list
//PARAMETER: Provide variable to received (pass by ref)
//AlGORITHM: Error case: if empty, throw Underflow
//     - Special case: if currently only one node, give back the rear node element through OldNum (pass by reference) and make sure both Front and Rear become NULL. Count is updated.
//      - Regular: give back the rear node element through OldNum (pass by reference) and also remove the rear node. Count is updated.
void llist::deleteRear(el_t& OldNum)
{
  if(isEmpty())
    {throw Underflow();}
  else if(Count == 1)
    {
      OldNum = Rear->Elem;
      delete Rear;
      Front = Rear = NULL;
    }
  else
    {
      OldNum = Rear->Elem;   
      Node *p = Front;           //Local value used to move through the list
      while(p->Next != Rear)     //Make p go to the one right before rear (using while)
	{p = p->Next;}

	delete Rear;
	Rear = p;
	Rear->Next = NULL;
    }
  Count--;
}


//PURPOSE: To delete a elemnet in the list from any position
//PARAMETER: int type (position users wants to delete an el_t type provide variable to received (pass by ref)   
//AlGORITHM: Error case:If I is an illegal value (i.e. > Count or < 1) throw OutOfRange.
//     - Special cases: this should simply call deleteFront when I is 1 or deleteRear when I is Count
//     - Regular: delete the Ith node (I starts out at 1).  Count is updated.
void llist::deleteIth(int I, el_t& OldNum)
{
  if(I > Count || I < 1)
    {throw OutOfRange();}
  else if(I == 1)
    {deleteFront(OldNum);}
  else if(I == Count)
    {deleteRear(OldNum);}
  else
    {
      Node* pre = Front;   //Local value used to store previous node
      Node* del = pre->Next;   //Local value used to store delete node
      int x = 2;   //Local value used to move through he list unitl position is found

      while (x != I) // to move pointers to the next node until we find the node we want to delete                                                                               
	{
	  pre = del;
	  del = del->Next;
	  x++;
	}

      OldNum = del->Elem;
      pre->Next = del->Next;

      delete del; 
      Count--;                 
    }
}

      
//PURPOSE: To add a element in any position in the list
//PARAMETER: int type (position users wants to delete an el_t type provide variable to received (pass by ref)
//AlGORITHM: Error case: If I is an illegal value (i.e. > Count+1 or < 1) throw OutOfRange.
//    -  Special cases: this should simply call addFront when I is 1 or addRear when I is Count+1
//    -  Regular: add right before the Ith node. Cout if updated.
void llist::addbeforeIth(int I, el_t newNum)
{
  if(I > (Count+1) || I <  1)
    {throw OutOfRange();}
  else if(I == 1)
    {addFront(newNum);}
  else if(I == (Count + 1))
    {addRear(newNum);}
  else
    {
      Node *temp = new Node;      //Local value used that will be added to the list
      Node *p = Front;            //Local value used that will be used to move through the loop

      for(int x = 2; x <= (I-1); x++)   //for loop used to move through loop
	{p = p->Next;}

      temp->Next = p->Next;
      temp->Elem = newNum;
      p->Next = temp;
      Count++;
    }
}
