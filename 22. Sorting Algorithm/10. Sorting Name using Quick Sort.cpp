#include<iostream>
#include<string.h>
#include <iomanip>
using namespace std ;

class Employee
{
    private :
        int emp_id ;
        char name[30] ;
        double salary ;
    public :

        //setter
        void setId (int id)
        {
            emp_id = id ;
        }
        void setName (char *name)
        {
            strcpy(this->name , name) ;
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
        char* getName ()
        {
            return name ;
        }
        double getSalary ()
        {
            return salary ;
        }
} ;

void setEmployee (Employee &e , int id , char* name , double salary)
{
    e.setId(id) ;
    e.setName(name) ;
    e.setSalary(salary) ;
}
void showEmployee(Employee e)
{
    cout<<e.getID()<<" "<<e.getName()<<" "<< fixed << setprecision(2)<<e.getSalary()<<endl ;
}




int quickProcedure (Employee a[] , int left , int right )
{
    int loc= left ;
    Employee temp ;
    
    while (left < right)
    {
        while (left < right && strcmp(a[right].getName(), a[loc].getName()) >= 0)
            right-- ;
        if (left<right)
        {
            temp = a[loc];
            a[loc] = a[right] ;
            a[right] = temp ;

            loc = right ;
        }
        while (left<right && strcmp(a[left].getName(), a[loc].getName()) <= 0)
            left++ ;
        if (left < right)
        {
            temp = a[loc];
            a[loc] = a[left] ;
            a[left] = temp ;

            loc = left ;
        }
    }
    return left ;
}

void QuickSortRec (Employee a[] , int left , int right)
{
    int loc = quickProcedure(a,left,right) ;

    if (loc>left+1)
        QuickSortRec(a,left,loc-1) ;
    if (loc <right-1)
        QuickSortRec(a,loc+1,right) ;
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

    QuickSortRec(e,0,4) ;

    cout<<endl<<"After Sorting"<<endl ;
    for(int i=0 ; i<5 ; i++)
        showEmployee(e[i]) ;
  
}








