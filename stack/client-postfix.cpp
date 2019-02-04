//=========================================================
//HW#: HW1P1 stack
//Your name: Omar Gonzalez Martinez
//Complier:  g++ complier
//File type: client program
//===========================================================
#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

//Purpose of the program: To solve one postfix expression 
//Algorithm: Ask user to enter a expression in a string variable; then Using a while loop to check
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  bool invalid = false;
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  
  while (expression[i] != '\0' && !invalid)
    {
      try
	{
	  item = expression[i];  // current char
	  
	  //2.  if it is an operand (number), 
	  //    push it (you might get Overflow exception)
	  if(isdigit(item))
	    {
	      int num = item - '0';
	      postfixstack.push(num);
	    }

	  //3.  else if it is an operator,
	  //    pop the two operands (you might get Underflow exception), and
	  //	apply the operator to the two operands, and
	  //    push the result.
	  else if ( (item == '+') || (item == '-') || (item == '*'))
	    {
	      postfixstack.pop(box1);
	      postfixstack.pop(box2);
	      int result;

	      //cases for different operators follow:
	      if (item == '-') result = box2-box1;
	      else if(item == '+') result = box2+box1;
	      else if(item == '*') result = box2*box1;
	      
	      // ** Finally push the result
	      postfixstack.push(result);
	    }
	  else
	    {
	      throw "Error: Invalid item ";
	    }
	} // this closes try
      
      // Catch exceptions and report problems and quit the program now. 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) 
	{invalid = true; cout << "Error: Expression is too long for the stack" << endl; }
      catch (stack::Underflow) // for too few operands
	{invalid = true; cout << "Error: Too few operands/numbers in the expression" << endl; }
      catch (char const* errorcode) // for invalid item
	{invalid = true; cout << errorcode << item << endl; }
      // go back to the loop after incrementing i
      i++;
    }// end of while
  
  // After the loop successfully completes: 
  // The result will be at the top of the stack. Pop it and show it.
  if(invalid == false && !postfixstack.isEmpty())
    {
      int answer;
      postfixstack.pop(answer);
      cout << "Your answer: " << answer << endl;
      
      // If anything is left on the stack, an incomplete expression was found.
      // Inform the user.
      if(!postfixstack.isEmpty())
	{
	  cout << "However your postfix expression is incomplete" << endl;
	  cout << "Remaining data" << endl;
	   postfixstack.displayAll();
	}
    }
  return 0;
}// end of the program
