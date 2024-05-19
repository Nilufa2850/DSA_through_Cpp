/*          Assignment-7: Problems on Linked List

1. Define a method to count number of list items in the singly linked list.
2. Define a method to reverse a singly linked list
3. Define a method to find middle node of the singly linked list.
4. Define a method to check whether a linked list has a cycle or not.
5. Define a method to count length of the cycle in the linked list
6. Define a method to sort a linked list.
7. Define a method to merge two sorted linked list
8. Define a Polynomial class to implement polynomial using linked list
9. Define a method to add two polynomials.
10. You are given two non-empty linked lists representing two non-negative integers.
    The digits are stored in reverse order, and each of their nodes contains a single digit. 
    Add the two numbers and return the sum as a linked list. You may assume the two numbers 
    do not contain any leading zero, except the number 0 itself.*/

#include "4. SLL.cpp"
#include<iostream>
using namespace std ;

//1 
int count_items (SLL &obj)
{
    int count=0 ;
    Node *t ;
    t=obj.get_1s_node() ;

    while (t != NULL) 
    {
        count++ ;
        t=t->Next ;
    }

    return count ;
}
//2 
void reverse_list (SLL &obj)
{
    int i ;
    Node *temp,*t ;
    Node* starting = obj.get_1s_node() ;

    if (starting) // if (start)
    {
        if (starting->Next == NULL)
            return ;
        else
        {
            Node *t1 , *t2 , *t3 ;

            t1 = starting ;
            t2 = t1->Next ;
            t3 = t2->Next ;

            t1->Next = NULL ;

            while ( t2!=NULL)
            {
                t2->Next = t1 ;
                t1=t2 ;
                t2=t3 ;
                if (t3!=NULL)
                    t3 = t3->Next ;
            } 

            starting = t1 ;
        }
    }
}
//3
int middle_node (SLL &obj)
{
    Node *starting = obj.get_1s_node() ;
    if (starting==NULL )
        return  -1 ;
    else if (starting->Next==NULL || starting->Next->Next ==NULL)
        return starting->Item ;
    else
    {
        Node *t1, *t2 ;
        t1 = starting ;
        t2 = starting ;

        while (t2 != NULL && t2->Next !=NULL)
        {
            t1 = t1->Next ;
            t2 = t2->Next->Next ;
        }
        return t1->Item ;
    }
}
//4 
bool cycle_or_not (SLL &obj)
{
    Node *start = obj.get_1s_node() ;
    Node *t1 , *t2 ;
    t1 = start ;
    t2 = start ;

    while (t2!=NULL  &&  t2->Next!=NULL)
    {
        t2 = t2->Next->Next ;
        t1=t1->Next ;

        if (t1 == t2 )
            return true ;

    }  
    return false ;
}
//5 
int length_cycle (SLL &obj)
{
    Node *start = obj.get_1s_node() ;
    int length=0 ;
    Node *t1 , *t2 ;
    t1 = start ;
    t2 = start ;

    while (t2!=NULL  &&  t2->Next!=NULL)
    {
        t2 = t2->Next->Next ;
        t1 = t1->Next ;

        if (t1 == t2 )
            break ;
    }
    if (t1==t2)
    {
        do 
        {
            length++ ;
            t2 = t2->Next ;
        }
        while (t2 != t1) ;
        
        return length ;
    }
    return 0 ;
}
//6 
void sorting_linked_list (SLL &obj)
{
    Node *t1,*t2 ;

    int i , j ;
    int end_loop = count_items(obj) ;

    t1=obj.get_1s_node() ;

    for (i=0 ; i<end_loop-1 ; i++)
    {
        t2 = t1->Next ;

        for (j=i+1 ; j<end_loop ; j++)
        {
            if (t2 == NULL)
                break ;
            if (t1->Item > t2->Item)
                obj.swapping(t1,t2) ;

            t2 = t2->Next ;
        }

        t1 = t1->Next ;
        if (t1->Next == NULL || t1 == NULL )
            break ;
    }

}
//7
SLL merge_LL (SLL &a , SLL &b)
{
    sorting_linked_list(a) ;
    sorting_linked_list(b) ;

    Node *t1 , *t2 ;
    
    SLL obj ;

    t1 = a.get_1s_node() ;
    t2 = b.get_1s_node() ;

    while (t1!=NULL && t2!=NULL)
    {

        if (t1->Item < t2->Item)
        {
            obj.Insert_End(t1->Item) ;
            a.del_1st_node() ;
            t1 = a.get_1s_node() ;
        }
        else
        {
            obj.Insert_End(t2->Item) ;
            b.del_1st_node() ;
            t2 = b.get_1s_node() ;
        }
    }
    while (t1!=NULL)
    {
        t1 = a.get_1s_node() ;
        obj.Insert_End(t1->Item) ;
        a.del_1st_node() ;
    }
    while (t2!=NULL)
    {
        t2 = b.get_1s_node() ;
        obj.Insert_End(t2->Item) ;
        b.del_1st_node() ;
    }
    return obj ;
}

