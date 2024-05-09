/*5.Define a function to calculate sum of all the elements of an array.*/

#include<iostream>
using namespace std ;

int sum (int a[] , int size)
{
    int i , sum=0 ;

    for (i=0 ; i<=size-1 ; i++)
        sum = sum+a[i] ;
    
    return sum ;
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

        
    cout<<"\nSum is "<<sum(ptr,size) <<endl ;
    delete []ptr ;
    return 0 ;
}
