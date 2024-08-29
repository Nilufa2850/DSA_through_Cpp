#include<iostream>
using namespace std ;

class node
{
    public :
        int vertex ;
        node *next ;
} ;
class Adjlist
{
    private :
        int vertex ;
        node *start ;
    public :
        ~Adjlist ()
        {
            while (start)
                del_1st() ;
        }
        void del_1st ()
        {
            node *t = start ;
            start = start->next ;
            delete t ;
        }
        void insert_last (int vno)
        {
            node *n = new node ;
            n->vertex = vno ;
            n->next = nullptr ;

            if (start == nullptr)
                start = n ;
            else 
            {
                node *t = start ;
                while (t->next)
                {
                    t = t->next ;
                }
                t->next = n ;
            }
        }
        Adjlist ()
        {
            start = nullptr ;
        }
        void showNode ()
        {
            cout<<"V"<<vertex<<" : " ;
            node *t = start ;
            while (t)
            {
                cout<<"v"<<t->vertex<<" " ;
                t = t->next ;
            }
            cout<<endl ;
        }
        void setVertex (int v)
        {
            vertex = v ;
        }
        
} ;

class Graph
{
    private :
        int v_count ;
        Adjlist *arr ;
    public :
        Graph ()
        {
            v_count = 0 ;
            arr = nullptr ;
        }
        void createGraph (int v)
        {
            v_count = v ;
            arr = new Adjlist[v] ;
            for (int i=0 ; i<v_count ; i++)
                arr[i].setVertex (i) ;
        }

        void addEdge (int vno , int u)
        {
            //vno = directory list no , u = adjacent / neighbors of v
            arr[vno].insert_last(u) ;
            arr[u].insert_last(vno) ;

        }

        ~Graph ()
        {
            delete []arr ;
        }

        void showList ()
        {
            int i ;
            for (i=0 ; i<v_count ; i++)
            {
                //cout<<endl<<"V"<<i<<" : " ;
                arr[i].showNode () ;
            }
            cout<<endl ;
        }

        void show_adjacentNode (int vno)
        {
            //cout<<"V"<<vno<<": " ;
            arr[vno].showNode() ;
        }
} ;

int main ()
{
    Graph obj ;
    obj.createGraph(6) ;

    obj.addEdge(0,1) ;
    obj.addEdge(0,2) ;
    obj.addEdge(1,2) ;
    obj.addEdge(1,3) ;
    obj.addEdge(2,3) ;
    obj.addEdge(2,4) ;
    obj.addEdge(3,4) ;
    obj.addEdge(3,5) ;
    obj.addEdge(4,5) ;
    obj.showList() ;

    //obj.show_adjacentNode(1) ;
}
