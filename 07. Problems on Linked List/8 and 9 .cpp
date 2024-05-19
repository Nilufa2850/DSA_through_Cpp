#include<iostream>
using namespace std ;
class node
{
    public :
    int coefficiant ;
    int power ;
    node *next ;
};
class Polynomial
{
    private : 
        node *start ;
    public :
        Polynomial() 
        {
            start = NULL ;
        }
        void insert (int coeff , int degree )
        {
            node *n = new node ;
            n->coefficiant = coeff ;
            n->power = degree ;
            

            if (start==NULL)
            {
                n->next = nullptr ;
                start = n ;
            }
            else
            {
                node *t = start ;
                node *p = NULL ;
                
                if (t->power < n->power)
                {
                    n->next = t ;
                    start = n ;
                }
                else
                {
                    p=t ;
                    t=t->next ;

                    while (t!=NULL)
                    {
                        if (n->power > t->power)
                        {
                            n->next = t ;
                            p->next = n ;
                            break ;
                        }
                        p=t ;
                        t=t->next ;
                    }
                    if (t==NULL)
                    {
                        n->next = NULL ;
                        p->next = n ;
                    }
                }
            }

        }
        void show()
        {
            if (start)
            {
                node *t=start ;

                while (t)
                {
                    if (t->power == 0)
                        cout<<t->coefficiant ;
                    else if (t->power > 1)
                        cout<<t->coefficiant<<"x^"<<t->power<<" " ;
                    else if (t->power == 1)
                        cout<<t->coefficiant<<"x"<<" " ;
                    
                    t=t->next ;
                }
                cout<<endl ;
            }
        }
        
        void add (Polynomial b)
        {
            Polynomial c ;

            node*t1,*t2 ;

            t1 = start ;    //collar object
            t2 = b.start ;

            while (t1 && t2)
            {
                if (t1->power == t2->power)
                {
                    c.insert(t1->coefficiant+t2->coefficiant , t1->power) ;

                }
                else
                {
                    c.insert(t1->coefficiant,t1->power) ;
                    c.insert(t2->coefficiant,t2->power) ;
                }
                t1 = t1->next ;
                t2 = t2->next ;
            }
            c.show() ;
        }
} ;
