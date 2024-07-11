/*                      Assignment-14: Priority Queue using singly linked list

1. Define a class PriorityQueue with node type pointer start as member variable.
    Implement PriorityQueue using singly linked list.
2. In question 1, define a constructor to initialise member variable.
3. In question 1, define a method to insert new item in the Priority Queue according to the priority number.
4. In question 1, define a method to delete highest priority element
5. In question 1, define a method to get highest priority element
6. In question 1, define a method to get highest priority number.
7. In question 1, define a destructor to deallocate the memory.
8. In question 1, define a method to check if Priority Queue is empty
9. Define a logic to implement priority queue using 2 dimensional arrays
10. Define a logic to implement min priority queue and max priority queue in the same data structure.*/

#include<iostream>
using namespace std ;

//PQ implementation by singly linked list
class node 
{
    public :
        int prio ;
        int item ;
        node * next ;
} ;

class priorityQueue 
{
    private :
        node *start ;
    public :

        void shownode ()
        {
            if (start)
            {
                node *t = start ;
                cout<<"\nNode are : "<<endl ;
                while (t)
                {
                    cout<<"(I="<<t->item<<",p="<<t->prio<<")"<<"  " ;
                    t = t->next ;
                }
            }
        }
        bool isEmpty ()
        {
            return start == NULL ;
        }

        ~priorityQueue()
        {
            while (start)
                del() ;
        }

        int get_high_prio_number ()
        {
            if (start)
                return start->prio ;
            return -1 ;
        }

        int get_high_prio_element ()
        {
            if (start)
                return start->item ;
            return -1 ;
        }

        void del ()
        {
            if (start)
            {
                node *t = start ;
                start = start->next ;  
                delete t ;
            }
        }
        void insert (int p , int data)
        {
            node *n = new node ;
            n->prio = p ;
            n->item = data ;
            if (start == NULL)
            {
                //when list is empty
                n->next = NULL ;
                start = n ;
            }
            else 
            {
                // when list is non empty
                node *t = start ;
                node *temp = NULL ;

                while (t!=NULL)
                {
                    if ((t->prio) < (n->prio))
                        break ;
                    
                    temp = t ;
                    t = t->next ;
                }
                if (temp == NULL)
                {
                    //when new node priority is higher 
                    n->next = start ;
                    start = n ;
                }
                else 
                {
                    n->next = temp->next ;
                    temp->next = n ;
                }
            }
            
        }
        priorityQueue ()
        {
            start = NULL ;
        }
} ;

//PQ implementation by Array
class PQ 
{
    private :
        int priorityRange ;
        int capacity ;
        int *front , *rear ;
        int *ptr ;
    public :
    
    bool isEmpty ()
    {
        int i ;
        for (i=0 ; i<priorityRange ; i++)
        {
            if (front[i] != -1)
                return false ;
        }
        return true ;
    }

    //get highest priority number
    int get_HP_number ()
    {
        int i ;
        for (i=0 ; i<priorityRange ; i++)
        {
            if (front[i] != -1)
                return i+1 ; ;
        }
        return 0 ;
    }

    //get high priority element
    int get_HP_element ()
    {
        int i ;
        for (i=0 ; i<priorityRange ; i++)
        {
            if (front[i] != -1)
                ptr[i][front[i]] ;
        }
        return 0 ;
    }

    //destructor 
    ~PQ ()
    {
        delete [] front ;
        delete [] rear ;
        delete [] ptr ;
    }


    //Deletion 
    void del ()
    {
        int i ;
        for (i=0 ; i<priorityRange ; i++)
        {
            if (front[i] == -1 )
            {
                //when single array is empty
                continue;
            }
            else if (front[i] == rear [i])
            {
                // when single array has single element
                front [i] = -1 ;
                rear [i] = -1 ;
                break ;
            }
            else if (front[i] == capacity-1)
            {
                //when front is last possible index
                front[i] = 0 ;
                break ;
            }
            else 
            {
                front[i] ++ ;
                break ;
            }

        }
        if (i == priorityRange)
            cout<<"\nArray is empty , can not deletion possible" ;
        
    }

