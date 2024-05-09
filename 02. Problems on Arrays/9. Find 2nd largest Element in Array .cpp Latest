/*9.Define a function to find the second largest element in the array.*/

#include<iostream>
using namespace std ;

int sort (int a[] , int size )
{
    
    int i, j , temp ;
    for (i=0 ; i<size-1 ; i++)
    {
        for (j=i+1 ; j<size ; j++)

            if (a[i] < a[j])
                {
                    temp = a[i] ;
                    a[i] = a[j] ;
                    a[j] = temp ;
                }
    }
    return a[1] ;
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

    cout<<"\n\nSecond Largest Value = "<<sort(ptr , size)<<endl ;
    
    delete []ptr ;
    return 0 ;
}
