

void insertionSort (int *a , int n)
{
    int i , temp , j ;

    for (i=1 ; i<=n-1 ; i++)
    {
        temp = a[i] ;

        j=i-1 ;

        while (a[j] > temp  && j>=0 )
        {
            a[j+1] = a[j] ;
            j-- ;
        }
        a[j+1] = temp ;
    }
}
