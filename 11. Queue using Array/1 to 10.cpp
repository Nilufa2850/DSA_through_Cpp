/*                      Assignment-11: Queue using arrays
1. Define a class Queue with capacity, front, rear and ptr pointer as member variables.
Implement queue using array.
2. In question 1, define a parameterzied constructor to initialise member variables.
3. In question 1, define a method to insert a new element at the rear in the queue.
4. In question 1, define a method to view rear element of the queue.
5. In question 1, define a method to view front element of the queue.
6. In question 1, define a method to delete the front element of the queue.
7. In question 1, define a destructor to deallocates the memory.
8. In question 1, define a method to check queue overflow
9. In question 1, define a method to check queue underflow.
10. In question 1, Define a method to count number of elements present in the queue*/
#include<iostream>
using namespace std ;
class Queue
{
    private :
        int capacity ;
        int front ;
        int rear ;
        int *ptr ;
    public :

        Queue& operator= (Queue &Q)
        {
            if (ptr!=NULL)
                delete [] ptr ;
            
            //initialize member variable
            capacity = obj.capacity ;
            front = obj.front ;
            rear = obj.rear ;
            ptr = new int [capacity] ;

            //Copy code (Sir approch)
            int n = obj.count_element() ;
            int i = obj.front ;
            while (n)
            {
                ptr[i] = obj.ptr[i] ;
                if (i==capacity-1)
                    i=0 ;
                else
                    i++ ;
                n-- ;
            }
            return *this ;
        }

        int count_element ()
        {
        // Array is empty
            if (queue_underflow())  
                return 0 ;
        // Array has (one element) or (more than one element) or  ( full )
            if (rear >= front)
                return (rear-front)+1 ;
        //Array has element but its more round insertion and deletion
            //if (rear < front)  #no requir more checking
            return ((capacity-front) + (rear+1)) ;


/*            
            //if using loop , Sir's idea

                // Array is empty
                if (queue_underflow())  
                    return 0 ;

                int i, count=0 ;
                i = front ;
                while (i != rear)
                {
                    if (i == capacity-1)
                        i = 0 ;
                    else 
                        i++ ;
                    count ++ ;
                }
                return count+1 ;

*/           
        }

        bool queue_underflow ()
        {
            return (front == rear && front == -1 ) ;
        }

        bool queue_overflow ()
        {
            return ((rear+1 == front) || (rear == capacity-1 && front==0)) ;
        }

        ~Queue ()
        {
            delete [] ptr ;
        }

        int getFront ()
        {
            if (queue_underflow())
            {
                cout<<"\nArray is empty" ;
                return -1 ;
            }
            return ptr[front] ;
        }

        int getRear ()
        {
            if (queue_underflow())
            {
                cout<<"\nArray is empty" ;
                return -1 ;
            }
                
            return ptr[rear] ;
        }

        void deletion ()
        {
            if ((front == rear) && front == -1) //or rear == -1
            {
                //when rear==front==-1 , means array is empty
                cout<<"\nDeletion not possible , array is empty" ;
            }
            else if (front == rear && front != -1) //sir , only check front == rear , becoz if front==rear==-1 then 1st ( code) running
            {
                //when one element present
                front = -1 ;
                rear = -1 ;
            }
            else if (front == capacity-1)
            {
                //when front value is possible last index
                front = 0 ;
            }
            else
            {
                front++ ;
            }
        }

        void insert (int data)
        {
            if( (rear==capacity-1 && front==0) || (rear+1 == front) )
            {
                //Array is full , insertion not possible
                cout<<"\nArray is full , can't insert" ;
            }
            else if (front == -1 && rear == -1) //sir , only check rear==-1 , becoz if rear==-1 , then ovbiously front ==-1
            {
                //Array is empty
                rear++ ;
                ptr[rear] = data ;
                front = 0 ;
            }
            else if (rear == capacity-1 && front>0 ) //sir , check only rear == capacity-1 , becoz if fullArray already coded
            {
                //when rear is last possible index , but front not 0 , then insertion possible
                rear = 0 ;
                ptr[rear] = data ;
            }
            else
            {
                //Normal case
                rear++ ;
                ptr[rear] = data ;
            }
        }

        //copy constructor
        Queue (Queue &obj)
        {
            //initialize member variable
            capacity = obj.capacity ;
            front = obj.front ;
            rear = obj.rear ;
            ptr = new int [capacity] ;

            //Copy code (Sir approch)
            int n = obj.count_element() ;
            int i = obj.front ;
            while (n)
            {
                ptr[i] = obj.ptr[i] ;
                if (i==capacity-1)
                    i=0 ;
                else
                    i++ ;
                n-- ;
            }

/*  -----------------------------------My approch ----------------------------------------------------
            //copy array
            int i ;
            //Case 1: Single element
            if (front == rear )
                ptr[rear] = obj.ptr[rear] ;
            //case 2 : normal condition
            else if (front < rear)
                for (i=front ; i<=rear ; i++)
                    ptr[i] = obj.ptr[i] ;
            //case 3 : when array has circular || gap || full by circular 
            else if (front > rear)
            {
                for (i=0 ; i<=rear ; i++)
                    ptr[i] = obj.ptr[i] ;
                for (i=front ; i<capacity ; i++)
                    ptr[i] = obj.ptr[i] ;
            }
*/
        }

        //parameterized constructor
        Queue (int size)
        {
            capacity = size ;
            front = -1 ;
            rear = -1 ;
            ptr = new int [size] ;
        }
} ;
