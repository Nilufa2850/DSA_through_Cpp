#include<iostream>
using namespace std ;
int quickProcedure (int a[] , int left , int right)
{
    int loc = left ;
    int temp ;

    while (left != right)
    {
        while (left < right && a[right]>=a[loc])
            right-- ;

        if (left == right)
            break ;

        temp = a[loc] ;
        a[loc] = a[right] ;
        a[right] = temp ;
        loc = right ;

        while (left<right && a[left]<=a[loc])
            left++ ;
        if (left == right)
            break ;
        temp = a[loc] ;
        a[loc] = a[left] ;
        a[left] = temp ;
        loc = left ;
        
    }
    return loc ;
}

void quickSortRec (int a[] , int l,int u) 
{
    int loc = quickProcedure(a,l,u) ;
    if (loc > l+1)
        quickSortRec(a,l,loc-1) ;
    if (loc < u-1)
        quickSortRec(a,loc+1 , u) ;
}


int main ()
{
    int arr[] = {50,90,30,60,10,40,20,80,100,70} ;

    quickSortRec (arr , 0 , 9) ;
    cout<<endl ;
    for (int i=0 ; i<10 ; i++)
        cout<<arr[i]<<" " ;

}
