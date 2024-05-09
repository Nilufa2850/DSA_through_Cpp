/*6.Define a function to calculate average of all the elements of an array.*/

#include<iostream>
using namespace std ;

float Average (int a[] , int size)
{
    int i , sum=0 ;
    float avg ;

    for (i=0 ; i<=size-1 ; i++)
        sum = sum+a[i] ;
    
    return avg = sum /(size*1.0) ;
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

        
    cout<<"\nAverage is "<<Average(ptr,size) <<endl ;
    delete []ptr ;
    return 0 ;
}
