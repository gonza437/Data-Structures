//=================================================================================================
//NAME: Omar Gonzalez Martinez
//COMPLIER: g++
//FILE TPYE:Merge Sort's Combine, 
//================================================================================================
#include<iostream>
#include<vector>
#include<string>
#include <stdlib.h>

using namespace std;

int SIZE;        //size of the list, Will be inputed later

//List of prototype
//===============================================================================================
void createArray(vector<int>& list);    //Will create the array of numbers
void combineArray(vector<int> list1, vector<int> list2, vector<int>& combine);//combine the two list
int onlyNumbers(string input);          //Function that check input ot see if it is a integer

int main()
{
  vector<int> myList1, myList2, combineList;       //three vector<int> list
  string input;                                   //The size of the list

  cout << "How many elemets would you like to enter: ";   
  getline(cin, input);        //User will enter the size of list

  SIZE = onlyNumbers(input);  //Function will check to see if input size is a integer
  
  //Create the two list
  createArray(myList1); 
  createArray(myList2);
   
  //Combine the list into one
  combineArray(myList1, myList2, combineList);
  
  //Display the combined list
  for(int i = 0; i < (SIZE*2); i++)
    {cout << combineList[i] << " ";}

  cout << endl;

  return 0;
}

//PURPOSE: Turn string input in a integer
//PARAMETER: String variable
//AlGORITHM: while error is true; enter for loop to check each of the elemets in the char array
//           if input varible is not a number end for loop by asking for new input
int onlyNumbers(string input)
{
  bool error = true;    //bool varible to stop loops when error happens
  while(error)
    {
      error = false;
      for(int i = 0; i < input.length() && !error; i++)
	{
	  if(isalpha(input[i]))
	    {error = true;
	      cout << "Error: invalid input try agian: ";
	      getline(cin, input);
	    }
	}
    }

  int amount = atoi(input.c_str());     //Convert string varible to a integer
  return amount;          //return amount
}

//PURPOSE: To create a list of integers
//PARAMETER: vector<int> varible
//AlGORITHM: Using while loop to keep entering elements until list is full  
void createArray(vector<int>& list)
{
  int i = 0, num;   //integer varibles
  string input;     //string varible
  cout << endl;
  while(i != SIZE)
      {
	i++;
   
	cout << "Enter " << i << " element: ";
	getline(cin, input);
	num = onlyNumbers(input);
     
	list.push_back(num);
      }
}

//PURPOSE: Combine the two list in order
//PARAMETER: Three vector<int> varibles
//AlGORITHM: 
void combineArray(vector<int> list1, vector<int> list2, vector<int>& combine)
{
  int i = 0, a = 0, b = 0;    //integer varibles use to keep track of postion
  int x, y;                   //Will store the element in lists
  bool done;

  while( a != SIZE && b != SIZE)
    {
      
	x = list1[a];
	y = list2[b];

	cout << x << " is being compared to " << y << endl;
	if(x < y)
	  {
	    combine.push_back(x);
	    a++;
	  }
	else
	  {
	    combine.push_back(y);
	    b++;
	}
	
	i++;
    }

  if(b != SIZE)
    {
      while(b != SIZE)
	{
	  x = list2[b];
	  combine.push_back(x);
	  b++;
	}
    }
  if( a != SIZE)
    {
      
      while(a != SIZE)
	{
	  x = list1[a];
	  combine.push_back(x);
	  a++;
	}
    }
}
