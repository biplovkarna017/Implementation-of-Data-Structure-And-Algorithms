/*
Doubly Circular Linked List
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
        struct Node *next,*prev;
    };
    struct Node *START;
public:
    List(){
        START = NULL;
    }

void insert(T info,bool END){
    struct Node* p;
    p = new Node();
    p->data=info;
    if(START==NULL){
        START=p;
        p->next=START;
        p->prev=START;
    }
    else{
    p->next=START;
    p->prev=START->prev;
    START->prev->next=p;
    START->prev=p;
    if(END!=true)
        START=p;
    }

}
void insert_after(){
    struct Node *ptr,*p;
    ptr = START;
    T new_val,pre_val;
    cout<<"New value: ";
    cin>>new_val;
if(ptr==NULL){
    cout<<"Empty List"<<endl;
    cout<<"Wanna add to the beginning? Y/N"<<endl;
    char ch;
    cin>>ch;
    if(ch == 'Y'|| ch == 'y')
        insert(new_val,false);
    else
        return;
}
else{
    cout<<"Insert after: ";
    cin>>pre_val;

    do{
        if(ptr->data==pre_val)
            break;
        ptr=ptr->next;
    }while(ptr!=START);
    if(ptr->data==pre_val){
        p = new Node();
        p->data=new_val;
        p->next=ptr->next;
        p->prev=ptr;
        ptr->next->prev=p;
        ptr->next=p;          
        
    }
    else{
        cout<<"Value not found!!"<<endl;
        getch();
        return;
    }
}
}
void delete_begend(bool END){
struct Node *p;
p = START;
if(p==NULL)
    cout<<"Empty List"<<endl;
else if(p->next==START){
    cout<<"Deleted value: "<<START->data<<endl;
    START = NULL;
    delete p;
}
else{
    if(END)
        p=START->prev;
    else
        START=p->next;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    cout<<"Deleted value: "<<p->data<<endl;
    delete p;
}
}
void delete_data(T val){
struct Node *p;
p = START;
if(p==NULL)
    cout<<"Empty list!";
else{
    do{
        if(p->data==val)
            break;
        p=p->next;
    }while(p!=START);
    if(p==START&&p->data==val)
        delete_begend(false);
    else if(p->data==val){
        if(p->next==p->prev)
            START=NULL;
        else{
        p->prev->next=p->next;
        p->next->prev=p->prev;
        }
        delete p;
        cout<<"Deleted value: "<<val<<endl;
    }
    else{
        cout<<"Value not found!"<<endl;
    }
    
}
getch();
}
void delete_all(){
    while(START!=NULL){
        delete_begend(false);
    }
}
void display(){
    struct Node* p;
    p =START;
if(p==NULL)
    cout<<"Empty list";
else{
    cout<<"List = [ ";
        do{
            cout<<p->data<<" ";
            p=p->next;
        }while(p!=START);
    cout<<"]";
}

}
void length(){
int ctr=0;
struct Node* p;
p = START;
if(START!=NULL){
do{
    ctr++;
    p=p->next;
}while(p!=START);
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
cout<<"0. Insert at beginning of the list."<<endl;
cout<<"1. Insert at the end of the list. "<<endl;
cout<<"2. Insert after a given node. "<<endl;
cout<<"3. Display the list. "<<endl;
cout<<"4. Delete beginning of the list. "<<endl;
cout<<"5. Delete end of the list."<<endl;
cout<<"6. Delete a given data."<<endl;
cout<<"7. Delete whole list."<<endl;
cout<<"8. Length of the list. "<<endl;
cout<<"9. Size of the list."<<endl;
cout<<"10. Exit. "<<endl;
cin>>ch;

switch(ch){
case 0:
    while(chk=='Y'||chk=='y'){
        cout<<"Please enter the value: ";
        cin>>val;
        L1.insert(val,false);
        cout<<"Insert more? Y/N: ";
        cin>>chk;
    }
    chk='Y';
    break;
case 1:

    while(chk=='Y'||chk=='y'){
        cout<<"Please enter the value: ";
        cin>>val;
        L1.insert(val,true);
        cout<<"Insert more? Y/N: ";
        cin>>chk;
    }
    chk='Y';
    break;
case 2:
    L1.insert_after();
case 3:
    L1.display();
    getch();
    break;
case 4:
    L1.delete_begend(false);
    getch();
    break;
case 5:
    L1.delete_begend(true);
    getch();
    break;
case 6:
    cout<<"Please enter the value to be deleted: ";
    cin>>val;
    L1.delete_data(val);
    break;
case 7:
    L1.delete_all();
    getch();
    break;
case 8:
    L1.length();
    break;
case 9:
    cout<<"The size of list is "<<sizeof(L1)<<endl;
    getch();
    break;
case 10:
    exit(1);
default:
    cout<<"Invalid Choice!"<<endl;
    break;

}
system("CLS");
}


}
