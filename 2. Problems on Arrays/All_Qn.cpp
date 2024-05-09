/*1. Define a function to sort elements of the array.
2. Define a function to find the greatest element in the array
3. Define a function to find the smallest element in the array
4. Define a function to search an element in the array
5. Define a function to calculate sum of all the elements of an array.
6. Define a function to calculate average of all the elements of an array.
7. Define a function to rotate an array towards right by one position
8. Define a function to remove duplicate elements in the array.
9. Define a function to find the second largest element in the array.
10. Define a function to swap elements with specified indices in the array.*/

#include"Assign1.cpp" 
class Modifi_Array : public Array
{
    public :
        Modifi_Array(int capacity) : Array(capacity)
        {   }
        void sorting () ;
        int greatest () ;
        int smallest () ;
        int search (int) ;
        int sum () ;
        float Average () ;
        void rotate (int) ;
        void Remove_Duplicate () ;
        int second_largest () ;
        void Swap_element(int , int) ;  
} ;

//10
void Modifi_Array :: Swap_element(int index1, int index2) 
{
    int temp = get_element(index1) ;
    edit (index1 , get_element(index2)) ;
    edit (index2 , temp) ;
}

//9
int Modifi_Array :: second_largest ()
{
    int i , j , temp;
    for (i=0 ; i<=1  ; i++)
        for (j=i+1 ; j<count_total_element() ; j++)
            if (get_element(i) < get_element(j))
            {
                temp = get_element(i) ;
                edit (i , get_element(j)) ;
                edit(j , temp) ;
            }
            return get_element(1) ;
    /*sorting () ;
    return get_element(count_total_element()-1) ;*/
}

//8
void Modifi_Array :: Remove_Duplicate ()
{
    /*int i , j ;
    for (i=0 ; i<= count_total_element()-2 ; i++)
    {
        for (j=i+1 ; j<= count_total_element()-1 ; j++)
        {
            if (get_element(i) == get_element(j))
            {
                Delete(j) ;
                j-- ;
            }
        }
    }*/
    sorting() ;
    for (int i=0 ; i<= count_total_element()-2 ; i++)
    {
        if (get_element(i) == get_element(i+1))
        {
            Delete(i) ;
            i-- ;
        }
    }

                
}

//7
void Modifi_Array :: rotate (int rotation )
{
    int r, i , temp , last_index ;

    last_index = count_total_element() - 1 ;

    for (r=1 ; r<=rotation ; r++)
    {
        temp = get_element(last_index) ;

        for (i=last_index ; i > 0 ; i--)
        {
            edit (i , get_element(i-1)) ;
        }
        edit(i , temp) ;
    }

}

//6
float Modifi_Array :: Average ()
{
    int i , sum=0 ;
    float avg ;

    for (i=0 ; i<count_total_element() ; i++)
        sum = sum + get_element(i) ;
    
    avg = (float)sum / ( count_total_element() ) ;

    return avg  ;     
    
}

//5
int Modifi_Array :: sum ()
{
    
        int i , sum=0 ;

        for (i=0 ; i<count_total_element() ; i++)
            sum = sum + get_element(i) ;

        return sum ;
    
}

//4
int Modifi_Array :: search (int data)
{
    if (is_empty_array())
    {
        cout<<"\nArray is empty" ;
        return -1 ;
    }
    else
    {
        int i ;
        for (i=0 ; i< count_total_element() ; i++)
            if (data == get_element(i))
                return find_element(data) ;

        return -1 ;
    }
}

//3
int Modifi_Array ::  smallest ()
{
    if (is_empty_array())
    {
        cout<<"\nArray is Empty" ;
        return -1 ;
    }
    else
    {
        int i ;
        int min = get_element(0) ;

        for (i = 1 ; i<count_total_element() ; i++)
            if (min > get_element(i))
                min = get_element(i) ;

        return min ;
    }
}

//2
int Modifi_Array :: greatest ()
{
    if (is_empty_array())
    {
        cout<<"\nArray is Empty" ;
        return -1 ;
    }
    else
    {
        int i ;
        int max = get_element(0) ;

        for (i = 1 ; i<count_total_element() ; i++)
            if (max < get_element(i))
                max = get_element(i) ;

        return max ;
    }
}

//1
void Modifi_Array :: sorting ()
{
    int i, j , temp ;
        
    for (i=0 ; i<= count_total_element()-2 ; i++)

        for (j = i+1 ; j<= count_total_element()-1 ; j++)

            if ( get_element(i) > get_element(j) )
            {
                temp = get_element(i) ;
                edit(i , get_element(j)) ;
                edit (j , temp) ;
                
            }
}
