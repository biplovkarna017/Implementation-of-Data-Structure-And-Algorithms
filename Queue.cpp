/*
Queue implementation of Doubly Circular Linked List
Biplov Karna
THA075BCT017
*/
#include<iostream>
#include<conio.h>
using namespace std;
template <typename T = int>

class Queue{
    struct Node{
        T data;
        struct Node *next,*prev;
    };
    struct Node *START;
public:
    Queue(){
        START = NULL;
    }

void enqueue(T info){
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
    }
}

void dequeue(){
struct Node *p;
p = START;
if(p==NULL)
    cout<<"Empty List"<<endl;
else if(p->next==START){
    cout<<"Dequeued item: "<<START->data<<endl;
    START = NULL;
    delete p;
}
else{
    START=p->next;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    cout<<"Dequeued item: "<<p->data<<endl;
    delete p;
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
cout<<"The length of the Queue is "<<ctr;
getch();
}
};

int main(){

 class Queue <string>Q1;
 int ch;
 char chk='Y';
 string val;
 while(1){
cout<<"Please choose any one of the options: "<<endl;
cout<<"1. Enqueue."<<endl;
cout<<"2. Dequeue."<<endl;
cout<<"3. Display the Queue. "<<endl;
cout<<"4. Length of the Queue. "<<endl;
cout<<"5. Exit. "<<endl;
cin>>ch;

switch(ch){
case 1:
    while(chk=='Y'||chk=='y'){
        cout<<"Please enter the value: ";
        cin>>val;
        Q1.enqueue(val);
        cout<<"Enqueue more? Y/N: ";
        cin>>chk;
    }
    chk='Y';
    break;
case 2:
    Q1.dequeue();
    getch();
    break;
case 3:
    Q1.display();
    getch();
    break;
case 4:
    Q1.length();
    break;
case 5:
    exit(1);
default:
    cout<<"Invalid Choice!"<<endl;
    break;
}
system("CLS");
}
}
