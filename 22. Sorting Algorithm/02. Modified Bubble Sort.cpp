
//2
void ModifyBubbleSort (int *a , int n)
{
    for (int r=n-1 ; r>=1 ; r--)
    {
        int c = 0 ;
        for (int i=0 ; i<r ; i++)
        {
            if (a[i] > a[i+1])
            {
                int temp = a[i] ;
                a[i] = a[i+1] ;
                a[i+1] = temp ;
                c=1 ;
            }
        }
        if (c == 0)
            break ;
    }
}

//or 
void ModifyBubbleSort (int a[], int n)
{
    int r , i, t ;
    bool swap ;
    for (r=1 ; r<=n-1 ; r++)
    {
        swap = false ;
        for (i=0 ; i<= n-r-1 ; i++)
        {
            if (a[i]>a[i+1])
            {
                t = a[i] ;
                a[i] = a[i+1] ;
                a[i+1] = t ;
                swap = true ;
            }
        }
        if (swap == false)
            break ;
    }
}
