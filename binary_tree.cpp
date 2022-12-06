/*
Binary Search Tree
Biplov Karna
THA075BCT017
*/
#include<iostream>
#include<conio.h>
using namespace std;
struct Node {
    int data;
    struct Node *left,*right;
    Node(){
        left = NULL;
        right = NULL;
    }
};
class BinaryTree{
    Node *root;
    bool avail;

    void insert(Node *&ptr, Node *&p){
            if(ptr==NULL)
                ptr= p;
            else if(p->data>=ptr->data)
                insert(ptr->right,p);
            else
                insert(ptr->left,p);
    }
    void inorder(Node *&ptr){
            //left root right
                if(ptr->left!=NULL){
                    inorder(ptr->left);
                }
                cout<<ptr->data<<" ";
                if(ptr->right!=NULL){
                    inorder(ptr->right); 
                }         
        }
    void preorder(Node *&ptr){
        //root left right
        cout<<ptr->data<<" ";
        if(ptr->left!=NULL){
            preorder(ptr->left);
        }
        if(ptr->right!=NULL){
            preorder(ptr->right);
                
        }
    }
    void postorder(Node *&ptr){
        //left right root
        if(ptr->left!=NULL){
            postorder(ptr->left);
        }
        if(ptr->right!=NULL){
            postorder(ptr->right);  
        }
        cout<<ptr->data<<" ";
    }
    void search(Node *&ptr,int &val){
            //left right root
            if(ptr->left!=NULL){
               search(ptr->left,val);
            }
            if(ptr->right!=NULL){
               search(ptr->right,val);  
            }
            if(ptr->data==val){
                avail = true;
            }       
        }
    int find_max(Node *&ptr){
    if(ptr->right!=NULL)
        find_max(ptr->right);
    else
    {
        int dum = ptr->data;
        Node *temp;
        temp = ptr;
        ptr = NULL;
        delete temp;
        return dum;
    }
    
}
    void delete_data(Node *&ptr,int &val){
        Node *temp;
            if(ptr->left!=NULL){
            delete_data(ptr->left,val);
        }
        if(ptr->right!=NULL){
            delete_data(ptr->right,val); 
        }
        if(ptr->data==val){ 
            if(ptr->left==NULL && ptr->right==NULL){
                temp = ptr;
                ptr = NULL;
                delete temp;
            }
            else if(ptr->left!=NULL && ptr->right==NULL){
                temp = ptr;
                ptr = ptr->left;
                delete temp;
            }
            else{

            ptr->data = find_max(ptr);
            temp = ptr->right;
            ptr->right = NULL;
            if(temp!=NULL)
                insert(ptr, temp); 
            }
            cout<<val<<" is deleted!"<<endl;
        }
    }
    
    public:
        BinaryTree(){
            root=NULL;
            avail = false;
        }
      
        void insert_data(int &val){
            Node *p;
            p = new Node();
            p->data = val;
            insert(root,p);
        }
        void display(int ch){
            Node *ptr;
            ptr=root;
            if(ptr==NULL)
                cout<<"The tree is empty"<<endl;
            else{
                switch(ch){
                    case 1: inorder(ptr);   break;
                    case 2: preorder(ptr);  break;
                    case 3: postorder(ptr); break;
                }
            }
        }
        void search_data(int &val){
            Node *ptr;
            ptr=root;
            if(ptr!=NULL)
                search(ptr,val);
            if(avail){
                cout<<"Value found";
                avail = false;
            }
            else
                cout<<"Not found";
        }
        void delete_val(int &val){
            if(root!=NULL)
                delete_data(root,val);
            else
                cout<<"The tree is empty"<<endl;
        }
        
};
int main(){
    BinaryTree b;
     int ch,chh;
    char chk='Y';
    int val;
    while(1){
        cout<<"Please choose any one of the options: "<<endl;
        cout<<"1. Insert."<<endl;
        cout<<"2. Display."<<endl;
        cout<<"3. Search."<<endl;
        cout<<"4. Delete."<<endl;
        cout<<"5. Exit. "<<endl;
        cin>>ch;

        switch(ch){
        case 1:
            while(chk=='Y'||chk=='y'){
                cout<<"Please enter the value: ";
                cin>>val;
                b.insert_data(val);
                cout<<"Insert more? Y/N: ";
                cin>>chk;
            }
            chk='Y';
            break;
        case 2:
            system("CLS");
            cout<<"Please choose any one of the options: "<<endl;
            cout<<"1. Inorder."<<endl;
            cout<<"2. Preorder."<<endl;
            cout<<"3. Postorder. "<<endl;
            cout<<"4. Exit."<<endl;
            cin>>chh;
            switch(chh){
                case 1:
                    b.display(1);
                    getch();
                    break;
                case 2:
                    b.display(2);
                    getch();
                    break;
                case 3:
                    b.display(3);
                    getch();
                    break;
                default:
                    break;
            }
            break;
        case 3:
            cout<<"Enter the value: ";
            cin>>val;
            b.search_data(val);
            getch();
            break;
        case 4:
            cout<<"Enter the value: ";
            cin>>val;
            b.delete_val(val);
            getch();
            break;
        default:
            exit(1);
            break;
        }
        system("CLS");
    }
}