/*7.Define a function to rotate an array towards right by one position*/

#include<iostream>
using namespace std ;

void Rotate (int a[] , int size , int times )
{
    int i , r , temp ;

    for (r=1 ; r<=times ; r++)
    {
        temp = a[0] ;
        for (i=0 ; i<=size-2 ; i++)
            a[i] = a[i+1] ;
        
        a[i] = temp; 
    }

    
}
int main ()
{
    int *ptr  ;
    
    int size , i , position ;

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

    cout<<"\nHow many position i wanna to rotate : "<<endl ;  
    cin>>position ;

    cout<<"\n\nAfter "<<position <<" Rotation"<<endl ;
    Rotate(ptr , size , position) ;

    for (i=0 ; i<size ; i++)
        cout<<ptr[i]<<"  ";

    
    delete []ptr ;
    return 0 ;
}
