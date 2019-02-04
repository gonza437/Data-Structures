//=========================================================
//Your name: Omar Gonzalez Martinez
//Complier:  g++
//File type: client program (tester) 
//===========================================================
using namespace std;

#include <iostream>
#include "llist.h"

void caseOne()
{
  cout << "CASE 1:------------------- " << endl;
  llist L;   // this is my list                                
  int x;  // to hold a removed element
       
  //1 check empty and report the resul                  
  cout << "Number 1: Check If Empty" << endl;
  if (L.isEmpty())
    {cout << "List is empty"<<endl;}
  else
    {cout << "List has elements" << endl;}

  //2 display the list
  cout << endl << "Number 2: Display List" << endl;
  L.displayAll();

  //3 add 4 integers 1,2,3,4
  cout << endl << "Number 3: Add To The Rear" << endl;
  L.addRear(1);
  L.addRear(2);
  L.addRear(3);
  L.addRear(4);
  cout << "Number's 1,2,3,4 were added" << endl;

  //4 display the list
  cout << endl << "Number 4: Display List" << endl;
  L.displayAll();

  //5 remove from front twice (and display the elements removed)
  cout << endl << "Number 5: Delete Twice From The Front" << endl;
  L.deleteFront(x);
  cout  << x << " was deleted from the front" << endl;
  L.deleteFront(x);
  cout << x << " was deleted from the front" << endl;

  //6 display the list
  cout << endl << "Number 6: Display List" << endl;
  L.displayAll();

  //7 check empty and report the result
  cout << endl <<  "Number 7: Check If Empty" << endl;
  if (L.isEmpty())
    {cout << "List is empty" << endl;}
  else
    { cout << "List has elements" << endl;}
  

  //8 remove from the rear twice (display the element removed
  cout << endl << "Number 8: Delete From Rear Twice" << endl;
  L.deleteRear(x);
  cout << x << " was deleted from the rear" <<  endl;
  L.deleteRear(x);
  cout << x << " was deleted from the rear" << endl;

  //9 check empty again and report the result
  cout << endl << "Number 9: Check If Empty" << endl;
  if (L.isEmpty())
    {cout << "List is empty"<<endl;}
  else
    {cout << "List has Elements" << endl;}
  cout << endl;
}//end of case 1       

