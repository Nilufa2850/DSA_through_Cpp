/*              Assignment-12: Queue using linked list
1. Define a class Queue with node type pointers front and rear as member variables.
Implement queue using Singly linked list.
2. In question 1, define a constructor to initialise member variable.
3. In question 1, define a method to insert a new element at the rear in the queue.
4. In question 1, define a method to view rear element in the queue.
5. In question 1, define a method to view front element in the queue.
6. In question 1, define a method to delete the front element of the queue.
7. In question 1, define a destructor to deallocates the memory.
8. In question 1, define a method to count number of elements present in the queue.
9. Write a program to sort a queue, using queue operations only.
10. Write a program to sort a queue in descending order, using queue operations only.*/

#include<iostream>
using namespace std ;
class node 
{
    public :
        int item ;
        node *next ;
} ;

class Queue 
{
    private :
        node *front ;
        node *rear ;
    public :

        int count ()
        {
            int c=0 ;
            if (front) //not empty situation
            {
                node *t = front ;
                while (t!=NULL)
                {
                    c++ ;
                    t=t->next ;
                }
                
            }
            return c ;

        }

        void Delete ()
        {
            if (front == NULL) 
                cout<<"\nEmpty queue , delete not possible" ;
            else if (front == rear) // is not empty situation (front == rear == nullptr) not , becoz its already check 
            {
                //it's a single node situation
                delete front ;
                front = nullptr ;
                rear = nullptr ;
            }
            else
            {
                //normal case
                node *t = front ;
                front = t->next ;
                delete t ;
            }
        }

        int get_front_element ()
        {
            if (front) //not empty situation
                return front->item ;
            return -1 ;
        }

        int get_rear_element ()
        {
            if (rear)   //not empty situation
                return rear->item ;
            return -1 ;
        }

        void insert (int item)
        {
            node* n = new node ;
            n->item = item ;
            n->next = nullptr ;

            if (front == NULL) // when empty node
                front = n ;
            else
                rear->next = n ; //when node is not empty
            rear = n ;
        }
        Queue ()
        {
            front = nullptr ;
            rear = nullptr ;
        }
        ~Queue()
        {
            while (front)
                Delete () ;
        }
        bool is_empty ()
        {
            return front==nullptr ;
        }
        node* get_front ()
        {
            return front ;
        }
        node* get_rear()
        {
            return rear ;
        }
} ;

//10 descending order sroting

void sorting_descending (Queue &q1)
{
    Queue q2 , q3 ;

    q2. insert (q1.get_front_element()) ;
    q1.Delete() ;

    while (q1.get_front()) //front not empty situation
    {

        if (q1.get_front_element() > q2.get_rear_element())
        {
            while (q1.get_front_element() < q2.get_front_element())
            {
                q3.insert (q2.get_front_element()) ;
                q2.Delete() ;
            }
            q3.insert(q1.get_front_element()) ;
            q1.Delete() ;

            while (q2.get_front())
            {
                q3.insert(q2.get_front_element()) ;
                q2.Delete() ;
            }

            //copy code , q2 = q3 
            while (q3.get_front())
            {
                q2.insert(q3.get_front_element()) ;
                q3.Delete() ;
            }
        }
        else
        {
            q2.insert(q1.get_front_element()) ;
            q1.Delete() ;

        }
    }

    while (q2.get_front())
    {
        q1.insert(q2.get_front_element()) ;
        q2.Delete() ;
    }
}


//9 Sorting with queue operation 
void sorting (Queue &q1)
{
    Queue q2 , q3 ;

    q2. insert (q1.get_front_element()) ;
    q1.Delete() ;

    while (q1.get_front()) //front not empty situation
    {

        if (q1.get_front_element() < q2.get_rear_element())
        {
            while (q1.get_front_element() > q2.get_front_element())
            {
                q3.insert (q2.get_front_element()) ;
                q2.Delete() ;
            }
            q3.insert(q1.get_front_element()) ;
            q1.Delete() ;

            while (q2.get_front())
            {
                q3.insert(q2.get_front_element()) ;
                q2.Delete() ;
            }

            //copy code , q2 = q3 
            while (q3.get_front())
            {
                q2.insert(q3.get_front_element()) ;
                q3.Delete() ;
            }
        }
        else
        {
            q2.insert(q1.get_front_element()) ;
            q1.Delete() ;

        }
    }

    while (q2.get_front())
    {
        q1.insert(q2.get_front_element()) ;
        q2.Delete() ;
    }
}

//9 Normal sorting 
void sort(Queue &q)
{
    node *t = q.get_front() ;
    node *p = nullptr ;
    int temp ;

    while (t!=nullptr)
    {
        p = t->next ;
        while (p!=NULL)
        {
            if (t->item > p->item)
            {
                //swapping
                temp = t->item ;
                t->item = p->item ;
                p->item = temp ;

            }
            p = p->next ;
        }
        t = t->next ;
    }
    
    
}
