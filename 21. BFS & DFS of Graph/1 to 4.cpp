#include<iostream>
#include "9. Stack using Array.cpp"
#include "11QueueusingArray.cpp" 

using namespace std ;
/*
class GraphMatrix
{
    private :
        int v_count , e_count ;
        int **adj ;
    public :
        GraphMatrix()
        {
            v_count = e_count = 0 ;
            adj = nullptr ;
        }
        void createGraph (int v_count , int e_count) 
        {
            this->v_count = v_count ;
            this->e_count = e_count ;

            adj = new int* [v_count] ;
            for (int i=0 ; i<v_count ; i++)
                adj[i] = new int [v_count]() ;

            int u ,v ;
            for (int i=0 ; i<e_count ; i++)
            {
                cout<<"\nEnter connected edges btw u and v : " ;
                cin>>u>>v ;

                adj[u][v] = 1 ;
                adj[v][u] = 1 ;
            }
        }
        void printGraph ()
        {
            int i , j ;
            cout<<endl ;
            for (i= 0 ;i<v_count ; i++)
            {
                for (j=0 ; j<v_count ; j++)
                    cout<<adj[i][j]<<" " ;
                cout<<endl ;
            }
            cout<<endl ;
        }
        
        int getAdjacentNo (int v)
        {
            int c ;
            for (int i=0 ; i<v_count ; i++)
                if (adj[v][i] == 1)
                    c++ ;
            return c ;
        }
        int printAdjacent (int v)
        {
            //cout<<endl<<"Adjacent node of V"<<v<<" is : " ;
            for (int i=0 ; i<v_count ; i++)
                if (adj[v][i] == 1)
                    cout<<"V"<<i<<" " ;
        }

        void isolated (int v)
        {
            int i ;
            for (i =0 ; i<v_count ; i++)
                if (adj[v][i] == 1)
                {
                    cout<<"\nNo , V"<<v<<" is not a isolated node " ;
                    break ;
                }
            
            if (i == v_count)    
                cout<<"\nYES , V"<<v<<" is a isolated node " ;
        }
        ~GraphMatrix()
        {
            int i ;
            for (i=0 ; i<v_count ; i++)
                delete [] adj[i] ;
            delete [] adj ;
        }

        void BFS ( int s)
        {

            //int *source = adj[s] ;
            bool *v = new bool [v_count]() ;
            //or i can assign false by loop
            for (int i=0 ; i<v_count ; i++)
                v[i] = false ;

            //s = 0 ;
            Queue Q(v_count) ;
            //Q.insert(adj[s]) ;
            Q.insert(s) ;
            v[s] = true ;

            while (! Q.queue_underflow())
            {
                int n = Q.getFront() ;
                Q.deletion() ;
                
                cout<<"V"<<n<<" " ;

                for (int j=0 ; j < v_count; j++)
                {
                    //1. find adjacent node of n 
                    if (adj[n][j] == 1)
                    {
                        /2. check that adjacent node visited or not
                        if (v[j] == false)
                        {
                            Q.insert(j) ;
                            v[j] = true ;
                        }
                    }
                }
            }
            delete [] v ;
        }

        void DFS (int s)
        {
            bool *v = new bool [v_count]() ;

            Stack stack(v_count) ;
            stack.push(s) ;

            v[s] = true ;

            while (! stack.stack_underflow())
            {
                int n = stack.peek() ;
                cout<<"V"<<n<<" " ;
                stack.pop() ;

                //fro find adjacent node of n 
                for (int i=0 ; i<v_count ; i++)
                {
                    if (adj[n][i] == 1)
                    {
                        if (v[i] == false )
                        {
                            stack.push(i) ;
                            v[i] = true ;
                        }
                    }
                }
            }
            delete [] v ;
            
        }


} ;

*/




// Adjacency list representation
class node 
{
    public :
        int item ;
        int vertex ;
        node *next ;
} ;
class adjlist 
{
    private :
        node * start ;
    public :
        node* getStart ()
        {
            return start ;
        }
        adjlist () 
        {
            start = nullptr ;
        }
        void insert_1st (int vno , int data)
        {
            node *n = new node ;
            n->item = data ;
            n->vertex = vno ;
            n->next = start ;
            start = n ;
        }
        void del_1st ()
        {
            node *t = start ;
            start = start->next ;
            delete t ;

        }
        ~adjlist ()
        {
            while (start)
                del_1st() ;
        }
        void showNode ()
        {
            node *t = start ;
            while (t)
            {
                cout<<"(V"<<t->vertex<<","<<t->item<<")"<< " " ;
                t = t->next ;
            }
            
        }


};

class Graphlist
{
    private :
        int vertex ;
        adjlist *arr ;
    public :
        Graphlist()
        {
            vertex = 0 ;
            arr = nullptr ;
        }
        void createGraph (int vno)
        {
            vertex = vno ;
            arr = new adjlist [vno] ;
        }
        void addEdge (int u , int v , int data)
        {
            arr[u].insert_1st(v , data) ;
            arr[v].insert_1st(u , data) ;

        }
        void showGraph ()
        {
            for(int i=0 ; i<vertex ; i++)
            {
                arr[i].showNode() ;
                cout<<endl ;
            }
        }

        void BFS (int s)
        {
            bool *v = new bool [vertex]() ;

            Queue Q(vertex) ;
            Q.insert(s) ;
            v[s] = true ;
            while (!Q.queue_underflow())
            {
                int n = Q.getFront();
                cout<<"V"<<n<<" " ;
                Q.deletion() ;

                //for adjacent node of n 
                node *t = arr[n].getStart() ;
                while (t)
                {
                    if (v[t->vertex] == false)
                    {
                        Q.insert(t->vertex) ;
                        v[t->vertex] = true ;
                    }
                    t = t->next ;
                }

                
            }
            delete [] v ;
        }

        void DFS (int s)
        {
            bool *v = new bool [vertex]() ;

            Stack  S(vertex) ;
            S.push(s) ;
            v[s] = true ;
            while (! S.stack_underflow())
            {
                int n = S.peek() ;
                cout<<"V"<<n<<" " ;
                S.pop() ;

                //for adjacent node of n 
                node *t = arr[n].getStart() ;
                while (t)
                {
                    if (v[t->vertex] == false)
                    {
                        S.push(t->vertex) ;
                        v[t->vertex] = true ;
                    }
                    t = t->next ;
                }

                
            }
            delete [] v ;
        }



} ;


int main ()
{
    Graphlist obj ;
    obj.createGraph(6) ;

    obj.addEdge(0,1,5) ;
    obj.addEdge(0,2,10) ;
    obj.addEdge(1,2,15) ;

    obj.addEdge(1,3,20) ;
    obj.addEdge(2,3,25) ;
    obj.addEdge(2,4,30) ;

    obj.addEdge(3,4,20) ;
    obj.addEdge(3,5,25) ;
    obj.addEdge(4,5,30) ;

    obj.showGraph() ;

    cout<<endl ;
    obj.BFS(0) ;
    cout<<endl ;
    obj.DFS(0) ;

    
}
