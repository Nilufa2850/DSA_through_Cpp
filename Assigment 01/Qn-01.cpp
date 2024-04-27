/* 1. Define a class Array to implement array data structure with member variables to
store capacity of array, last index of the last filled block of the array and a 
pointer to hold the address of the first block of the dynamically created array.

2. In qn 1, define a parameterised constructor to create an array of specified size.
3. In qn 1, add a method to check whether an array is empty or not by
    returning True or False.
4.  In question 1, define a method to append a new element in the array
5.  In question 1, define a method to insert a new element at specified index
6.  In question 1, define a method to edit an element at specified index.
7.  In question 1, define a method to delete an element at specified index.
8.  In question 1, define a method to check if the array is full by returning true or false.
9.  In question 1, define a method to get element at specified index.
10. In question 1, define a method to count number of elements present in the array.
11. In question 1, define a destructor to deallocate the memory of array.
12. In question 1, define a method to find an element in the array. Return index if the
    element found, otherwise return -1.*/

#include<iostream>
#include<stdlib.h>
using namespace std ;

class Array
{
    private : 
        int size,capacity,last_index ;  //Qn-1
        int *p ;
    public :
        Array (int size)             //Qn-2
        {
            this->size = size ;
            last_index = -1 ;

            if (p != NULL)
                delete []p ;

            p = new int [size] ;
        }
        ~Array ()       //Qn-12
        {
            delete [] p ;
            cout<<"\n\nThank You\n" ;
        }
        void initialize_Array()
        {
            cout<<"Enter "<<size <<" Array Values : "<<endl ;
            int i ;
            for (i=0 ; i<size ; i++)
            {
                cin>>p[i] ;
                last_index ++ ;
            }
        }
        void show_Array()
        {
            cout<<"\n********ARRAY VALUES*********\n" ;
            int i ;
            for (i=0 ; i<size ; i++)
                cout<<p[i]<<"  " ;
            cout<<endl ;
            cout<<"\nLast Index = "<<last_index<<endl ;
            cout<<"*******************************\n" ;
        }
        bool check_Array ()          //Qn-3
        {
            if (last_index == -1)
                return true ;
            else
                return false ;
        }
        void append (int data)         //Qn-4
        {
            if (last_index == size-1)
                cout<<"\nCan't Append , Indexs are full"<<endl ;
            else {
                p [last_index + 1] = data ;
                last_index ++ ; 
            }
        }
        void insert (int data , int index_no)       //Qn-5
        {
            if (last_index == size-1)
                cout<<"\nCan't Insert , Indexs are full"<<endl ;
            
            int i ;
            i = last_index ;
            for (i = last_index ; i>=index_no ; i--)
            {
                p [i+1] = p[i] ; 
            }
            p[index_no] = data ;
            last_index++ ;

            if (index_no<0 || index_no>last_index+1)
                cout<<"\nInvalid Index" ;
        }
        void edit (int index_no , int data)         //Qn-6
        {
            if (index_no>=0 && index_no<=last_index )
                p[index_no] = data ;
            
            else
            {
                p[index_no] = data ;
                last_index ++ ;
            }
        }
        void shifting (int start , int end)    //Right to left
        {
            int i ;
            for (i=start ; i<=end-1 ; i++ )
                p[i] = p[i+1] ;
        }

        void del(int index_no)          //Qn-7
        {
            if (index_no<0 || index_no>last_index)
                cout<<"\nInvalid Index" ;

            shifting(index_no , last_index) ;
            last_index -- ;
        }
        bool full_array()               //Qn-8
        {
            if (last_index == size-1 )
                return true ;
            else
                return false ;
        }
        int get_Element(int index_no)       //Qn-9
        {
            if (index_no >= 0 && index_no <= last_index)
                return p[index_no] ;
            cout<<"\nEmpty Array or Invalid Index" ;
            return -1 ;

        }
        int count_Element ()        //Qn-10
        {
            return last_index + 1 ;
        }
        int found_element (int element)     //Qn-12
        {
            int i ;
            for (i=0 ; i<=last_index ; i++)
            {
                if (p[i] == element)
                    return i ;
            }
            return -1 ;
        }

} ;
int main ()
{
    cout<<"****************************************************\n" ;
    cout<<"1. Check Array for empty or not\n" ;
    cout<<"2. Append a new Element\n" ;
    cout<<"3. Insert a new Element\n" ;
    cout<<"4. Edit an Element\n" ;
    cout<<"5. Delete an Element\n" ;
    cout<<"6. Check array is full or not\n" ;
    cout<<"7. Get Element at specified index\n" ;
    cout<<"8. Count number of elements present in the array\n" ;
    cout<<"9. Find an element in the array\n" ;
    cout<<"10. Exit"<<endl ;
    cout<<"****************************************************\n\n" ;

    Array a1(10) ;
    a1.initialize_Array() ;
    a1.show_Array() ;


    while(1)
    {  
        cout<<"\nEnter your choice : ";
        int A ;
        cin>>A ;
        cout<<endl ;
 
        switch (A)
        {
            case 1 :
                if (a1.check_Array())
                    cout<<"Array is empty"<<endl ;
                else
                    cout<<"Array is non empty"<<endl ;
                break ;

            case 2 :
                int m ;
                cout<<"Enter your Data to append : " ;
                cin>>m ;

                a1.append(m) ; 
                a1.show_Array() ;
                break ;

            case 3 :

                int p , q ;
                cout<<"Enter your Data & Index No. to insert : " ;
                cin>>p>>q ;

                a1.insert(p,q) ;
                a1.show_Array() ;
                break ;

            case 4 :
                int e,f ;
                cout<<"Enter your Index No. & Data to Edit : " ;
                cin>>e>>f ;

                a1.edit(e,f) ;
                a1.show_Array() ;
                break ;

            case 5 :
                int b ;
                cout<<"Enter your Index no to delete : ";
                cin>>b ;

                a1.del(b) ;
                a1.show_Array() ;
                break ;

            case 6 :
                if (a1.full_array())
                    cout<<"Array is Total full"<<endl ;
                else
                    cout<<"Array is not full"<<endl ;
                break ;

            case 7 :
                int x ;
                cout <<"Enter a Index No. to get it's element : " ;
                cin>>x ;
                cout<<"Index = "<<x<<" Element = "<<a1.get_Element(x) ;
                break ;

            case 8 :
                cout<<"\nNo of elements are "<<a1.count_Element()<<endl ;
                break ;

                
            case 9 :
                int c ;
                cout<<"Enter a element to found : ";
                cin>>c ;

                if (a1.found_element(c) != -1)
                    cout<<"\nElement found" ;
                else
                    cout<<"\nElement not found" ;
                break ;

            case 10 :
                exit(0) ;
            
            default :
                cout<<"Invalid choice :(" ;
                
        }
        if (A==20)
            break ;
    }
    return 0 ;
}
