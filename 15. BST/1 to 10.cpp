
/*1.Define a class BST (Binary Search Tree) with node type pointer root as member
variable. Implement Binary Search Tree using linked representation.
2. In question 1, define a constructor to initialise root pointer with NULL.
3. In question 1, define a method to check if the tree is empty.
4. In question 1, define a method to insert a new element in the BST
5. In question 1, define a method for preorder traversing of BST
6. In question 1, define a method for inorder traversing of BST
7. In question 1, define a method for postorder traversing of BST
8. In question 1, define a method to delete an element from BST
9. In question 1, define a method to search an item in the BST
10. In question 1, define a destructor to release memory of all the nodes of BST.*/


#include<iostream>
#include "11QueueusingArray.cpp"
//#include "12QueueusingLL.cpp"
using namespace std ;

class BST 
{
    private :
        node *root ;
    public :
        BST ()
        {
            root = nullptr ;
        }
       
        isEmpty ()
        {
            return root == nullptr ;
        }
        node* getRoot ()
        {
            return root ;
        }

        node* search (int data)
        {
            if (root)
                return traverse_for_search (data ,root) ;
            return nullptr ;
        }
        node* traverse_for_search (int data , node *root)
        {
            if (root == nullptr)
                return nullptr ;
            if (root->item == data)
                return root ;
            if (root->item > data)
                return traverse_for_search(data , root->left) ;
            if (root->item < data)
                return traverse_for_search(data , root->right) ;
        }

        void insert(int data)
        {
        //ready to node
            node *n = new node ;
            n->item = data ;
            n->left = nullptr ;
            n->right = nullptr ;

        //for root node 
            if (root == nullptr)
                root = n ;
        //remaining node
            else 
            {
                node *t = traverse(data,root) ;

                if (t == nullptr)
                {
                    cout<<endl<<data<<" can't insert , data is same" ;
                    return ;
                }
                if (t->item > data)
                    t->left = n ;
                else if (t->item < data)
                    t->right = n ;
            }
        }
        node* traverse (int data , node *root)
        {
            if (root == NULL) 
                return nullptr ;

            if (root->item == data)
                return nullptr ;
            

            if (root->item > data)
            {
                if (root->left == NULL)
                    return root ;
                else 
                    return traverse(data , root->left) ;
            }
            if (root->item < data)
            {
                if (root->right == NULL)
                    return root ;
                else 
                    return traverse (data , root->right) ;
            }
        }

        void pre_traverse (node *root)
        {
            if (root)
            {
                cout<<root->item<<"  " ;
                pre_traverse(root->left) ;
                pre_traverse(root->right) ;
            }
        }
        void in_traverse (node *root)
        {
            if (root)
            {
                in_traverse(root->left) ;
                cout<<root->item<<"  " ;
                in_traverse(root->right) ;
            }
        }
        void post_traverse (node *root)
        {
            if (root)
            {
                post_traverse(root->left) ;
                post_traverse(root->right) ;
                cout<<root->item<<"  " ;
            }
        }
        void showNode ()
        {
            //cout<<endl<<"Pre Order  : " ;
            //pre_traverse(root) ;
            cout<<endl<<"In Order   : " ;
            in_traverse(root) ;
            //cout<<endl<<"Post Order : " ;
            //post_traverse(root) ;

            cout<<endl<<endl ;
        }

/*
    //level wise traverse using Queue array (access node item)
    void traverse_Q (node *root)
    {
        if (root == nullptr)
            return ;

        node *t=nullptr;

        Queue obj(10) ;
        obj.insert(root->item) ;

        while ( ! obj.queue_underflow())
        {
            cout<<obj.getFront_element()<<" " ;

            t = search(obj.getFront_element()) ;

            if (t->left)
            {
                obj.insert(t->left->item) ;
            }
            if (t->right)
            {
                obj.insert(t->right->item) ;
            }

            obj.deletion() ;
        }
    }
*/
    //level wise traverse using Queue array (access node address)
    void traverse_q (node *root)
    {
        if (root == nullptr)
            return ;

        node *t=nullptr;

        Queue obj(10) ;
        obj.insert(root) ;

        while ( ! obj.queue_underflow())
        {
            t = obj.getFront_element() ;
            cout<<t->item <<" " ;

            if (t->left)
            {
                obj.insert(t->left) ;
            }
            if (t->right)
            {
                obj.insert(t->right) ;
            }
            obj.deletion() ;
        }
        if (obj.queue_underflow())
        {
            cout<<"\nEnd"<<endl ;
            return ;
        }
    }

  /*  //level wise traverse using Queue Linked list
    void traverse_QLL (node *root)
    {
        if (root == nullptr)
            return ;

        QueueLL obj ;
        obj.insert(root->item) ;

        while (! obj.is_empty())
        {
            cout<<obj.get_front_element()<<" " ;

            node *t = obj.get_front() ;
            if (t->left)
                obj.insert(t->left->item) ;
            if (t->right)
                obj.insert(t->right->item) ;
            obj.Delete() ;   
        }
    }
*/





