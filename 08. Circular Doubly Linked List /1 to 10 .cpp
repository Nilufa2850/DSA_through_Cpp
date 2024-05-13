/*                      Assignment-8: Circular Doubly Linked List

1. Define a class CDLL to implement Circular Doubly linked list data structure with
member variable start pointer of type node.
2. In question 1, define a constructor to initialise start pointer with NULL
3. In question 1, define a method to insert a data into the list at the beginning.
4. In question 1, define a method to insert a data into the list at the end
5. In question 1, define a method to search a node with the give item.
6. In question 1, define a method to insert a data into the list after the specified node of the list.
7. In question 1, define a method to delete first node from the list.
8. In question 1, define a method to delete last node of the list.
9. In question 1, define a method to delete a specific node.
10. In question 1, define a destructor to deallocates memory for all the nodes in the linked list.*/

#include<iostream>
#include<stdio.h>
using namespace std ;
class node
{
    public :
        node *prev ;
        int item ;
        node *next ;
};
class CDLL
{
    private :
        node *start ;
    public :
        //10
        ~CDLL ()
        {
            while (start)
                delete_first() ;
        }
        //9
        void delete_specific (node *temp)
        {
            if (temp)
            {
                if (start == start->next)
                {   //when single node present
                    delete start ;
                    start = NULL ;
                }
                else
                {
                    node *t = start ;
                    while (t->next != temp)
                        t = t->next ;
                    t->next = temp->next ;
                    temp->next->prev = t ;
                    if (start == temp)
                        //when temp is 1st node
                        start = temp->next ;
                    delete temp ;
                }
            }
        }
        //8
        void delete_last ()
        {
            if (start)
            {
                if (start == start->next)
                {   //when single node present
                    delete start ;
                    start = NULL ;
                }
                else
                {
                    node *t = start->prev ;
                    t->prev->next = start ;
                    start->prev = t->prev ;
                    delete t ;
                }
            }
        }
        //7
        void delete_first ()
        {
            if (start)
            {
                if (start == start->next)
                {
                    //when single node present
                    delete start ;
                    start = NULL ;
                }
                else
                {
                    node *t = start ;
                    start->next->prev = start->prev ;
                    start->prev->next = start->next ;
                    start = t->next ;
                    delete t ;
                }
            }
        }
        //6
        void insert_after (node *temp , int data)
        {
            if (temp)
            {   //when list is non empty 

                node *n = new node ;
                n->item = data ;
                n->prev = temp ;
                n->next = temp->next ;

                if (temp->next == start)
                {
                    //when temp is last node
                    temp->next = n ;
                    start->prev = n ;
                }
                else
                {
                    temp->next->prev = n ;
                    temp->next = n ;
                }
            }
        }
        //5
        node* search ( int data)
        {
            if (start)
            {   //when list is non empty
                node *t = start ;
                do
                {
                    if (t->item == data)
                        return t ;
                    t = t->next ;
                }
                while (t != start ) ;
            }
            return NULL ;
        }
        //4
        void insert_last (int data)
        {
            node *n = new node ;

            if (start==NULL)
            {   //when list is empty
                n->item = data ;
                n->prev = n ;
                n->next = n ;
                start = n ;
            }
            else
            {   //when list is non empty & node>1
                n->item = data ;
                n->prev = start->prev ;
                n->next = start ;
                start->prev->next = n ;
                start->prev = n ;
            }
        }
        //3
        void insert_first (int data)
        {
            node *n = new node ;
            n->item = data ;

            if (start == NULL)
            {   
                    //when list is empty
                n->next = n ;
                n->prev = n ;
                start = n ;
            }
            else    //when list is non empty 
            {
                n->next = start ;
                n->prev = start->prev ;
                start->prev->next = n ;
                start->prev = n ;
                start = n ;
            }
            
        }
        //2
        CDLL () { start = NULL ;}
        void show()
        {
            if (start == start->next)
                //when single node 
                cout<<start->item<<"  " ;
            else 
            {   //when 1<node
                node *t = start ;
                while (t->next != start)
                {
                    cout<<t->item<<"  " ;
                    t = t->next ;
                }
                cout<<t->item<<endl ;

            }
        }
} ;
