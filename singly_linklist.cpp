
#include <iostream>
using namespace std;
class node{
  public:
  int data;
  node *next;
  node(int data){
      this->data=data;
      this->next=NULL;
  }
};
void insertbtw(node* &head,int data,int x){
    if(head==NULL){
        node *temp=new node(data);
        head=temp;
    }
    else{
        int i=0;
        node *temp=head;
        while(i<x-2){
            temp=temp->next;
            i++;
        }
        node *p=new node(data);
        p->next=temp->next;
        temp->next=p;
    }
}
void display(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"END";
}
void deletehead(node* &head){
    node *temp=head;
    if(head!=NULL){
        head=head->next;
        delete temp;
    }
    
}
void insertfi(node * &head,int data ){
    if(head==NULL){
        node *temp=new node(data);
        head=temp;
    }
    else{
        node *temp=new node(data);
        temp->next=head;
        head=temp;
    }
}
void deleteend(node * &head){
    if(head!=NULL){
        node *temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        node *p=temp->next;
        temp->next=p->next;
        delete p;
    }
}
void deletebtw(int x,node * &head){
    if(head!=NULL){
        node *temp=head;
        int i=0;
        while(i<x-2){
            temp=temp->next;
            i++;
        }
        node *p=temp->next;
        temp->next=p->next;
        delete p;
    }
}
int main()
{
    node *head=NULL;
    insertbtw(head,55,1);
    insertbtw(head,77,2);
    insertbtw(head,100,3);
    insertfi(head,200);
    //deletehead(head);
    //deleteend(head);
    deletebtw(2,head);
    display(head);
    

    return 0;
}
