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
void insertfi(node * &head,int data){
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
void display(node * head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"END"<<endl;
}
void reverse(node * &head){
    node *prev=NULL;
    node *curr=head;
    node *nxt;
    while(curr!=NULL){
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    head=prev;

}
int main(){
node *head=NULL;
for(int i=1;i<=6;i++){
    insertfi(head,i);
}
reverse(head);
  display(head);
}
