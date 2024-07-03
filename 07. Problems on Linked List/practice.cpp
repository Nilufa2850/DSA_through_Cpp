/*1. Define a method to count number of list items in the singly linked list.
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
void sort_LL (SLL &) ;

//10
void add_LL (SLL &a , SLL &b)
{
    Node *t , *p ;
    t = a.getStart() ;
    p = b.getStart() ;

    int sum=0 ;
    int carry=0 ;
    int input ;

    SLL obj ;

    while (t != NULL && p!=NULL)
    {
        sum = (t->Item) + (p->Item) + carry ;
        carry = sum/10 ;
        input = sum%10 ;

        obj.Insert_End(input) ;

        t=t->Next ;
        p=p->Next ;
    }
    while (t!=NULL)
    {
        sum = t->Item + carry ;
        carry = sum/10 ;
        input = sum%10 ;

        obj.Insert_End(input) ;
        t = t->Next ;
    }
    while (p!=NULL)
    {
        sum = p->Item + carry ;
        carry = sum/10 ;
        input = sum%10 ;

        obj.Insert_End(input) ;
        p = p->Next ;
    }
    if (carry != 0)
        obj.Insert_End(carry) ;

    cout<<"\nAfter add" <<endl ;
    obj.show_node() ;
}

void merge_2_LL (SLL &a , SLL &b)
{
    sort_LL(a) ;
    cout<<"\nAfter sorting of a = ";
    a.show_node() ;
    sort_LL(b) ;
    cout<<"\nAfter sorting of b = ";
    b.show_node() ;
    cout<<endl ;

    SLL obj ;

    Node *t , *p ;
    t = a.getStart() ;
    p = b.getStart() ;

    while (t!=NULL && p!=NULL)
    {
        if (t->Item < p->Item)
        {
            obj.Insert_End(t->Item) ;
            t = t->Next ;
        }
        else
        {
            obj.Insert_End(p->Item) ;
            p = p->Next ;
        }
    }
    while (t!=NULL)
    {
        obj.Insert_End(t->Item) ;
        t = t->Next ;
    }
    while (p!=NULL)
    {
        obj.Insert_End(p->Item) ;
        p = p->Next ;
    }

    cout<<"\n\nAfter two LL merge"<<endl ;

    obj.show_node() ;

}

void sort_LL (SLL &obj)
{
    Node *t = obj.getStart() ;
    Node *p ; 
    int temp ;

    while (t != NULL)
    {
        p = t->Next ;
        while (p != NULL)
        {
            if (t->Item > p->Item)
            {
                temp = t->Item ;
                t->Item = p->Item ;
                p->Item = temp ;
            }
            p = p->Next ;
        }
        t = t->Next ;
    }
}

int count_length_cycle (SLL & obj)
{
    int count = 0 ;
    Node *t1, *t2 ;
    t1 = t2 = obj.getStart() ;

    while (t2 != NULL && t2->Next != NULL)
    {
        t1 = t1->Next ;
        t2 = t2->Next->Next ;

        if (t1 == t2)
        {
            do
            {
                count ++ ;
                t2 = t2->Next ;

            }while (t1 != t2) ;
            return count ;
        }
            
    }
    return -1 ;
    
}

bool is_cycle (SLL &obj)
{
    Node *start = obj.getStart() ;
    Node *t1, *t2 ;
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

int mid_node (SLL &obj)
{
    Node *start = obj.getStart() ;
    if (start->Next == NULL  ||  start->Next->Next == NULL)
        return start->Item ;
    else 
    {
        Node *t = start ;
        Node *t1 = start ;

        while (t1->Next != NULL  &&  t1 != NULL )
        {
            t1 = t1->Next->Next ;
            t = t->Next ;
        }
        return t->Item ;
    }

}

void reverse_list(SLL &obj) {
    Node *current = obj.getStart();
    Node *prev = nullptr;
    Node *next = nullptr;

    while (current != nullptr) {
        next = current->Next;   // Store next node
        current->Next = prev;   // Reverse current node's pointer

        prev = current;         // Move pointers one position ahead
        current = next;
    }

    obj.setStart(prev);   // Update the start of the list to the new head
}



int count_list (SLL &obj)
{
    int count =0 ;

    Node *t = obj.getStart() ;
    while (t != NULL)
    {
        count++ ;
        t = t->Next ;
    }
    return count ;
}
