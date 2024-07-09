/*                    Assignment-13: Deque using Array
1. Define a class Deque with node type pointers front and rear as member variables.
   Implement queue using ARRAY.
2. In question 1, define a constructor to initialise member variables
3. In question 1, define a method to insert a new element at the front
4. In question 1, define a method to insert a new element at the rear.
5. In question 1, define a method to delete front element
6. In question 1, define a method to delete rear element
7. In question 1, define a method to get front element.
8. In question 1, define a method to get rear element
9. In question 1, define a destructor to deallocate the memory.
10. In question 1, define a method to check if deque is empty.*/  

#include<iostream>
using namespace std ;
class Deque 
{
    private :
        int capacity ;
        int front , rear ;
        int *ptr ;
    public : 


        //copy constructor with out count()
        Deque(const Deque &d) 
        {
            capacity = d.capacity;  
            front = d.front;        
            rear = d.rear;         
            
            ptr = new int[capacity];  

            int i = d.front;
            while (i != d.rear) 
            {
                ptr[i] = d.ptr[i];

                // Increment i in a circular manner
                if (i == d.capacity - 1)
                    i = 0;  // Wrap around to the beginning of the array
                else
                    i++;    // Move to the next index
            }
            
            // Copy the last element (rear)
            ptr[i] = d.ptr[i];
        }

        int count ()
        {
            if (rear == NULL)
                return 0 ;
            /*    
            else if (rear >= front)
            {
                return rear-front+1 ;
            }
            return capacity-front + rear +1 ;*/
            int c=0 ;
            int i ;
            while (i!=rear)
            {

                if (i == capacity-1)
                    i=0 ;
                else 
                    i++ ;

                c++ ;

            }
            return c+1 ;
            

                
        }

        Deque (Deque &d)
        {
            capacity = d.capacity ;
            front = d.front ;
            rear = d.rear ;

            ptr = new int [capacity] ;
            
            int i = front ;
            int n = d.count() ;

            while (n )
            {
                if (i==capacity-1)
                    i = 0 ;
                else 
                    i++ ;

                ptr[i] = d.ptr[i] ;

                n-- ;

            }
            

        }

        bool isEmpty ()
        {
            return front == -1 ;
        }

        ~Deque()
        {
            delete [] ptr ; 
        }

        int getRear ()
        {
            if (rear!=-1) 
                return ptr[rear] ;
            return -1 ;
        }

        int getFront ()
        {
            if (front!=-1) 
                return ptr[front] ;
            return -1 ;
        }

        void delRear ()
        {
            if (rear == -1)      //when array is empty
                cout<<"\nArray is empty, can't delete" ;

            else if (front == rear) // when single element present
            {
                front = rear = -1 ;
            }
            else if (rear == 0 )
            {
                rear = capacity-1 ; 
            }
            else 
            {
                rear -- ;
            }
        }

        void delFront ()
        {
            if (front == -1)      //when array is empty
                cout<<"\nArray is empty, can't delete" ;

            else if (front == rear) // when single element present
            {
                front = rear = -1 ;
            }
            
            else if (front == capacity-1)
                    front = 0 ;
            else
                front ++ ;
            
        }

        void insertRear (int data)
        {
            if (rear+1 == front || (rear==capacity-1 && front==0))
                cout<<"\nArray is full, can't insert" ;

            else if (rear == -1) // array is fully empty
            {
                rear++ ;
                ptr[rear] = data ;
                front = 0 ;
            }
            else if (rear == capacity-1)
            {
                rear = 0 ;
                ptr[rear] = data ;
            }
            else 
            {
                rear ++ ;
                ptr[rear] = data ;
            }
        }

        void insertFront (int data)
        {
            if (front == rear+1 || (front==0 && rear == capacity-1))
                cout<<"\nArray is full, can't insert" ;

            else if (front == -1)  // when list fully empty
            {
                front = 0 ;
                rear = 0  ;
                ptr [front] = data ;
            }
            
            else if (front == 0)   // when front 0 index , but we insert at front , then front should be = last index 
            {
                front = capacity-1 ;
                ptr[front] = data ;
            }
            else 
            {
                front-- ;
                ptr[front] = data ;
            }

        }
        Deque (int size)
        {
            capacity = size ;
            front = rear = -1 ;
            ptr = new int [size] ;
        }
} ;
