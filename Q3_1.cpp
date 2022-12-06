/*
Doubly Linked List
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
void insert_end(T info){
    if (START == NULL){
            insert_beg(info);
    }
    else{
        struct Node* p, *preptr;
        p = new Node();
        p->data=info;
        preptr = START;
        while(preptr->next!=NULL){
            preptr=preptr->next;
        }
        preptr->next= p;
        p->next=NULL;
        p->prev=preptr;
    }
}
void insert_beg(T info){
    struct Node* p;
    p = new Node();
    p->data=info;
    p->next=START;
    START=p;
    p->prev=START;

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
        insert_beg(new_val);
    else
        return;
}
else{
    cout<<"Insert after: ";
    cin>>pre_val;

    while(ptr->next!=NULL){
        if(ptr->data==pre_val)
            break;
        ptr=ptr->next;
    }
    if(ptr->data==pre_val){
        p = new Node();
        p->data=new_val;
        p->next=ptr->next;
        ptr->next=p;
        p->prev=ptr;
        if(p->next!=NULL)
            p->next->prev=p;
        
    }
    else{
        cout<<"Value not found!!"<<endl;
        getch();
        return;
    }
}
}
void delete_beg(){
struct Node *p;
p = START;
if(p==NULL)
    cout<<"Empty List"<<endl;
else{
cout<<"Deleted value: "<<START->data<<endl;
START = START->next;
if(START!=NULL)
    START->prev=START;
delete p;
}
}
void delete_end(){
struct Node *p;
p = START;
if(p==NULL)
    cout<<"Empty List"<<endl;
else if(p->next==NULL)
        delete_beg();
else{
    while(p->next!=NULL){
        p=p->next;
    }
    cout<<"Deleted value: "<<p->data<<endl;
    p->prev->next=NULL;
    delete p;  
}
getch();
}
void delete_data(T val){
struct Node *p;
p = START;
if(p==NULL)
    cout<<"Empty list!";
else{
    while(p->next!=NULL){
        if(p->data==val)
            break;
        p=p->next;
    }
    if(p==START&&p->data==val)
        delete_beg();
    else if(p->data==val){
        if(p->next!=NULL)
            p->next->prev=p->prev;
        p->prev->next=p->next;
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
        delete_beg();
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
cout<<"0. Insert at beginning of the list."<<endl;
cout<<"1. Insert at the end of the list. "<<endl;
cout<<"2. Insert after a given node. "<<endl;
cout<<"3. Display the list. "<<endl;
cout<<"4. Delete beginning of the list. "<<endl;
cout<<"5. Delete end of the list."<<endl;
cout<<"6. Delete a given data."<<endl;
cout<<"7. Delete whole list."<<endl;
cout<<"8. Length of the list. "<<endl;
cout<<"9. Exit. "<<endl;
cin>>ch;

switch(ch){
case 0:
    while(chk=='Y'||chk=='y'){
        cout<<"Please enter the value: ";
        cin>>val;
        L1.insert_beg(val);
        cout<<"Insert more? Y/N: ";
        cin>>chk;
    }
    chk='Y';
    break;
case 1:

    while(chk=='Y'||chk=='y'){
        cout<<"Please enter the value: ";
        cin>>val;
        L1.insert_end(val);
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
    L1.delete_beg();
    getch();
    break;
case 5:
    L1.delete_end();
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
    exit(1);
default:
    cout<<"Invalid Choice!"<<endl;
    break;

}
system("CLS");
}


}
