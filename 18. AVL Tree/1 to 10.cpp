#include<iostream>
#include<algorithm>
using namespace std ;

struct node
{
    node *left ;
    int item ;
    node *right ;
    int height ;
} ;
class AVL
{
    private :
        node *root ;
    protected :
        int getHeight(node* ptr)
        {
            if(ptr==NULL)
                return 0;
            return ptr->height;
        }
        int get_BF (node *ptr)
        {
            if(ptr == nullptr)
                return 0 ;
            return (getHeight(ptr->left) - getHeight(ptr->right)) ;
        }
        int get_H (node *ptr)
        {
            int LN = ptr->left ? ptr->left->height : 0 ;
            int RN = ptr->right ? ptr->right->height : 0 ;

            return 1+ max(LN,RN) ;
        }
        
        node* Delete_Node (node *root , int data)
        {
            if (root == nullptr)
                return nullptr ;
            if (root->item > data)
                root->left = Delete_Node(root->left , data) ;
            else if (root->item < data)
                root->right = Delete_Node(root->right , data) ;
            else 
            {
                //no child
                if (root->left == nullptr && root->right == nullptr)
                {
                    delete root ;
                    return nullptr ;
                }
                //single child
                if (root->left == nullptr || root->right == nullptr)
                {
                    node *child = root->left ? root->left : root->right ;
                    delete root ;
                    return child ;
                }
                //two children
                node *par_temp , *temp ;
                par_temp = root ;
                temp = root->left ;

                while (temp->right != nullptr)
                {
                    par_temp = temp ;
                    temp = temp->right ;
                }
                root->item = temp->item ;
                par_temp->right = Delete_Node(temp , temp->item) ;
            }
            

            /*2. After delete update height*/
            root->height = get_H(root) ;


            /*3. check balance out of permissible range or not*/
            int balance = get_BF(root) ;

            /*LL case*/
            if (balance>1 && root->left->item > data)
                return RightRotate(root) ;

            /*RR case*/
            if (balance < -1 && root->right->item < data)
                return LeftRotate(root) ;
            
            /*LR case */
            if (balance>1 && root->left->item < data)
            {
                root->left = LeftRotate(root->left) ;
                return RightRotate(root) ;
            }
            /*RL case*/
            if (balance < -1 && root->right->item > data)
            {
                root->right = RightRotate(root->right) ;
                return LeftRotate(root) ;
            }
            
            return root ;

        }
        
        node* traverse_forSearch (node *ptr , int data)
        {
            if (ptr)
            {
                if (ptr->item == data)
                    return ptr ;
                if (ptr->item > data)
                    return traverse_forSearch(ptr->left , data) ;

                return traverse_forSearch(ptr->right , data) ;
            }
            return ptr ;
        }
        
        node* insertion (node *ptr , int data)
        {
        //1. find position , and inserted
            if (ptr == nullptr)
            {
                node *n = new node ;
                n->item = data ;
                n->left = nullptr ;
                n->right = nullptr ;
                n->height = 1 ;

                return n ;
            }
            else if (ptr->item  >  data)
                ptr->left = insertion(ptr->left , data) ;
            else if (ptr->item  <  data)
                ptr->right = insertion(ptr->right , data) ;
            else  //duplicate value not allowed
                return ptr ;

        //2. Update height after insertion
            ptr->height = get_H(ptr) ;

         //3. check balance out of range or not

            int balance = get_BF(ptr) ;

            //case 1: LL Rotation
            if (balance >1 && ptr->left->item  > data)
                return RightRotate(ptr) ;
            //case 2: RR Rotation  
            if (balance <-1 && ptr->right->item  < data)
                return LeftRotate(ptr) ;
            //case 3: LR Rotation
            if (balance >1 && ptr->left->item < data)
            {
                ptr->left = LeftRotate(ptr->left) ;
                return RightRotate(ptr) ;
            }
            //case 4: RL Rotation
            if (balance <-1 && ptr->right->item > data)
            {
                ptr->right = RightRotate(ptr->right) ;
                return LeftRotate(ptr) ;
            }
            
            return ptr ;
        }
    
    public :
        node* getRoot()
        {
            return root ;
        }
        AVL ()
        {
            root = nullptr ;
        }
        ~AVL ()
        {
            while (root)
                Delete(root->item) ;
        }
        node* LeftRotate (node *A) //Anti clockwise rotation
        {
            node *B = A->right ;
            node *L_B = B->left ;
            
            B->left = A ;
            A->right = L_B ;
            
            //Edit height
            A->height = get_H(A) ;
            B->height = get_H(B) ;

            return B ;
         
        }
        node* RightRotate (node *A) //Clockwise rotation
        {
           node *B = A->left ;
           node *R_B = B->right ;

            B->right = A ;
            A->left = R_B ;

            //Edit height
            A->height = get_H(A) ;
            B->height = get_H(B) ;

            return B ;
        }


        void insert (int data)
        {
            root = insertion(root , data) ;
        }
        
        void Delete (int data)
        {
            root = Delete_Node (root , data) ;
        }
        
        
        //traverse 
        void in_traverse (node *root)
        {
            if (root)
            {
                in_traverse(root->left) ;
                cout<<"("<<root->item<<"|"<<get_BF(root)<<")"<<" " ;
                in_traverse(root->right) ;
            }
        }
        void pre_traverse (node *root)
        {
            if (root)
            {
                cout<<root->item<<"|"<<root->height<<" " ;
                pre_traverse(root->left) ;
                pre_traverse(root->right) ;
            }
        }
        void post_traverse (node *root)
        {
            if (root)
            {
                post_traverse(root->left) ;
                post_traverse(root->right) ;
                cout<<root->item<<"|"<<root->height<<" " ;
            }
        }
        node* search (int data)
        {
            return traverse_forSearch (root , data) ;
        }

} ;


int main ()
{
    AVL obj ;
    obj.insert(70) ;
    obj.insert(40) ;
    obj.insert(90) ;
    obj.insert(100) ;
    obj.insert(120) ;
    
    
    cout<<endl ;
    obj.in_traverse(obj.getRoot()) ;

    obj.Delete(120) ;
    cout<<endl ;
    obj.in_traverse(obj.getRoot()) ;

}

