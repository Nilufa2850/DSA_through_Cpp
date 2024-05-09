/*1.Define a function to sort elements of the array.*/

#include<iostream>
using namespace std ;

void sort (int a[] , int size)
{
    int i , j , temp ;

    for (i=0 ; i<=size-2 ; i++)
        for (j=i+1 ; j<=size-1 ; j++)
            if (a[i] > a[j])
            {
                temp = a[i] ;
                a[i] = a[j] ;
                a[j] = temp ;
            }
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

    sort(ptr , size) ;

    for (i=0 ; i<size ; i++)
        cout<<ptr[i]<<"  ";
    return 0 ;
}
