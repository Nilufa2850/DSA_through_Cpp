//4
void selectionSort (int *a , int n)
{
    int i , j , temp , minIndex ;
    

    for (i=0 ; i<=n-2 ; i++)
    {
        minIndex = i ;
        for (j=i+1 ; j<=n-1 ; j++)
        {
            if (a[minIndex] > a[j])
            {
                minIndex = j ;
            }
        }
        temp = a[i] ;
        a[i] = a[minIndex] ;
        a[minIndex] = temp ;
    }
}
