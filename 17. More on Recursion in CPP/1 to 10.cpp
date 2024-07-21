/*                  Assignment-17: More on Recursion
1. Write a recursive function to calculate sum of first N natural numbers
2. Write a recursive function to calculate sum of first N odd natural numbers
3. Write a recursive function to calculate sum of first N even natural numbers
4. Write a recursive function to calculate sum of squares of first N natural numbers
5. Write a recursive function to calculate factorial of a number
6. Write a recursive function to calculate sum of the digits of a given number
7. Write a recursive function to print binary of a given decimal number
8. Write a recursive function to find nth term of the Fibonacci series
9. Write a recursive function to calculate HCF of two numbers
10. Write a recursive function to calculate x power y.*/

#include<iostream> 
using namespace std ;

//10
int power (int x , int y)
{
    if (y==0)  //y = power
        return 1 ;
    return x*power(x,y-1) ;
}
//9
int HCF (int x , int y)
{
    if (y  > 0 )
        return HCF(y , x%y) ;
    return x ;
    
/*    USING LOOP    
// 
RULES 1 

    int temp ;
    while (y > 0)
    {
        temp = y ;
        y = x%y ;
        x = temp ;

    }
    return x ;

RULES 2 

    int i ;
    int min = x<y?x:y ;
    for (i=min ; i>=1 ; i--)
    {
        if (x%i == 0 && y%i == 0)
            return i ;
    }
    return 0 ;*/
}
//8
int fibo (int n)
{
    if (n==1)
        return 0 ;
    if (n==2 || n==3)
        return 1 ;

    return fibo(n-2)+fibo(n-1) ;
}
//7
void DtoB (int n)
{
    if (n>0)
    {
        DtoB(n/2) ;
        if (n % 2 )
            cout<<"1" ;
        else
            cout<<"0" ;
        
    }
}
//6
int sum_digit (int n )
{
    if (n>0)
        return n%10 + sum_digit(n/10) ;
    return 0 ;
}
//5
int fact (int n)
{
    if (n==0 || n==1)
        return 1 ;
    if (n>1)
        return n*fact(n-1) ;
}
//4
int sum_sqr (int n)
{
    if (n>0)
        return n*n+sum_sqr(n-1) ;
    return 0 ;
}
//3
int sum_even (int n)
{
    if (n>0)
        return (2*n) + sum_even(n-1) ;
    return 0 ;
}
//2
int sum_odd (int n)
{
    if (n>0)
        return (2*n-1) + sum_odd(n-1) ;
    return 0 ;
}
//1
int sum (int n)
{
    if (n>0)
        return n+sum(n-1) ;
    return 0 ;
}

int main ()
{
    cout<<fibo(10) ;
    return 0 ;
}

