/*                              Assignment-9: Stack using arrays
1. Define a class Stack with capacity, top and ptr pointer as member variables. Implement stack using array.
2. In question 1, define a parameterzied constructor to initialise member variables.
3. In question 1, define a method to push a new element on to the Stack.
4. In question 1, define a method to peek top element of the stack.
5. In question 1, define a method to pop the top element of the stack.
6. In question 1, define a destructor to deallocates the memory.
7. In question 1, define a method to check stack overflow
8. In question 1, define a method to check stack underflow.
9. Define a method to reverse a stack.
10. Define a solution to keep track of minimum value element in the stack.*/

#include "Array_Stack.cpp"

class Stack : private Array 
{
    public :
        void operator= (Stack &s)
        {
            Array :: operator=() ;
        }
        //9
        void reverse ()
        {
            if (!is_array_empty())
            {
                int i , j ;
                int temp ;
                int indexlast = count_element()-1 ;

                for (i=0 , j=indexlast ; i<=j ; i++,j-- )
                {
                    temp = get_element(i) ;
                    edit (get_element(j) , i) ;
                    edit (temp , j) ;
                }
                show_Array() ;
            }
        }
        //8
        bool stack_underflow ()
        {
            return is_array_empty() ;
        
        }
        //7
        bool stack_overflow ()
        {
            return is_array_full() ;
        }
        //6
        ~Stack ()
        {
            
        }
        //5
        void pop ()
        {
            if (is_array_empty())
                cout<<"\nStack underflow" ;
            else
            {
                delete_specified(count_element()-1) ;
                show_Array() ;
            }
        }
        //4
        int peek ()
        {
            if(!is_array_empty())
                return get_element(count_element()-1) ;
        }
        //3
        void push (int data)
        {
            if (is_array_full())
                cout<<"\nStack is overflow" ;
            else
            {
                append(data) ;
                show_Array() ;
            }

        }
        //2
        Stack (int size) : Array (size) 
        { 
            
        }
} ;

//non member qn 9
void reverse (Stack &a)
{
    Stack b(10) ;
    while (!a.stack_underflow())
    {
        b.push(a.peek()) ;
        a.pop() ;
    }
    a = b ;
}
// non member 10 
void pushInStack (Stack &s , Stack &minStack , int data)
{
    s.push(data) ;
    
    if (minStack.stack_underflow())
        minStack.push (data) ;
    else
    {
        if (data > minStack.peek())
            minStack.push(minStack.peek()) ;
        else
            minStack.push(data) ;
    }
}
void popFromStack (Stack &s , Stack &minStack )
{
    s.pop() ;
    minStack.pop() ;
}

int main ()
{
    Stack S(5) ;
    Stack minStack (5) ;

    pushInStack(S , minStack , 10) ;
}
