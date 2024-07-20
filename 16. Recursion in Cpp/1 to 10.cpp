/*                  Assignment-16: Recursion
1. Write a recursive function to print first N natural numbers
2. Write a recursive function to print first N natural numbers in reverse order
3. Write a recursive function to print first N odd natural numbers
4. Write a recursive function to print first N odd natural numbers in reverse order
5. Write a recursive function to print first N even natural numbers
6. Write a recursive function to print first N even natural numbers in reverse order.
7. Write a recursive function to print squares of first N natural numbers
8. Write a recursive function to print squares of first N natural numbers in reverse order.
9. Write a recursive function to print cubes of first N natural numbers
10. Write a recursive function to print cubes of first N natural numbers in reverse order */
#include<iostream> 
using namespace std ;

void RevCube (int n )
{
    if (n>0)
    {
        cout<<n*n*n<<" " ;
        RevCube (n-1) ;
    }
}
void Cube (int n )
{
    if (n>0)
    {
        Cube (n-1) ;
        cout<<n*n*n<<" " ;
    }
}
void RevSqr (int n)
{
    if (n>0)
    {
        cout<<n*n<<" " ;
        RevSqr(n-1) ;
    }
}
void Sqr (int n)
{
    if (n>0)
    {
        Sqr(n-1) ;
        cout<<n*n<<" " ;
    }
}
void RevEven (int n)
{
    if (n>0)
    {
        cout<<2*n<<" " ;
        RevEven (n-1) ;
    }
}
void Even (int n)
{
    if (n>0)
    {
        Even (n-1) ;
        cout<<2*n<<" " ;
    }
}
void RevOdd (int n)
{
    if (n>0)
    {
        cout<<2*n-1<<" " ;
        RevOdd (n-1) ;
    }
}
void Odd (int n)
{
    if (n>0)
    {
        Odd (n-1) ;
        cout<<2*n-1<<" " ;
    }
}
void Rev_N (int n)
{
    if (n>0)
    {
        cout<<n<<" " ;
        Rev_N (n-1) ;
    }
}
void Firtst_N (int n)
{
    if (n>0)
    {
        Firtst_N (n-1) ;
        cout<<n<<" " ;
    }
}

int main ()
{
    RevCube (5) ;
    cout<<endl ;
    return 0 ;
}
