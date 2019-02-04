// =======================================================
// HW#: HW3P1 llist
// Your name: Omar Gonzalez Martinez
// Compiler:  g++ 
// File type: headher file 
//=======================================================

//----- Globally setting up the alias and struct  ----------------
typedef int el_t;  // elements will be int

//a list node is defined here as a struct Node
// I could have done class Node and add the data members under public
// but it would use too much space
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{  
  //private:
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes
   
 public:
  // Exception handling classes 
  class Underflow{};   //thrown when list is empty
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //PURPOSE: To chech if the list is empty
  bool isEmpty();
    
  //PURPOSE: To display all the elements in the list
  void displayAll();

  //PURPOSE: To add a new elememt to the rear of the list   
  // PARAMETER: Provide variable to received from client 
  void addFront(el_t);
    
  //PURPOSE: To add a new elememt to the rear of the list
  // PARAMETER: Provide variable to received from client    
  void addRear(el_t);

  //PURPOSE: To delete the front element in the list and pass by ref the element deleted
  // PARAMETER: Provide variable to received (pass by ref)  
  void deleteFront(el_t&);
    
  //PURPOSE: To delete the last element in the list and pass by ref the element deleted
  // PARAMETER: Provide variable to received (pass by ref)      
  void deleteRear(el_t&);
    
  //PURPOSE: To delete a elemnet in the list from any position
  //PARAMETER: int type (position users wants to delete an el_t type provide variable to receive (pass by ref)  
  void deleteIth(int, el_t&);

  //PURPOSE: To add a element in any position in the list   
  //PARAMETER: int type (position users wants to delete an el_t type provide variable to receive (pass by ref) 
  void addbeforeIth(int, el_t);
};
