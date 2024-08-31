
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
