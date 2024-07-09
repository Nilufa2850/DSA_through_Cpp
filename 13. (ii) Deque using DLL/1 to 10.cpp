/*                      Assignment-13: Deque
1. Define a class Deque with node type pointers front and rear as member variables.
   Implement queue using doubly linked list.
2. In question 1, define a constructor to initialise member variables
3. In question 1, define a method to insert a new element at the front
4. In question 1, define a method to insert a new element at the rear.
5. In question 1, define a method to delete front element
6. In question 1, define a method to delete rear element
7. In question 1, define a method to get front element.
8. In question 1, define a method to get rear element
9. In question 1, define a destructor to deallocate the memory.
10. In question 1, define a method to check if deque is empty.*/    
#include<iostream>
using namespace std ;
class node
{
   public :
      node *prev ;
      int item ;
      node *next ;
} ;
class Deque 
{
   private : 
      node *front , *rear ;
   public :

      //Assignment operator 
      Deque& operator= (Deque&)
      {
         if (front!=NULL)
         {
            while (front)
               deleteFront() ;  // null initialize done by deletefront()
         }

         node *t = d.front ;
         while (t)
         {
            node *n = new node ;
            n->item = t->item ;
            n->prev = NULL ;
            n->next = front ;
            if (front) //when List is non empty
               front->prev = n ;
            else
               rear = n ; //when list is empty
               
            front = n ;

            t = t->next ;
         }
         return *this ;
         
      }

      //copy constructor 
      Deque (Deque &d)
      {
         front = rear = NULL ;

         cout<<"\ncopy Constructor called" ;
         node *t = d.front ;
         while (t)
         {
            node *n = new node ;
            n->item = t->item ;
            n->prev = NULL ;
            n->next = front ;
            if (front) //when List is non empty
               front->prev = n ;
            else
               rear = n ; //when list is empty
               
            front = n ;

            t = t->next ;
         }
      }

      void showNode ()
      {
         node *t = front ;
         while (t!=rear)
         {
            cout<<t->item<<"  " ;
            t= t->next ;
         }
         cout<<t->item ;
      }

      bool is_empty ()
      {
         return front==NULL ;
      }

      ~Deque ()
      {
         while (front) 
            deleteFront() ;
      }

      node* getRear ()
      {
         return rear ;
      }

      node* getFront ()
      {
         return front ;
      }

      void deleteRear ()
      {
         if (rear) // not empty 
         {
            node *t = rear ;
            if (rear == front)
               rear = front = NULL ;
            else
            {
               rear->prev->next = NULL ;
               rear = rear->prev ;
            }
            delete t ;
         }
      }

      void deleteFront ()
      {
         if (front) // not empty
         {
            node *t = front ;

            if (front == rear) // single node present
               front = rear = NULL ;
            else
            {
               front->next->prev = NULL ;
               front = front->next ;
            }
            delete t ; 
         }
         else
            cout<<"\nDeque is empty , not deletion possible" ;
      }

      void insertRear (int data)
      {
         node *n = new node ;
         n->item = data ;
         n->next = NULL ;
         n->prev = rear ;
         if (rear) // not empty
            rear->next = n ;
         else 
            front = n ; // when list is empty
         rear = n ;
      }

      void insertFront (int data)
      {
         node *n = new node ;
         n->item = data ;
         n->prev = nullptr ;
         n->next = front ;
         if (front) //not empty 
            front->prev = n ;
         else 
            rear = n ; // when list is mepty
         front = n ;
      }
      
      Deque ()
      {
         cout<<"\nConstructor called" ;
         front = rear = nullptr ;
      }
      
} ;





