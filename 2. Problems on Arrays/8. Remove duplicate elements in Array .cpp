/*8.Define a function to remove duplicate elements in the array.*/

#include<iostream>
using namespace std ;

void Duplicates (int a[] , int size )
{
    int p[20] = {0} ;

    int i ,j ;

    for (i=0 ; i<20 ; i++)
    {
        for (j=0 ; j<size ; j++)
        {
            if(i == a[j])
                p[a[j]]++ ;
        }
    }

    cout<<"\n\n*************************\n" ;
    for (i=0 ; i<20 ; i++)
        cout<<p[i]<<" " ;

    cout<<"\n\nAfter Remove Duplicates Values , Array values are : \n" ;
    for (i=0 ; i<20 ; i++)  
        if (p[i]==1)
            cout<<i<<"  " ;

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

    Duplicates(ptr,size) ;

    delete []ptr ;
    return 0 ;
}