void caseTwo()
{
  cout << "Case 2: -----------------------" << endl;
  llist L2;  // another list 
  int x;   // to hold the removed element
  int c = 1;  // displayed step number

  // 1.add to front once   (element 5)
  cout << endl << "Number " << c << ": Add To Front" << endl; c++;
  L2.addFront(5);
  cout << "5 was added to the front" << endl;
  
  // 2.add to front again  (element 4)
  cout << endl << "Number " <<  c << ": Add To Front" <<  endl; c++;
  L2.addFront(4);
  cout << "4 was added to the front" << endl;

  // 3.delete Front
  cout << endl << "Number " <<  c << ": Delete Front" << endl; c++;
  L2.deleteFront(x);
  cout << x << " was delete from the front" << endl;

  // 4.add to rear 3 times (elements 6,8,9)
  cout << endl << "Number " << c << ": Add To Rear 3 Times" <<  endl; c++;
  L2.addRear(6);
  L2.addRear(8);
  L2.addRear(9);
  cout << "6, 8, 9 were added" << endl;

  // 5. display all
  cout << endl << "Number " << c << ": Display List " <<  endl; c++;
  L2.displayAll();
 
  // 6.add before the 1st  (element 4) . 4 5 6 8 9
  cout << endl << "Number " <<  c << ": Add Before Position 1" << endl; c++;
  L2.addbeforeIth(1,4);
  cout << "4 was added before position 1" << endl;

  // 7.add before the 4th  (element 7) . 4 5 6 7 8 9 
  cout << endl << "Number " <<  c << ": Add Before Position 4 " << endl; c++;
  L2.addbeforeIth(4,7);
  cout << "7 was added to position" << endl;

  // 8.add before the 7th  (element 10) . 4 5 6 7 8 9 10
  cout << endl << "Number " <<  c << ": Add Before Position 7" <<  endl; c++;
  L2.addbeforeIth(7,10);
  cout << "10 was added to position 7" << endl;
  
  // 9.add before the 9th  (element 12) . error (out of range)
  cout << endl << "Number " << c << ": Add Before Position 9" << endl; c++;
  try{L2.addbeforeIth(9,12);}
  catch(llist::OutOfRange){cout<< "ERROR: Out of Range" << endl;}

  // 10.add before the 0th (element 0) . error (out of range)
  cout << endl << "Number " << c << ": Add Before Position 0" <<  endl; c++;
  try{L2.addbeforeIth(0,0);}
  catch(llist::OutOfRange){cout << "ERROR: Out of Range" << endl;}

  // 11.displayAll
  cout << endl << "Number " << c << ": Display List" << endl; c++;
  L2.displayAll();

  // 12.delete Ith I==1 (indicate  the element removed) . 5 6 7 8 9 10
  cout << endl << "Number " << c << ": Delete Position 1" <<  endl; c++;
  L2.deleteIth(1,x);
  cout << x <<" was deleted from position 1" << endl;

  // 13.delete Ith I==6 (indicate the element removed)  - 5 6 7 8 9
  cout << endl << "Number " << c << ": Delete Position 6" <<  endl; c++;
  L2.deleteIth(6,x);
  cout << x <<" was deleted from position 6" << endl;

  // 14.delete Ith I==3 (indicate the element removed)  - 5 6 8 9
  cout << endl << "Number " <<  c << ": Delete position 3" << endl; c++;
  L2.deleteIth(3,x);
  cout << x <<" was deleted from position 3" << endl;

  // 15.delete Ith I==5 . error (out of range)
  cout << endl << "Number " << c << ": Delete Position 5" << endl; c++;
  try {L2.deleteIth(5,x);}
  catch(llist::OutOfRange){cout << "ERROR: Out of Range" <<endl; }

  // 16.delete Ith I==0 . error (out of range)
  cout << endl << "Number " << c << ": Delete Position 0 " <<  endl; c++;
  try {L2.deleteIth(16,x);}
  catch(llist::OutOfRange){cout << "ERROR: Out of Range" << endl;}

  // 17.displayAll
  cout << endl << "Number " <<  c << ": Display List " <<  endl; c++;
  L2.displayAll();

  // 18.delete from rear until it is empty (indicate the elements removed)
  cout << endl << "Number " <<  c << ": Delete Rear Until Empty " <<  endl; c++;
  while(!L2.isEmpty())
    {
      L2.deleteRear(x);
      cout << x << " was deleted from the rear" <<endl;
    }

  // 19.displayAll
  cout << endl << "Number " <<  c << ": Display List" << endl; c++;
  L2.displayAll();
  
  cout << endl;

}//end of case 2        

void caseThree()
{
  cout << "Case 3:-------------------- " << endl;
  llist L3;
  int x;  // to hold the removed element

  // 1.add before the 0th . error (out of range)
  cout << "Number 1: Add Before position 0 " << endl;
  try {L3.addbeforeIth(0,x);}
  catch (llist::OutOfRange){cout << "ERROR: Out of Range" << endl;}

  //2.delete front . error (underflow)
  cout << endl <<  "Number 2: Delete Front"  << endl;
  try {L3.deleteFront(x);}
  catch (llist::Underflow){cout << "ERROR: Underflow" << endl;}
  
  cout << endl;
}   //end of case 3   

void caseFour()
{
  cout << "Case 4:------------------------ " << endl;
  llist L4;
  int x;  // to hold the removed element

  // 1.delete 2nd . error (out of range)
  cout << "Number 1: Delete Position 2" << endl;
  try {L4.deleteIth(2,x);}
  catch (llist::OutOfRange){cout << "ERROR: Out of Range" << endl;}

  // 2.delete rear . error (underflow)                                                 
  cout << endl << "Number 2: Delete Rear"  << endl;
  try {L4.deleteRear(x);}
  catch (llist::Underflow){cout << "ERROR: Underflow" << endl; }
  cout << endl;
} // end of case 4    


//PURPOSE of the Program: **                                                          
//Algorithm/Design: 4 test cases are divided into 3 functions and **                  
int main()
{
  int selection; // this will indicate what the user wants to do
   do
     {
       cout << endl << "MENU: These are your options: " << endl << endl;
       cout << "   (1) Case 1  " << endl;
       cout << "   (2) Case 2  " << endl;
       cout << "   (3) Case 3  " << endl;
       cout << "   (4) Case 4 " << endl;
       cout << "    Enter ( 0 ) to quit " << endl;
       cout << "===>";

       cin >> selection;

       switch(selection)
	 {
	 case 1: caseOne(); break;
	 case 2: caseTwo(); break;
	 case 3: caseThree(); break;
	 case 4: caseFour(); break;
	 }
     }
   while(selection !=0);

}// end of main
