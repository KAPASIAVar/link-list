#include<iostream>
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
void insert(node * &head,int data){
    if(head==NULL){
        node *temp=new node(data);
        head=temp;

    }
    else{
        node *temp=head;
        while(temp->next){temp=temp->next;}
        node *p=new node(data);
        temp->next=p;
    }
}
void display(node * head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"END"<<endl;
}
node * mid(node *head){
    
    node *slow=head;
    node *fast=head->next;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
node *rev(node* &head){
    node *prev=NULL;
    node *curr=head;
    node *nxt=NULL;
    while(curr!=NULL){
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    return prev;
}
bool check(node * &head){
    if(head->next==NULL)return true;
    node *middle=mid(head);
    node *temp=middle->next;
    
    middle->next=rev(temp);
    node *head1=head;
    node *head2=middle->next;
    while(head2!=NULL){
        if(head2->data!=head1->data)return false;
        head2=head2->next;
        head1=head1->next;
    }
    return true;
}