    //Insertion
    void insert (int p , int data)
    {
        if (p>priorityRange || p<1)
            cout<<"\nInvalid Priority Range" ;

        else if ((front[p-1] == 0 && rear[p-1]==capacity-1) || (front[p-1] == rear[p-1]+1) )
        {
            //when array is full
            cout<<"\nEvery Array is full , cant insert possible" ;
        }
        else if (front[p-1] == -1)
        { 
            //when array is empty

            front[p-1]++ ;   //front[p] = 0 ;
            rear [p-1] ++ ;   //rear[p] = 0 ;

            ptr[p-1][rear[p-1]] = data ;
        }
        else if (front[p-1] > 0 && rear[p-1] == capacity-1) 
        {
            //when rear is last possible index , but front is in middle index
            rear[p-1] = 0 ;
            ptr[p-1][rear[p-1]] = data ;

        }
        else 
        {
            rear[p-1]++ ;
            ptr[p-1][rear[p-1]] = data ;
        }
    }

    //Constructor 
    PQ (int p_Range , int size_Array)
        {
            priorityRange = p_Range ;
            capacity = size_Array ;
            
            front = new int [priorityRange] ;
            rear = new int [priorityRange] ;

            //assign - in front and rear array index
            int i ;
            for (i=0 ; i<priorityRange ; i++)
            {
                front[i] = -1 ;
                rear [i] = -1 ;
            }
            ptr = new int [priorityRange][capacity] ;
        }

} ;

//PQ implementation by Doubly linked list
class Node
{
    public :
        int p ;
        int item ;
        Node *prev ;
        Node *next ;
} ;

class PQ_DLL 
{
    private :
        Node *start , *last ;
    public :

        void shownode ()
        {
            if (start)
            {
                Node *t = start ;
                cout<<"\nNode are : "<<endl ;
                while (t)
                {
                    cout<<t->p<<"  " ;
                    t = t->next ;
                }
            }
        }

        void del_max_PQ ()
        {
            if (start)
            {
                Node *t = start ;
                if (start == last)
                {
                    //when single node present 
                    start = last = NULL ;
                }
                else 
                {
                    start->next->prev = NULL ;
                    start = start->next ;
                }
                delete t ;
            }
        }
        void del_min_PQ ()
        {
            if (last)
            {
                Node *t = last ;
                if (last == start)
                    start = last = NULL ;
                else 
                {
                    last->prev->next = NULL ;
                    last = last->prev ; 
                }
                delete t ;
            }
        }

        void insert_min_PQ (int pno , int data)
        {
            Node *n = new Node ;
            n->item = data ;
            n->p = pno ;

            if (last == NULL)
            {
                //when list is empty
                n->prev = NULL ;
                n->next = NULL ;
                last = n ;
                start = n ;

            }
            else if (last->p > n->p)
            {
                //when new p is lower from all node
                n->next = NULL ;
                n->prev = last ;
                last->next = n ;
                last = n ;

            }
            else 
            {
                Node *t = last ;
                while (t->prev != NULL)
                {
                    if (t->prev->p <= n->p)
                        t = t->prev ;
                    else 
                        break ;
                }
                n->next = t ;
                n->prev = t->prev ;
                if (t!= start)
                    t->prev->next = n ;
                else 
                    start = n ;
                t->prev = n ;
            }
        }

        void insert_max_PQ (int pno , int data)
        {
            Node *n = new Node ;
            n->item = data ;
            n->p = pno ;

            if (start == NULL)
            {
                //when list is empty
                n->prev = NULL ;
                n->next = NULL ;

                start = last = n ;
            }
            else if (start->p  <  n->p)
            {
                //when new p is higher from all node
                n->prev = NULL ;
                n->next = start ;
                start->prev = n ;
                start = n ;
            }
            else
            {
                Node *t = start ;
                while (t->next != NULL)
                {
                    if (t->next->p >= n->p)
                        t = t->next ;
                    else 
                        break ;
                }
                n->prev = t ;
                n->next = t->next ;

                if (last != t)
                    t->next->prev = n ;
                else 
                    last = n ;
                t->next = n ;

            }
        }
        
        PQ_DLL()
        {
            start = last = NULL ;
        }
} ;
