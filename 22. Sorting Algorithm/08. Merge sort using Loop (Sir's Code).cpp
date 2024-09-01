void merge(int a[],int n1,int i1,int b[],int n2,int i2,int c[],int i3)
{
    int i,j,k;
    for(i=0,j=0,k=0;i<n1&&j<n2;k++)
    {
        if(a[i+i1]<b[j+i2])
        {
            c[k+i3]=a[i+i1];
            i++;
        }
        else
        {
            c[k+i3]=b[j+i2];
            j++;
        }
    }
    while(i<n1)
    {
        c[k+i3]=a[i+i1];
        i++;
        k++;
    }
    while(j<n2)
    {
        c[k+i3]=b[j+i2];
        j++;
        k++;
    }
}
void mergepass(int SRC[],int size,int L,int DEST[])
{
    int j,mergeCount,index,R,S;
    mergeCount=size/(2*L);
    S=mergeCount*2*L;
    R=size-S;
    
    for(j=0;j<mergeCount;j++)
    {
        index=j*2*L;
        merge(SRC,L,index,SRC,L,index+L,DEST,index);
    }
    if(R<=L)
    {
        for(int i=0;i<R;i++)
            DEST[S+i]=SRC[S+i];
    }
    else
        merge(SRC,L,S,SRC,R-L,S+L,DEST,S);

}
void mergeSortLoop(int A[], int size)
{
    int L=1,B[size];
    while(L<size)
    {
        mergepass(A,size,L,B);
        mergepass(B,size,2*L,A);
        L=L*4;
    }
}
