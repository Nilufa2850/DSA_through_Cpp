#include<iostream>
using namespace std ;

void merging (int a[], int l , int u ,int m)
{
    int n1 = (m-l)+1 ;
    int n2 = u-(m+1)+1 ;
    int x[n1] , y[n2] ;

    for (int i=0 ; i<n1 ; i++)
        x[i] = a[l+i] ;
    for (int i=0 ; i<n2 ; i++)
        y[i] = a[m+1+i] ;
    
    int i,j,k ;
    for (i=0,j=0,k=l ; i<n1 && j<n2 ; k++)
    {
        if (x[i]<=y[j])
        {
            a[k] = x[i] ;
            i++ ;
        }
        else 
        {
            a[k] = y[j] ;
            j++ ;
        }
    }
    while (i<n1)
    {
        a[k] = x[i] ;
        i++ ;
        k++ ;
    }
    while (j<n2)
    {
        a[k] = y[j] ;
        j++ ;
        k++ ;
    }
    
}

void mergeSort (int a[] , int l , int u)
{
    int m = (u+l)/2 ;
    if (l<u)
    {
        mergeSort(a,l,m) ;
        mergeSort(a,m+1,u) ;
        merging(a,l,u,m) ;
    }
    
}

int main ()
{
    int arr[] = {60,30,90,10,40,70,50,80,100,20} ;
    mergeSort(arr,0,9) ;
    for (int i=0 ; i<10 ; i++)
        cout<<arr[i]<<" " ;
}
