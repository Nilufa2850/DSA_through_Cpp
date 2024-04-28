/*1. Define a class DynArray to implement dynamic array data structure with member
variables to store capacity of array, last index of the last filled block of the array and
a pointer to hold the address of the first block of the dynamically created array.
2. In question 1, define a parameterised constructor to create an array of specified size
3. In question 1, define a method doubleArray() to increase the size of the array by double of its size.
4. In question 1, define a method halfArray() to decrease the size of the array by half of its size.
5. In question 1, define a method which returns the current capacity of the array.
6. In question 1, add a method to check whether an array is empty or not by returning True or False.
7. In question 1, define a method to append a new element in the array
8. In question 1, define a method to insert a new element at specified index
9. In question 1, define a method to edit an element at specified index.
10. In question 1, define a method to delete an element at specified index.
11. In question 1, define a method to check if the array is full by returning true or false.
12. In question 1, define a method to get element at specified index.
13. In question 1, define a method to count number of elements present in the array.
14. In question 1, define a destructor to deallocate the memory of array.
15. In question 1, define a method to find an element in the array. Return index if the lement found, otherwise return -1.*/

#include<iostream>
#include<stdlib.h>
using namespace std ;

class DynArray
{
    private :
        int size ;
        int last_index ;
        int *ptr ;
    public :

        void showArray()
        {
            cout<<"\n**********ARRAY VALUES*********"<<endl ;
            int i ;
            for (i=0 ; i<=Current_capacity()-1 ; i++)
                cout<<ptr[i]<<" " ;
            cout<<endl ;
        }
        int find_element (int index)                //15
        {
            if (index >=0 && index <= last_index)
                return ptr[index] ;
            else
                return -1 ;
        }
        ~DynArray()                                 //14
        {
            delete [] ptr ;
            cout<<"\nThank You" ;
        }
        int count_no_of_elements ()                 //13
        {
            return last_index+1 ;
        }

        int get_element (int index )                //12
        {
            if (index >=0 && index<=last_index)
                return ptr[index] ;
            return -1 ;
        }
        bool Array_is_full ()                   //11
        {
            if (last_index == size-1)
                return true ;
            else
                return false ;
        }

        void Delete (int index)                 //10
        {
            int i ;
             
            if (index>last_index || index<0 )
                cout<<"\nYou can't delete , invalid index" ;

            else if (is_empty())
                cout<<"\nCan't Delete , Arrai is empty" ;

            else
            {
                for (i=index ; i<=last_index ; i++)
                {
                    ptr[i] = ptr[i+1] ;
                }
                last_index -- ;

                if (last_index >= (size-1)/2  && size >1 )
                    halfArray() ;
            }
        }

        void edit (int index , int data)                //9
        {
            if (index >=0 && index <= last_index)
                ptr[index] = data ;
            
            else if (index > last_index)
                cout<<"\nYou can't do Edit" ;
        }

        void insert (int index , int data)              //8
        {
            int i ;

            if (index >= 0 && index<= last_index)
            {
                if (last_index == size-1)   
                    doubleArray() ;

                for (i=last_index ; i>=index ; i-- )
                    ptr[i+1] = ptr[i] ;

                ptr[index] = data ;
                last_index ++ ;
            }
            else if (index<0 || index > last_index+1)
                cout<<"\nYou can't Insert , Invalid Index" ;
            
        }

        void append (int data)                  //7
        {
            if (last_index == size-1)   
                doubleArray() ;
                
            last_index ++ ;
            ptr[last_index] = data ;
            
        }
        bool check_Array_empty()                //6
        {
            if (last_index==-1)
                return true ;
            else
                return false ;
        }
        int Current_capacity ()                 //5
        {
            return size ;
        }
        void halfArray ()                       //4
        {
            size = size / 2 ;

            int *temp = new int [size] ;

                int i ;
                for (i=0 ; i<=last_index ; i++)
                    temp[i] = ptr[i] ;

                delete [] ptr ;
                ptr = temp ;
        }
        void doubleArray ()                   //3
        {
            size = size+size ;

            int *temp = new int [size] ;

            int i ;
            for (i=0 ; i<=last_index ; i++)
                temp[i] = ptr[i] ;

            delete [] ptr ;
            ptr = temp ;
        }

        DynArray (int size)                  //2
        {
            this->size = size ;
            last_index = -1 ;

            ptr = new int [size] ;
        }
        
        
} ;

int main ()
{
    int size ;
    cout<<"\nEnter size of array : " ;
    cin>>size ;

    DynArray obj(size) ;
    int data , index ;

    cout<<"*********************************" ;
    cout<<"\n1. Append";
    cout<<"\n2. Insert" ;
    cout<<"\n3. Edit" ;
    cout<<"\n4. Delete" ;
    cout<<"\n5. Know Current Capacity" ;
    cout<<"\n6. Array is Empty or not" ;
    cout<<"\n7. Array is Full or not" ;
    cout<<"\n8. Get Element";
    cout<<"\n9. Know No. of Element Present";
    cout<<"\n10. Find Element" ;
    cout<<"\n11. Show Array" ;
    cout<<"\n0. Exit";
    cout<<"\n*********************************\n" ;

    while (1)
    {
        cout<<"\nEnter your choice : ";
        int x ; 
        cin>>x ;

        switch (x)
        {
            case 1: 
                cout<<"\nEnter Data to Append : " ;
                cin>>data ;
                obj.append(data) ;
                break ;
            case 2:
                cout<<"\nEnter Data & Index to Insert : " ;
                cin>>data ;
                cin>>index ;
                obj.insert(index , data) ;
                break ;
            case 3:
                cout<<"\nEnter Data & Index to Edit : " ;
                cin>>data ;
                cin>>index ;
                obj.edit(index , data) ;
                break ;
            case 4:
                cout<<"\nEnter Index to Delete : " ;
                cin>>index ;
                obj.Delete(index) ;
                break ;
            case 5:
                cout<<"\nCurrent Capacity is : "<<obj.Current_capacity() ;
                break ;
            case 6:
                if (obj.check_Array_empty())
                    cout<<"\nArray is Empty" ;
                else
                    cout<<"\n Array is NOT empty" ;
                break ;
            case 7:
                if (obj.Array_is_full())
                    cout<<"\nArray is Full" ;
                else
                    cout<<"\n Array is NOT Full" ;
                break ;
            case 8:
                cout<<"\nEnter Index to Get Element : " ;
                cin>>index ;
                cout<<"\nIndex="<<index<<" Element="<<obj.get_element(index) ;
                break ;
            case 9:
                cout<<"\nNo. of element present in the array : "<<obj.count_no_of_elements() ;
                break ;
            case 10:
                cout<<"\nEnter Index to Find Element : " ;
                cin>>index ;
                cout<<"\nIndex="<<index<<" Element="<<obj.find_element(index) ;
                break ;
            case 11 :
                /*int i ;
                for (i=0 ; i<=obj.Current_capacity() ; i++)
                    cout<<obj.get_element(i) <<" " ;*/
                obj.showArray() ;
                break ;
            case 0:
                exit(0) ;
            default:
                cout<<"\nInvalid choice" ;
        }
    }

}
