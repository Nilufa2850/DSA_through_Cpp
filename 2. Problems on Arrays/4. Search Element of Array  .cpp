/*4.Define a function to search an element in the array*/

#include<iostream>
using namespace std ;

void search (int a[] , int size , int element)
{
    int i ;

    for (i=0 ; i<=size-1 ; i++)
        if (a[i] == element)
        {
            cout<<"\nElement found"<<endl ;
            cout<<"Index="<<i<<"  Element="<<element<<endl ;
            break ;
        }
    if (i == size)
        cout<<"\nElements not found"<<endl ;
    
}
int main ()
{
    int *ptr  ;
    
    int size , i ;

    cout<<"Enter Array Sizes : " ;
    cin>>size ;

    if (ptr != NULL)
        delete []ptr ;
    ptr = new int [size] ;

    cout<<"Enter "<<size<<" Elements\n" ;
    for (i=0 ; i<size ; i++)
        cin>>ptr[i] ;

    cout<<"\n****ARRAY VALUES****\n" ;
    for (i=0 ; i<size ; i++)
        cout<<ptr[i]<<"  ";

        
    int data ;
    cout<<"\n\nEnter a data to search : " ;
    cin>>data ;
    search(ptr , size , data) ;

    delete []ptr ;
    return 0 ;
}
