#include<bits/stdc++.h>
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
void insertfi(int data,node * &head){
    if(head==NULL){
        node *temp=new node(data);
        temp->next=temp;
        head=temp;
    }
    else{
        node *temp=head->next;
        node *p=new node(data);
        while(temp->next!=head){
            temp=temp->next;
        }
        p->next=head;
        temp->next=p;
        head=p;
        
    }
}
void display(node *head){
    node *temp=head;
    cout<<temp->data<<"->";
    temp=temp->next;
    while(temp!=head){
        cout<<temp->data<<"->";
    temp=temp->next;
    }
    cout<<"Head";
}
void insertend(int data,node * &head){
    if(head==NULL){
        node *temp=new node(data);
        temp->next=temp;
        head=temp;
    }
    else{
        node *temp=head->next;
        while(temp->next!=head){
            temp=temp->next;
        }
        node *p=new node(data);
        temp->next=p;
        p->next=head;
    }
}
void insert(int data,int pos,node * &head){
    if(head==NULL){
        node *temp=new node(data);
        temp->next=temp;
        head=temp;
    }
    else{
        node *temp=head->next;
        int i=0;
        while(i<pos){
            temp=temp->next;
            i++;
        }
        node *p=new node(data);
        p->next=temp->next;
        temp->next=p;
    }
}
void deleteHead(node* &head) {
  if (head == NULL) return; 
  if (head->next == head) { 
    delete head;
    head = NULL;
    return;
  }
  node* temp = head; 
  node* last = head; 
  while (last->next != head) {
    last = last->next;
  }
  last->next = head->next; 
  head = head->next; 
  delete temp; 
}
void deleteend(node * &head){
    if(head==NULL)return;
    if(head->next==head){
        delete head;
        head=NULL;
        return;
    }
    node *temp=head;
    while(temp->next->next!=head){
        temp=temp->next;
    }
    node *ptr=temp->next;
    temp->next=head;
    delete ptr;
}
int main(){
    node *head=NULL;
    insertfi(55,head);
    insertfi(100,head);
    insertend(500,head);
    
    insert(3,2,head);
    //deleteHead(head);
    deleteend(head);
    display(head);
}
