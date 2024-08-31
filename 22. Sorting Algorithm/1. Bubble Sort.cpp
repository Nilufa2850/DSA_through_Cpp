
//1
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
