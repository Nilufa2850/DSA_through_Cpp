/*3.Define a function to find the smallest element in the array*/

#include<iostream>
using namespace std ;

int smallest (int a[] , int size)
{
    int i , j , temp ;

    for (i=0 ; i<=size-2 ; i++)
        for (j=i+1 ; j<=size-1 ; j++)
            if (a[i] < a[j])
                temp = a[i] ;

    return temp ;
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

    for (i=0 ; i<size ; i++)
        cout<<ptr[i]<<"  ";

    cout<<"\n\nSmallest Element is "<<smallest(ptr,size) ;

    delete []ptr ;
    return 0 ;
}
