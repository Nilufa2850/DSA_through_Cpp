#include<iostream>
using namespace std ;

class Graph
{
    private :
        int v_count ;
        int e_count ;
        int **adj ;
    public :
        Graph ()
        {
            adj = nullptr ;
        }
        void createGraph (int vno , int eno)
        {
            v_count = vno ;
            e_count = eno;

            //2d array create
            adj = new int*[v_count];
            int i ;
            for (i=0 ; i < v_count ; i++)
                adj[i] = new int [v_count]() ;
            
            //input 
            int u, v ;
            for(int k=0 ; k<e_count ; k++)
            {
                cout<<"\nEnter node no connecting edges : " ;
                cin>>u>>v ;

                adj[u][v] = 1 ;
                adj[v][u] = 1 ;
            }
        

        }
        void showMatrix ()
        {
            cout<<endl<<"********Adjacency Matrix Representation*********"<<endl ;
            int i , j ;
            for (i=0 ; i<v_count ; i++)
            {
                for (j=0 ; j<v_count ; j++)
                    cout<<adj[i][j]<<" " ;
                cout<<endl ;
            }
            cout<<endl ;
        }
        void showAdjacentNode (int n)
        {
            cout<<endl<<"All adjacent node of node V"<<n<<" is : "<<endl ;
            if (n >= 0 && n<= v_count-1)
            {
                for (int j=0 ; j<v_count ; j++)
                    if (adj[n][j] == 1)
                        cout<<"V"<<j<<" " ;
                    
                cout<<endl ;
            }
            else 
                cout<<"\nNode is invalid" <<endl ;
        }

        void isolated_node (int n)
        {
            int j ;
            if (n >= 0 && n<= v_count-1)
            {
                for (j=0 ; j<v_count ; j++)
                    if (adj[n][j] != 0)
                        break ;
                        
                if (j == v_count)
                    cout<<"\nV"<<n<<" node is a isolated node" ;
                else 
                    cout<<"\nV"<<n<<" node is not a isolated node" ;
            }
        }

        ~Graph()
        {
            for (int i=0 ; i<v_count ; i++)
                delete [] adj[i] ;
            delete []adj ;
        }
} ;



void menu ()
{
    cout<<"***************************"<<endl ;
    cout<<endl<<"1. Create a Adjacency Matrix";
    cout<<endl<<"2. Show Adjacency Matrix";
    cout<<endl<<"3. Show Adjacency Node";
    cout<<endl<<"4. Isolated Node";
    cout<<endl<<"5. Exit" ;
    cout<<endl ;
}
int main ()
{
    Graph obj ;

    menu() ;
    int x ,y;
    while (true)
    {
        cout<<"\nEnter your choice : " ;
        cin>>x ;

        switch(x)
        {
            case 1: obj.createGraph(6,6) ;
                    break ;
            case 2: obj.showMatrix() ;
                    break ;
            case 3: cout<<"\nEnter node no . for see adjacent : ";
                    cin>>y ;
                    obj.showAdjacentNode(y) ;
                    break ;
            case 4: cout<<"\nEnter node no . for see isolated node or not : ";
                    cin>>y ;
                    obj.isolated_node(y) ;
                    break ;
            case 5:
                    return 0;
            default :
                    cout<<"\nYour choice is invalid" ;
        }
    }
    return 0 ;
} 
