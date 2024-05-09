/*1. Define a class DLL to implement singly linked list data structure with member
     variable start pointer of type node.
2. In question 1, define a constructor to initialise start pointer with NULL.
3. In question 1, define a method to insert a data into the list at the beginning.
4. In question 1, define a method to insert a data into the list at the end
5. In question 1, define a method to search a node with the give item.
6. In question 1, define a method to insert a data into the list after the specified node of the list.
7. In question 1, define a method to delete first node from the list.
8. In question 1, define a method to delete last node of the list.
9. In question 1, define a method to delete a specific node.
10. In question 1, define a destructor to deallocates memory for all the nodes in the linked list.*/

#include<iostream>
using namespace std ;
class node
{
    public :
        node* prev ;
        int item ;
        node* next ;
} ;

class DLL
{
    private:
        node* start ;
    public :
    
        ~DLL ()
        {
            while (start)
                delete_1st() ;
        }

        void delete_specific (node* ptr)        //9
        {
            if (ptr->prev)
                ptr->prev->next = ptr->next ;
            else
                start = ptr->next ;
                
            if (ptr->next)
                ptr->next->prev = ptr->prev ;

            delete ptr ;
            /*my process
            if (ptr == start)
            {
                delete_1st() ;
            }
            else if (ptr->next == NULL)
            {
                delete_last() ;
            }
            else
            {
                if (ptr != NULL)
                {
                    ptr->prev->next = ptr->next ;
                    ptr->next->prev = ptr->prev ;
                    delete ptr ;
                }
            }*/
        }

        void delete_last () //8
        {
            if (start == NULL)
                cout<<"\nList is Empty" ;

            else if (start ->next == NULL)
            {
                delete start ;
                start = NULL ;
            }
            else
            {
                node *t ;
                t=start ;
                while (t->next != NULL)
                    t = t->next ;

                t->prev->next = NULL ;
                delete t ;
            }
        }

        void delete_1st ()  //7
        {
            if (start == NULL)
                cout<<"\nList is Empty" ;
            else
            {
                node* t ;
                t = start ;

                start = t->next ;

                if (t->next)
                    start->prev = NULL ;

                delete t ;
            }
        }

        void insert_specific (node* ptr , int data) //6
        {
            if (start == NULL)
            {
                cout<<"\nInvalid node address" ;
            }
            else if (ptr) //or if(ptr != NULL)
            {
                node *n = new node ;
                n->item = data ;
                n->prev = ptr ;

                if (ptr->next == NULL)
                    n->next = NULL ;
                else
                {
                    n->next = ptr->next ;
                    ptr->next->prev = n ;
                }
                ptr->next = n ;
            }
        }

        node* search (int data)  //5
        {
            node* t ;
            t = start ;
            while (t!= NULL)
            {
                if (t->item == data)
                    return t ;
                t = t->next ;
            }   
            return NULL ;  //or return t ;
        }

        void insert_last (int data) //4
        {
            node* t ;
            node * n = new node ;

            if (start == NULL)
            {
                n->item = data ;
                n->next = NULL ;
                n->prev = NULL ;
                start = n ;
            }
            else
            {
                n->item = data ;
                n->next = NULL ;
                
                t = start ;
                while (t->next != NULL)
                    t = t->next ;
                
                n->prev = t ;

                t->next = n ;
            }
        }

        void insert_start (int data) //3
        {
            node *n = new node ;
            n->item = data ;
            n->prev = NULL ;
            n->next = start ;

            if (start)  //or if (start != NULL)
                start ->prev = n ;
                
            start = n ;
        }
        
        DLL () {start = NULL ; }  //2
};
