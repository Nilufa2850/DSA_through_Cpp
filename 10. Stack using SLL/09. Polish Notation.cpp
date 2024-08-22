#include<iostream>
#include<string.h>
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


//Polish Notation
int priority (char x)
{
    if (x == '*' || x=='/' || x=='%')
        return 2 ;
    if (x=='+' || x=='-')
        return 1 ;
    if (x=='(' || x==')')
        return 0 ;
    return -1 ;
    
}
bool check_operands (char x)
{
    if (x>='a' && x<='z'  || x>='A' && x<='Z' || x>='0'&& x<='9') 
        return true ;
    return false ;
}
bool check_operator (char x)
{
    if (x=='+' || x=='-' || x=='*' || x=='/' || x=='%')
        return true ;
    return false ;
}

void infix_to_postfix (char Q[])
{
    //ALL declaration statement 
    stack obj ; 
    int len = strlen(Q) ;
    int i,j ;
    char p[100] ;
    

    Q[len] = ')' ;    //step 1
    Q[len+1] = '\0' ;
    len = strlen(Q) ;  //updated length increse +1 ;

    obj.push('(') ;  //step 1
    
    for (i=0,j=0 ; i<len ; i++)
    {
        //step 3
        if (check_operands(Q[i])) // when encountered a operand like : A B C
        {
            p[j++] = Q[i] ;
            
            
        }
        else if (check_operator(Q[i])) // when encountered a operator like : + - * / 
        {
            //step 5
            while ( ! obj.isStackEmpty() && priority(Q[i]) <= priority(obj.peek()))
            {
                p[j++] = obj.peek() ;
                obj.pop() ;
            }
            obj.push(Q[i]) ; //step 5
        }
        else if (Q[i] == '(') //step 4 
            obj.push(Q[i])  ;

        else if (Q[i] == ')') //step 6
        {
            while (obj.peek () != '(')
            {
                p[j++] = obj.peek() ;
                obj.pop() ;
            }
            obj.pop() ;     //remove '(' in the stack 
        }

    }
    while (! obj.isStackEmpty())
    {
        p[j++] = obj.peek() ;
        obj.pop() ;
    }
    p[j] = '\0' ;
    
    cout<<endl<<p ;
}

int main ()
{
    char Q[] = "A+B*(C-D)+E" ;

    infix_to_postfix(Q) ;

    return 0 ;
}
