/*                  Assignment-6: Circular Linked List

1. Define a class CLL to implement Circular linked list data structure with member
    variable last pointer of type node.
2. In question 1, define a constructor to initialise last pointer with NULL.
3. In question 1, define a method to insert a data into the list at the beginning.
4. In question 1, define a method to insert a data into the list at the end. 
5. In question 1, define a method to search a node with the give item.
6. In question 1, define a method to insert a data into the list after the specified node of the list.
7. In question 1, define a method to delete first node from the list.
8. In question 1, define a method to delete last node of the list.
9. In question 1, define a method to delete a specific node
10. In question 1, define a destructor to deallocates memory for all the nodes in the linked list. */

#include<iostream>
#include<stdio.h>
using namespace std ;

class node 
{
    public :
        int item ;
        node *next ;
} ;
class CLL
{
    private :
        node *last ;
    public :

        ~CLL()                                              //10
        {
            while (last)
                delete_1st() ;
        }

        void delete_specific (node *temp)                   //9
        {
            if (last)
            {
                if (last->next == last)
                    last = NULL ;
                else
                {
                    node *t ;
                    t = last->next ;

                    while (t->next != temp)
                        t = t->next ;
                    t->next = temp->next ;

                    if (last == temp)
                        last = t ;
                }

                delete temp ;
            }
        }

        void delete_last()                                  //8
        {
            if (last)
            {
                node *t , *p ;
                p = last ;
                if (p->next == last)
                    last = NULL ;
                else
                {
                    t = last->next ;
                    while (t->next != last)
                        t = t->next ;

                    t->next = last->next ;
                    last = t ;
                }
                delete p ;
            }
        }

        void delete_1st ()                                  //7
        {
            node *t ;
            if (last)
            {
                t = last->next ;
                if (last == t)
                    last = NULL ;
                else
                    last->next = t->next ;
                delete t ;
            }
            else
                cout<<"\nDeletion not possible , node empty" ;
        }

        void insert_specific (node *temp , int data)        //6
        {
            if (last)
            {
                node *n = new node ;
                n->item = data ;
                n->next = temp->next ;
                temp->next = n ;

                if (temp == last)
                    last = n ;
            }
        }

        node* search (int data)                             //5
        {
            if (last) //list is non empty
            {
                node *t ;
                t = last->next ;
                while (t != last)
                {
                    if (t->item == data)
                        return t ;
                    t = t->next ;
                }
                if (t->item == data)
                    return t ;
            }
            return NULL ; 

        }

        void insert_last (int data)                         //4
        {
            node *n = new node ;
            n->item = data ;

            if (last)
            {
                //when list is not empty
                n->next = last ->next ;
                last ->next = n ;
            }
            else //when list is empty
                n->next = n ;
            last = n ;
        }

        void insert_1st (int data)                          //3
        {
           node *n = new node ;
           n->item = data ;

           if (last == NULL)
           {
                //when list is empty
                n->next = n ;
                last = n ;
           }
           else
           {    //when list is not empty
                n->next = last->next ;
                last->next = n ;
           }
        }
        
        CLL() { last = NULL ;}                              //2
        
        void show_node ()
        {
            if (last == NULL)
                cout<<"\nempty" ;

            else if (last->next == last)
                cout<<last->item<<" " ;
            else
            {
                
                node *t = last->next ;
                while (t != last )
                {
                    cout<<t->item<<"  " ;
                    t = t->next ;
                }
                cout << t->item << " ";
            }
            cout<<endl ;
        }
} ;
