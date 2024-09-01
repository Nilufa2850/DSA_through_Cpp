#include<iostream>
#include<string>
#include <iomanip>
using namespace std ;

class Employee
{
    private :
        int emp_id ;
        string name ;
        double salary ;
    public :

        //setter
        void setId (int id)
        {
            emp_id = id ;
        }
        void setName (string name)
        {
            this->name = name ;
        }
        void setSalary (double s)
        {
            salary = s ;
        }
        //getter
        int getID ()
        {
            return emp_id ;
        }
        string getName ()
        {
            return name ;
        }
        double getSalary ()
        {
            return salary ;
        }
} ;

void setEmployee (Employee &e , int id , string name , double salary)
{
    e.setId(id) ;
    e.setName(name) ;
    e.setSalary(salary) ;
}
void showEmployee(Employee e)
{
    cout<<e.getID()<<" "<<e.getName()<<" "<< fixed << setprecision(2)<<e.getSalary()<<endl ;
}



void merging(Employee a[] , int l , int m , int u)
{
    int n1 , n2 ;
    n1 = (m-l)+1 ;
    n2 = u-m ;

    Employee left[n1] , right[n2] ;

    for (int i=0 ; i<n1 ; i++)
        left[i] = a[l+i] ;
    for (int i=0 ; i<n2 ; i++)
        right[i] = a[m+1+i] ;

    int i,j,k ;

    for (i=0,j=0,k=l ; i<n1 && j<n2 ; k++)
    {
        if (left[i].getSalary() <= right[j].getSalary())
        {
            a[k] = left[i] ;
            i++ ;
        }
        else 
        {
            a[k] = right[j] ;
            j++ ;
        }
    }

    while (i<n1)
    {
        a[k] = left[i] ;
        i++ ;
        k++ ;
    }
    while (j<n2)
    {
        a[k] = right[j] ;
        j++ ;
        k++ ;
    }
}

void mergeSortRec (Employee a[] , int l , int u)
{
    int m = (l+u)/2 ;
    if (l<u)
    {
        mergeSortRec(a,l,m) ;
        mergeSortRec(a,m+1,u) ;
        merging(a,l,m,u) ;
    }
}



int main ()
{
    Employee e[5] ;
    setEmployee(e[0],1,"Nilufa",15) ;
    setEmployee(e[1],2,"yasmin",19) ;
    setEmployee(e[2],3,"Asif",12) ;
    setEmployee(e[3],4,"Sahara",14) ;
    setEmployee(e[4],5,"Sahaji",9) ;

    for(int i=0 ; i<5 ; i++)
        showEmployee(e[i]) ;

    mergeSortRec(e,0,4) ;

    cout<<endl<<"After Sorting"<<endl ;
    for(int i=0 ; i<5 ; i++)
        showEmployee(e[i]) ;
  
}