        void insert_with_loop (int data)
        {
            node *n = new node ;
            n->item = data ;
            n->left = nullptr ;
            n->right = nullptr ;

            if (root == nullptr)
                root = n ;
            else 
            {
                node *t = root ;
                while (t)
                {
                    if (t->item == data)
                    {
                        cout<<"\nvalue is duplicate , can not insert" ;
                        delete n ;
                        return ;
                    }
                    if (t->item > data)
                    {
                        if (t->left == NULL)
                        {
                            t->left = n ;
                            return ;
                        }
                        t = t->left ;
                    }
                    if (t->item < data)
                    {
                        if (t->right == NULL)
                        {
                            t->right = n ;
                            return ;
                        }
                        t = t->right ;
                    }
                }
                
            }
        }




    void del (int data)
    {
        if (root == nullptr)
            return ;
        if (root->left == NULL && root->right == NULL)
        {
            delete root ;
            root = nullptr ;
            return ;
        }

        node *t , *p ;

        t = root ;
        p = nullptr ;

        while (t!=NULL) //search data's node 
        {
            if (data == t->item)
                break ;
            if (data < t->item)
            {
                p = t ;
                t = t->left ;
            }
            else if (data > t->item)
            {
                p = t ;
                t = t->right ;
            }
        }
        

        //delete code
        if (t)
        {
            if (t->left == NULL && t->right == NULL) //when t is leaf node or t has no child node
            {  
                if (p->item > t->item)
                    p->left = nullptr ;
                else 
                    p->right = nullptr ;

                delete t ;
            }

            else if (t->left == NULL || t->right == NULL)  //when t has one child node
            {
                if (p->item > t->item)  //when p->left = t ; 
                {
                    if (t->left )    //if t child node is in left side
                        p->left = t->left ;
                    else 
                        p->left = t->right ;
                    delete t ;
                }
                else 
                {
                    if (t->left)
                        p->right = t->left ;
                    else 
                        p->right = t->right ;
                    delete t ;
                }

            }

            else  // t has two child node
            {
                node *temp ; 
                inorder_traverse(root , data , temp) ; //t->item or data same thing
                int copy = temp->item ;
                del (temp->item) ;
                t->item = copy ;
            }
        }
    }
protected :
    void inorder_traverse (node *root  , int data , node* &temp)
    {
        if (root)
        {
            temp = root ;
            inorder_traverse(root->left , data , temp) ;
            if (root->item == data)
                return ;
            inorder_traverse(root->right , data , temp) ;

        }
    }
    
/**************************DELETE USING RECURSION******************************* */  
    
    node* tra (node *root , node* &ptr , int data) //give delete wala node
    {
        if (root)
        {
            if (root->item == data)
                return root ;
            if (root->item > data)
            {
                ptr = root ;
                return tra(root->left ,ptr , data) ;
            }
            if (root->item < data)
            {
                ptr = root ;
                return tra(root->right ,ptr , data) ;
            }
        }
        return nullptr ;
    }

public :
    void del_rec (int data)
    {
        if (root == nullptr)    
            return ;
        if (root->left == NULL && root->right == NULL)
        {
            delete root ;
            root = nullptr ;
            return ;
        }
        node *t ;
        node *ptr=nullptr ;
        t = tra(root , ptr , data) ;
        //ptr = parent node addres 

        if (t)
        {
            if (t->left == NULL && t->right == NULL)
            {
                if (ptr->item > t->item)
                    ptr->left = NULL ;
                else 
                    ptr->right = NULL ;
                delete t ;
            }
            else if (t->left == NULL || t->right == NULL)
            {
                if (ptr->item > t->item)
                {
                    if (t->left)
                        ptr->left = t->left ;
                    else
                        ptr->left = t->right ;
                }
                else 
                {
                    if (t->left)
                        ptr->right = t->left ;
                    else
                        ptr->right = t->right ;
                }
            }
            else 
            {
                node *n = NULL ;
                inorder_traverse(root , data , n) ;
                //now n have some address
                int copy = n->item ;
                del_rec(n->item) ;
                t->item = copy ;
            }
        }

    }
    ~BST ()
    {
        while (root)
        {
            del_rec(root->item) ;
        }
    }

// Sir's Procedure 
    void Deletion (int item)
    {
        root = delNode (root , item) ;
    }
protected :
    node* delNode (node *ptr , int data)
    {
        if (ptr == nullptr)
            return nullptr ;
        if (data < ptr->item)
            ptr->left = delNode(ptr->left , data) ;
        else if (data > ptr->item)
            ptr->right = delNode (ptr->right , data) ;
        else 
        {
            // no child
            if (ptr->left==nullptr && ptr->right==nullptr)
            {
                delete ptr ;
                return nullptr ;
            }
            //else single child
            if (ptr->left==nullptr || ptr->right==nullptr)
            {
                node *child = ptr->left ? ptr->left : ptr->right ;
                delete ptr ;
                return child ;
            }
            // else two children
            node *ptrtemp , *temp ;
            ptrtemp = ptr ;
            temp = ptr->left ;
            
            while (temp->right)
            {
                ptrtemp = temp ;
                temp = temp->right ;
            }
            ptr->item = temp->item ;
            ptrtemp->right = delNode(temp , temp->item) ;

        }
        return ptr ;

    }


} ;


int main ()
{
    BST obj ;
    obj.insert_with_loop(60) ;
    
    obj.showNode() ;

    obj.Deletion(60) ;
    obj.showNode() ;

}

