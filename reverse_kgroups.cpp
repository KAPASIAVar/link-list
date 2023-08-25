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
node * reversek(node * &head,int k){
    node *prev=NULL;
    node *curr=head;
    node *nxt;
    int i=0;
    while(curr!=NULL && i<k){
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
        i++;

    }
    if(nxt!=NULL){
        head->next=reversek(nxt,k);
    }
    return prev;

}
int main(){
node *head=NULL;
for(int i=1;i<=6;i++){
    insertfi(head,i);
}
node *r=reversek(head,2);
display(r);
}
