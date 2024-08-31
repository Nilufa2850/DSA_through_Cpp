#include<iostream>
#include "9. Stack using Array.cpp"

using namespace std ;
int quickProcedure (int a[] , int left , int right)
{
    int loc = left ;
    int temp ;
    while (left < right)
    {
        while (left<right && a[right] >= a[loc])
            right-- ;
        if (left == right)
            break ;
        temp = a[loc] ;
        a[loc] = a[right] ;
        a[right] = temp ;
        loc = right ;

        while (left<right && a[left] <= a[loc])
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

void quickSortLoop (int a[] , int l,int u) 
{
    int loc , i , j ;
    Stack lower(u+1),upper(u+1) ;

    lower.push(l) ;
    upper.push(u) ;

    while (!lower.stack_underflow()) //check any one is not empty
    {
        i = lower.peek() ;
        j = upper.peek() ;
        loc = quickProcedure(a,i,j) ;
        lower.pop() ;
        upper.pop() ;

        if (loc >i+1)
        {
            lower.push(i) ;
            upper.push(loc-1) ;
        }
        if (loc < j-1)
        {
            lower.push(i=loc+1) ;
            upper.push(j) ;
        }
    } 
}


int main ()
{
    int arr[] = {50,90,30,60,10,40,20,80,100,70} ;

    quickSortLoop (arr , 0 , 9) ;
    cout<<endl ;
    for (int i=0 ; i<10 ; i++)
        cout<<arr[i]<<" " ;

}

