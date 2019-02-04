//=========================================================
//HW#: HW1P1 queue
//Your name: Omar Gonzalez Martinez
//Complier:  g++ complier
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include "queue.h"

//Purpose of the program: To generate a sequence from the string ABC
//Algorithm: Using a while loop, until variable invalid is true, to start the sequence and to retrive the front element in the queue list
//         for loop takes each element in the char array and adds it to another string

int main()
{// A, B, C in the queue
  queue MyList;                //List used for the sequence
  string alpha = "012";        //Base of the string sequence
  string frontLetter, back;    //Variables used to create the sequence list
  bool invalid = false;        //Use to stop the while loop
  int front = 0;               //Where the front element is in the list
  int rear = -1;               //Wher the last element is in the list
 

  while(!invalid) //loop -- indefinitely
    {
      try
      	{
	  for(int i = 0; i < alpha.length(); i++)    //for used to  create the sequence and list
	    {
	      char item = alpha[i];      //Each element of the string
	      back = "\0";               //Restart the list
	      if(front != 0)
		{back = frontLetter;}    //Restart the list with the front element
		
	      frontLetter += item;       //Add to the sequence
	      MyList.add(frontLetter);   //Add new string to the queue
	      frontLetter = back;        //Restart the list
	      
	      
	      ++rear;
	      if(rear >= 25)            //Keep track of the last element in the list
		{
		  rear = (rear+1) % 25;
		  rear -= 1;
		}
	    }
	    
	  //Using cout to display the size of the list, where the front and last element are
	  cout << "Count = " << MyList.getSize() << "  ";
	  cout << "Front = " << front << "  ";
          cout << "Rear = " << rear << endl;

	  // MyList.displayAll();          //Display the list
	  MyList.remove(frontLetter);   //Retrive the front element 
	  cout << frontLetter << endl;  //Display the front element
    	}

      //Catch exceptions and report problems and quit the programs now
      //Error message describles what is wrong with the expression
      catch(queue::Overflow)
	{invalid = true; cout << "Error: Too many values" << endl;}
      catch(queue::Underflow)
	{invalid = true; cout << "Error: List is empty" <<  endl;}

      //go back to the loop after incrementing
      front++;
    }
  return 0; //End of program
}

