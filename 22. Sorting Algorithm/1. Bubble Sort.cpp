
//process 1
void BubbleSort (int *a , int n) 
{
    int round , i , temp ;
    for (round=n-1 ; round>=1 ; round--)
    {
        for (i=0 ; i<round ; i++) 
        {
            if (a[i] > a[i+1])
            {
                temp = a[i] ;
                a[i] = a[i+1] ;
                a[i+1] = temp ;
  }}}}
//process 2
void BubbleSort (int a[], int n)
{
    int r , i, t ;
    for (r=1 ; r<=n-1 ; r++)
    {
        for (i=0 ; i<= n-r-1 ; i++)
        {
            if (a[i]>a[i+1])
            {
                t = a[i] ;
                a[i] = a[i+1] ;
                a[i+1] = t ;
            }
        }
    }
}
