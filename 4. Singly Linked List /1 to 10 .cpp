/*1. Define a class SLL to implement singly linked list data structure with member
variable start pointer of type node.*
2. In question 1, define a constructor to initialise start pointer with NULL.
3. In question 1, define a method to insert a data into the list at the beginning.
4. In question 1, define a method to insert a data into the list at the end
5. In question 1, define a method to search a node with the give item.
6. In question 1, define a method to insert a data into the list after the specified node of the list.
7. In question 1, define a method to delete first node from the list.
8. In question 1, define a method to delete last node of the list.
9. In question 1, define a method to delete a specific node.
10. In question 1, define a destructor to deallocates memory for all the nodes in the linked list.*/

#include <iostream>

using namespace std ;

class Node
{
    public :
        int Item ;
        Node * Next ;
} ;

class SLL 
{
    private :
        Node *start ;
    public :
        SLL () { start = nullptr ;  }       //2

        void Insert_Start (int data)    //3
        {
            Node* temp = new Node ;
            temp -> Item = data ;
            temp -> Next = start ; 
            start = temp ;
        }
        
        void Insert_End (int data)          //4
        {
            Node *n = new Node ;
            n -> Item = data ;
            n -> Next = nullptr ;

            if (start == nullptr)
                start = n ;
            else
            {
                Node * t ;
                t = start ;

                while (t->Next != NULL)
                    t = t->Next ;
                
                t->Next = n ;
            }
        }

        Node* search_Node (int data)        //5
        {
            
            Node *t ;
            t = start ;
            while (t != NULL)
            {
                if (t->Item == data)
                {
                    cout<<"\nData found" ;
                    return  t ;
                }
                t = t->Next ;
            }
            return NULL ;
            
        }

        void Insert_Specified (Node* ptr , int data)    //6
        {
            Node * n = new Node ;
            n ->Item = data ;
            n-> Next = ptr ->Next ;
            ptr->Next = n ;
        }
    
        void del_1st_node ()                //7
        {
            Node *t ;
            if (start != NULL) //or if (Start)
            {
                t = start ;
                start = t->Next ; //or start = start->Next ;
                delete t ;
            }
            else
                cout<<"\nList empty" ;
        }
        
        void del_last_node ()                //8
        {
            if (start == NULL)
            {
                cout<<"\nEmpty list" ;
            }
            else if (start->Next == NULL)
            {
                delete start ;
                start = NULL ;
            }
            else
            {
                Node *p , *t ;
                t = start ;
                while (t->Next != NULL)
                {
                    p = t ;
                    t = t->Next ;
                }

                delete t ;
                p->Next = NULL ;
            }
            

            /*if (start->Next == NULL)
            {
                delete start ;
                start = NULL ;
            }
            
            else
            {
                Node* t ;
                t = start ;

                while (t->Next->Next != NULL)
                    t = t->Next ;

                delete t->Next ;
                t->Next = NULL ;
            }*/
        }
        
        void del_Specified_node (Node *temp)                //9
        {
            Node *t ;

            if (start == NULL)
                cout<<"\nList Empty" ;

            else 
            {
                if (temp != NULL)
                {
                    if (start = temp)
                    {
                        start = NULL ;
                        delete temp ;
                    }
                    else
                    {
                        t = start ;
                        while (t->Next != temp)
                            t = t->Next ;

                        t->Next = temp->Next ;
                        delete temp ;

                    }
                }
            }
        }
        
        ~SLL ()                             //10
        {
            while (start != NULL)
                del_1st_node() ;
        }
} ;
