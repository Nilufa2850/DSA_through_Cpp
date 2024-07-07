/*          Assignment-10: Stack using linked list
1. Define a class Stack with node type pointer top as member variable. Implement stack using linked list.
2. In question 1, define a constructor to initialise member variable.
3. In question 1, define a method to push a new element on to the Stack.
4. In question 1, define a method to peek top element of the stack.
5. In question 1, define a method to pop the top element of the stack.
6. In question 1, define a destructor to deallocates the memory.
7. Define a method to reverse a stack.
8. Define a method to check whether a given number is a palindrome or not using stack.
9. Define a method to convert infix to postfix expression.
10. Define a method to evaluate postfix expression.*/

#include<iostream>
using namespace std ;
class node 
{
    public :
        int item ;
        node* next ;
} ;
class Stack 
{
    private :
        node *top ;
    public :
    //operator= overloading
    Stack& operator= (Stack &S)
    {
        // if we are trying (obj = obj) in the code 
        if (this == &S) //this means adress of collar object , compare with adress of S
            return *this ;

        //if collar object contain node then delete all nodes
        if (top !=NULL)
        {
            while (top)
            {
                this->pop() ;
            }
        }
        //copy code
        node *t , *n , *p=NULL ;
        t = S.top ;
        while (t)
        {
            n = new node ;
            n->item = t->item ;
            if (top==NULL)
                top = n ;       //for 1st node
            else
                p->next = n ;   //remaining node
            
            p = n ;
            t=t->next ;
        }
        if (p!=NULL)
            p->next = NULL ;

        return *this ;
    }

    //copy constructor 
    Stack (Stack &obj)
    {
        node *t , *n , *p=NULL ;
        t = obj.top ;
        while (t)
        {
            n = new node ;
            n->item = t->item ;
            if (top==NULL)
                top = n ;       //for 1st node
            else
                p->next = n ;   //remaining node
            
            p = n ;
            t=t->next ;
        }
        if (p!=NULL)
            p->next = NULL ;
    }
    //7. Reverse a stack 
    void reverse () 
    {
        node *t1 , *t2 ;
        
        if (top && top->next)
        {
            t2 = NULL ;
            do
            {
                t1 = top ;
                top = top->next ;
                t1->next = t2 ;      //reversing
                t2 = t1 ;
            }
            while (top->next!=NULL) ;
            top->next = t1 ;
        }
    }

    bool isEmpty ()
    {
        return top==NULL ;
    }

    node* middle_node ()        //for palindrome
    {
        if (top == NULL || top->next == NULL  || top->next->next == NULL)
            return top ;
        else
        {
            node *t1 , *t2 ;
            t1 = t2 = top ;

            while (t2 !=NULL && t2->next!=NULL )
            {
                t1 = t1->next ;
                t2 = t2->next->next ;
            }
            return t1 ;
        }
    }

    node* getTop ()
    {
        return top ;
    }
    //operator= overloading
    void operator= (Stack &obj)
    {
        if (top != NULL)
        {
            delete top ;
            top = NULL ;
        }
        while (obj.top != NULL)
        {
            push(obj.peek()) ;
        }
    }
    //6
        ~Stack () 
        { 
            while (top)
                pop() ;
        }
    //5
        void pop ()
        {
            if (top == NULL)
                cout<<"\nStack is underflow" ;
            else
            {
                node *t = top ;
                top = t->next ;
                delete t ;
            }

        }
    //4
        int peek ()
        {
            if (top)
                return top->item ;
            return 0 ;
        } 
    //3 insert at start
        void push (int data)
        {
            node *n = new node ;
            n->item = data ;
            n->next = top ;
            top = n ;
        }
    //2
        Stack ()
        {
            top = nullptr ;
        }
} ;
//7 non member reversing 
void reverse (Stack &obj)
{
    Stack S ;
    while (! obj.isEmpty())
    {
        S.push(obj.peek()) ;
        obj.pop() ;
    }
    obj = S ;
}
//check length of a anumber 
int length (int x)
{
    int count=0 ;
    while (x)
    {
        x = x/10 ;
        count++ ;
    }
    return count ;
}
//8. palindrome 
bool isPalindrome (int x)
{
    int len = length(x) ;

    Stack obj ;

    for (int i=1 ; i<=len/2 ; i++)
    {
        obj.push(x%10) ;
        x = x/10 ;
    }
    if (len % 2 != 0) // for ODD
        x = x/10 ; //remove middle number 

    while (x!=0)
    {
        if (x%10 == obj.peek())
        {
            obj.pop() ;
            x=x/10 ;
        }
        else
            return false ;
    }
    return true ;

}
#include<stdio.h>
#include<math.h>
int main()
{
    int a=2 ;
    int mul = 1 ;
    for (i=0 ; i<10000 ; i++)
        mul = a*a ;
    printf ("%d" , mul) ;
    return 0 ;

}
