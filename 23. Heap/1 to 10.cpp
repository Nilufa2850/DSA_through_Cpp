#include<iostream>
using namespace std ;

class Heap
{
    private :
        int capacity ;
        int N ;
        int *ptr ;
    public :
        Heap () { }
        Heap (int size)
        {
            capacity = size ;
            N = 0 ;
            ptr = new int [size] ;
        }
        Heap (Heap &obj)
        {
            capacity = obj.capacity ;
            N = obj.N ;

            ptr = new int [capacity] ;
            for (int i=0 ; i<N ; i++)
                ptr[i] = obj.ptr[i] ;
        }
        ~Heap ()
        {
            delete []ptr ;
        }
        void doubleArray ()
        {
            capacity = capacity*2 ;
            int *temp = new int [capacity] ;
            for (int i=0 ; i<N ; i++)
                temp[i] = ptr[i] ;
            delete []ptr ;
            ptr = temp ;
        }
        void HalfArray ()
        {
            if (capacity > 1)
            {
                capacity = capacity/2 ;
                int *temp = new int [capacity] ;
                for (int i=0 ; i<N ; i++)
                    temp[i] = ptr[i] ;
                delete []ptr ;
                ptr = temp ;
            }
        }
        
        bool isEmpty ()
        {
            return N==0 ;
        }
        int max ()
        {
            if (N>0)
                return ptr[0] ;
            return -1 ;
        }
        Heap& operator= (Heap &obj)
        {
            capacity = obj.capacity ;
            N = obj.N ;

            if (ptr)
                delete []ptr ;

            ptr = new int [capacity] ;
            for (int i=0 ; i<N ; i++)
                ptr[i] = obj.ptr[i] ;
            return *this ;
        }

        void insertion1 (int data) //my code , short version
        {
            if (N>=capacity)
                doubleArray() ;

            int i = N ; 
            int parent_index = (i-1)/2 ;
            while (i!=0 && ptr[parent_index]<data)
            {
                ptr[i] = ptr[parent_index] ;
                i = parent_index ;
                parent_index = (i-1)/2 ;
            }
            ptr[i] = data ;
            N++ ;
        }
        void insertion (int data)
        {
            if (N>=capacity)
                doubleArray() ;

            if (N==0)
                ptr[N] = data ;
            else 
            {
                int i = N ; 
                int parent_index = (i-1)/2 ;

                //if (ptr[parent_index] >= data)
                    //ptr[i] = data ;
                //else
                while (i!=0 && ptr[parent_index]<data)
                {
                    ptr[i] = ptr[parent_index] ;
                    i = parent_index ;
                    //if (i>0)
                    parent_index = (i-1)/2 ;
                }
                ptr[i] = data ;
            }
            N++ ;
        }
        void showHeap ()
        {
            cout<<endl ;
            for (int i=0 ; i<N ; i++)
                cout<<ptr[i]<<" " ;
            cout<<endl ;
        }
        
        void deletion1 ()
        {
            if (N==0)
            {
                cout << "Heap is empty." << endl;
                return ;
            }
            if (N == capacity/2)
                HalfArray() ;
            //cout<<endl<<ptr[0] ;
            N-- ;
            if (N>0)
            {
                int i , temp , childIndex,leftChild_index,rightChild_index ;
                i=0 ;
                temp = ptr[N] ;

                if (N==1)
                    ptr[i] = temp ;
                else 
                {
                    if (N==2)
                        childIndex = 1 ;
                    else 
                    {
                        leftChild_index = (2*i)+1 ;
                        rightChild_index = (2*i)+2 ;
                        // It's return Index value
                        childIndex = (ptr[leftChild_index] >= ptr[rightChild_index])?leftChild_index:rightChild_index ;
                    }
                
                    while (ptr[childIndex] > temp)
                    {
                        ptr[i] = ptr[childIndex] ;
                        i = childIndex ;
                        if (i>=N-2)
                            break ;
                        leftChild_index = (2*i)+1 ;
                        rightChild_index = (2*i)+2 ;
                        childIndex = (ptr[leftChild_index]>=ptr[rightChild_index])?leftChild_index:rightChild_index ;
                    
                    }
                    ptr[i] = temp ;
                }
            }
            else 
                N = 0 ;
        }
        
        void deletion2 ()
        {
            if (N==0)
            {
                cout << "Heap is empty." << endl;
                return ;
            }
            //cout<<endl<<ptr[0] ;
            N-- ;
            int i=0 , temp=ptr[N] , childIndex ; ;
        
            while (true)
            {
                int leftChild_index = (2*i)+1 ;
                int rightChild_index = (2*i)+2 ;

                if (leftChild_index < N) 
                {
                    if (rightChild_index < N)
                        // Both children exist, choose the larger one (return index)
                        childIndex = (ptr[leftChild_index] >= ptr[rightChild_index])?leftChild_index:rightChild_index ;
                    else 
                        // Only left child exists
                        childIndex = leftChild_index ;


                    if (ptr[childIndex] > temp)
                    {
                        ptr[i] = ptr[childIndex] ;
                        i = childIndex ;
                    }
                    else
                        break ;
                }
                else
                    break ; //when no children exist , then stop
            }
            ptr[i] = temp ;
        }  
} ;

void HeapSort (int a[] , int n)
{
    Heap h(n) ;
    int i ;
    for (i=0 ; i<n ; i++)
        h.insertion(a[i]) ;
    
    for (i=n-1 ; i>=0 ; i--)
    {
        a[i] = h.max() ;
        h.deletion2() ;
    }
}
