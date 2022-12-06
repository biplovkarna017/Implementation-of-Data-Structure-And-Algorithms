/*
Priority Queue implementing Singly Linked List
Biplov Karna
THA075BCT017
*/
#include<iostream>
#include<conio.h>
using namespace std;
template <typename T = int>

class List{
    struct Node{
        T data;
        int priority;
        struct Node *next;

    };
    struct Node *START;
public:
    List(){
        START = NULL;
    }

void insert_node(){
    struct Node *ptr,*p;
    ptr = START;
    T new_val;
    int prior;
    
    cout<<"New value: ";
    cin>>new_val;
    cout<<"Priority: ";
    cin>>prior;
    
    p = new Node();
    p->data=new_val;
    p->priority=prior;

if(ptr==NULL){
    p->next=START;
    START=p;
}
else{
    while(ptr->next!=NULL){
        if(ptr->priority<=prior&&ptr->next->priority>prior)
            break;
        ptr=ptr->next;
    }
    if(ptr->priority>prior){
        p->next=START;
        START=p;
    }
    else{
        p->next=ptr->next;
        ptr->next=p;        
    }
}
}
void delete_node(){
struct Node *p;
p = START;
if(p==NULL)
    cout<<"Empty List"<<endl;
else{
cout<<"Deleted value: "<<START->data<<endl;
START = START->next;
delete p;
getch();
}
}
void delete_all(){
    while(START!=NULL){
        delete_node();
    }
}
void display(){
    struct Node* p;
    p =START;
if(p==NULL)
    cout<<"Empty list";
else{
    cout<<"List = [ ";
        while(p!=NULL){
            cout<<p->data<<" ";
            p=p->next;
        }
    cout<<"]";
}
}
void length(){
int ctr=0;
struct Node* p;
p = START;
while(p!=NULL){
    ctr++;
    p=p->next;
}
cout<<"The length of the list is "<<ctr;
getch();
}
};

int main(){
 class List <int>L1;
 int ch;
 char chk='Y';
 int val;
 while(1){
cout<<"Please choose any one of the options: "<<endl;

cout<<"1. Insert a node. "<<endl;
cout<<"2. Display the queue. "<<endl;
cout<<"3. Delete a node. "<<endl;
cout<<"4. Delete whole queue."<<endl;
cout<<"5. Length of the queue. "<<endl;
cout<<"6. Exit. "<<endl;
cin>>ch;

switch(ch){

case 1:
    while(chk=='Y'||chk=='y'){
        L1.insert_node();
        cout<<"Insert more? Y/N: ";
        cin>>chk;
    }
    chk='Y';
    break;
case 2:
    L1.display();
    getch();
    break;
case 3:
    L1.delete_node();
    break;
case 4:
    L1.delete_all();
    break;
case 5:
    L1.length();
    break;
case 6:
    exit(1);
default:
    cout<<"Invalid Choice!"<<endl;
    break;
}
system("CLS");
}
}
