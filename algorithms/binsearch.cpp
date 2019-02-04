//=================================================================================================
//NAME: Omar Gonzalez Martinez
//Complier: g++ complier
//File Tpye: client Binary Search tree
//================================================================================================
#include<iostream>

using namespace std;

int const SIZE = 10;

//List of prototype
int binSearch(int list[], int num);      //Find the position a number in the list

int main()
{
  int myList[SIZE] = {1,3,5,7,9,11,13,15,17,19};   //integer list
  int num, index;    //integer num is the number the user is looking for; index is the position

  cout << "What number are you looking for: ";
  cin >> num;

  index = binSearch(myList, num);     //Using binary Search to find the position
  
  if(index != -1)
    {cout << num << " is in position " << ++index << endl;}
  else
    {cout << num << " was not found" << endl;}

  return 0;
}

//PURPOSE: Find the position of a integer in the list
//PARAMETER: int array and the number the user is looking for
//AlGORITHM: Using a while loop to binary search 
int binSearch(int list[], int num)
{
  int first = 0, last = SIZE-1;   
  
  int middle = (first + last)/2;
  bool found;                       //bool varible to stop the loop
  int size = SIZE;                  

  while(size != 0 && !found)
    {
      if(num == list[middle])
	{found = true;}
      else if(num < list[middle])
	{last = middle-1;}
      else if(num > list[middle])
	{first = middle+1;}

      middle = (first + last)/2;
      size /=2;
    }

  if(found)
    {return middle;}
  else
    {return -1;}
}
