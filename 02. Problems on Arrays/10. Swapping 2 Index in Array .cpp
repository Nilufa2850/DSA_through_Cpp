/*10.Define a function to swap elements with specified indices in the array.*/

#include<iostream>
using namespace std ;

void Swaps (int a[] , int size , int index1 , int index2)
{
    int temp ;

    temp = a[index1] ;
    a[index1] = a[index2] ;
    a[index2] = temp ;

    cout<<"\n\nAfter Swaping Array is : "<<endl ;
    for (int i=0 ; i<size ; i++)
        cout<<a[i]<<"  " ;

    cout<<endl ;
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

    Swaps(ptr,size,1,3) ;
    delete []ptr ;
    return 0 ;
}
