#include<iostream>
#include<cstring>
#include<cctype>
using namespace std ;

class node 
{
    public :
    char item ;
    node *next ;
} ;
class stack 
{
    private :
        node *top ;
    public :
        void ShowNode ()
        {
            if (top)
            {
                node *t = top ; 
                while (t)
                {
                    cout<<t->item ;
                    if (t->next != NULL)
                        cout<<"->" ;
                    t = t->next ;
                }
                cout<<endl ;
            }
        }

        stack& operator= (stack &obj)
        {
            top = NULL ;
            
            node *t = obj.top ;
            node *p = NULL ;

            while (t)
            {
                node *n = new node ;
                n->item = t->item ;
                if (this->top == NULL)
                    top = n ;
                else 
                    p->next = n ;
                p = n ; 

                t = t->next ;
            }
            if (p)
                p->next = NULL ;
            return *this ;
        }

        /*stack (stack &A)
        {
            top = NULL ;
            node *t = A.top ;

            stack temp ;

            while (t != NULL)
            {
                temp.push (t->item) ;
                t = t->next ;
            }
            while (temp.top != NULL)
            {
                push (temp.peek()) ;
                temp.pop() ;
            }
        }*/

        stack (stack &obj)
        {
            top = NULL ;
            
            node *t = obj.top ;
            node *p = NULL ;

            while (t)
            {
                node *n = new node ;
                n->item = t->item ;
                if (this->top == NULL)
                    top = n ;
                else 
                    p->next = n ;
                p = n ; 

                t = t->next ;
            }
            if (p)
                p->next = NULL ;

        }

        ~stack ()
        {
            while (top)
                pop() ;
        }
        
        void pop ()
        {
            if (top == NULL)
                return ;
            
            node *t = top ;
            top = t->next ;
            delete t ;
        }
        
        bool isStackEmpty ()
        {
            return top == NULL ;
        }
        
        int peek ()
        {
            if (top == NULL)
                return 0  ;
            return top->item ;
        }      
        
        void push (char data)
        {
            node *n = new node ;
            n->item = data ;
            n->next = top ;
            top = n ;
        }       
        stack ()
        {
            top = nullptr ;
        }
} ;

int operator_perform (char x , int a , int b)
{
    switch(x)
    {
        case '+' : return a+b ;
        case '-' : return a-b ;
        case '*' : return a*b ;
        case '/' : 
                    if (b!=0)
                        return a/b ;
                    throw -1 ;
        case '%' : return a%b ;
        default : return 0 ;

    }
}
bool is_Operand (char op)
{
    return isalnum(op) ;
}
bool is_oprator (char x)
{
    return x=='+'||x=='-'||x=='*'||x=='/'||x=='%' ;
}


void evaluate_postfix (const char Q[] , int &value)
{
    int len = strlen (Q) ;
    char p[len] ;
    strcpy(p , Q) ;
    int i ;
    stack obj ;

    int a , b , result ;


    p[len] = ')' ;
    p[len+1] = '\0' ;
    len++ ;

    for (i=0 ; p[i] !=')' ; i++)
    {
        if (is_Operand(p[i]) )
            obj.push(p[i] - '0') ;

        else  if (is_oprator(p[i]))
        {
            b = obj.peek() ;
            obj.pop() ;
            a = obj.peek() ;
            obj.pop () ;

            result = operator_perform(p[i] , a , b ) ;
            obj.push(result) ;
        }
    }
    value = obj.peek() ;
}

int main ()
{
    char p[] = "7 8 + 3 2 + /" ;
    int value ;
    evaluate_postfix (p , value) ;
    cout<<endl<<value ;
    return 0 ;
}
