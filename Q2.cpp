/*
Singly Circular Linked List
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
        struct Node *next;
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
        p->next=START;
        preptr = START;
        while(preptr->next!=START){
            preptr=preptr->next;
        }
        preptr->next= p;
    }
}
void insert_beg(T info){
    struct Node* p,*ptr;
    p = new Node();
    p->data=info;
    if(START==NULL){
        START=p;
        p->next=START;  
    }
    else{ 
        p->next=START;
        ptr=START;
        while(ptr->next!=START){
        ptr=ptr->next;
        }
        START=p;
        ptr->next=START;
    }
}
void insert_after(){
    struct Node *ptr,*p,*temp;
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
    do{
        if(ptr->data==pre_val)
            break;
        ptr=ptr->next;
    }while(ptr!=START);
    if(ptr->data==pre_val){
        p = new Node();
        p->data=new_val;
        p->next=ptr->next;
        ptr->next=p;        
    }
    else{
        cout<<"Value not found!!"<<endl;
        getch();
        return;
    }
}
}
void delete_beg(){
struct Node *p,*ptr;
p = START;
ptr=p;
if(p==NULL)
    cout<<"Empty List"<<endl;
else if(p->next==START){
    ptr=START;
    cout<<"Deleted value: "<<ptr->data<<endl;
    START=NULL;
    delete ptr;
}
else{
int temp = START->data;
while(ptr->next!=START){
    ptr=ptr->next;
}
START = p->next;
ptr->next=START;
delete p;
cout<<"Deleted value: "<<temp<<endl;

}
}
void delete_end(){
struct Node *p,*tp;
p = START;
tp=p;
if(p==NULL){
    cout<<"Empty List"<<endl;
    getch();
}
else if(p->next==START)
        delete_beg();
else{
    p=p->next;
    while(p->next!=START){
        p=p->next;
        tp=tp->next;
    }
    cout<<"Deleted value: "<<p->data<<endl;
    tp->next=START;
    delete p;
    getch();
}
}
void delete_data(){
T val;
cout<<"Value: ";
cin>>val;
struct Node *p,*temp;
p = START;
temp=p;
if(p==NULL)
    cout<<"Empty list!";
else if(p->next==START||p->data==val){
    if(p->data==val){
        delete_beg();
        return;
    }
    else{
        cout<<"Value not found";
    }
    
}
else{
    p=p->next;
    do{
        if(p->data==val)
            break;
        p=p->next;
        temp=temp->next;
    }while(p!=START);
    if(p->data!=val&&p==START)
        cout<<"Value not found!"<<endl;
    else if(p->data==val){
        temp->next=p->next;
        delete p;
        cout<<"Deleted value: "<<val<<endl;
    }
}
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
if(p!=NULL){
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
cout<<"2. Insert after a given value. "<<endl;
cout<<"3. Delete beginning of the list. "<<endl;
cout<<"4. Delete end of the list."<<endl;
cout<<"5. Delete a given value."<<endl;
cout<<"6. Delete whole list."<<endl;
cout<<"7. Display the list."<<endl;
cout<<"8. Length of the list. "<<endl;
cout<<"9. Exit. "<<endl;
cin>>ch;

switch(ch){
case 0:
    while(chk=='Y'||chk=='y'){
        cout<<"Please enter the value: ";
        cin>>val;
        L1.insert_beg(val);
        cout<<"Insert more? Y/N";
        cin>>chk;
    }
    chk='Y';
    break;
case 1:

    while(chk=='Y'||chk=='y'){
        cout<<"Please enter the value: ";
        cin>>val;
        L1.insert_end(val);
        cout<<"Insert more? Y/N";
        cin>>chk;
    }
    chk='Y';
    break;
case 2:
    L1.insert_after();
    getch();
    break;
case 3:
    L1.delete_beg();
    getch();
    break;
case 4:
    L1.delete_end();
    break;
case 5:
    L1.delete_data();
    getch();
    break;
case 6:
    L1.delete_all();
    getch();
    break;
case 7:
    L1.display();
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
