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
bool check_circular(node *head){
    if(head==NULL){
        return false;
    }
    if(head->next==head)return true;
    node *temp=head->next;
    while(temp!=NULL && temp!=head){
        if(temp->next==head){
            return true;

        }
        temp=temp->next;
    }
    return false;
}
void insert(node * &head,int data){
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
void display1(node *head){
    node *temp=head;
    cout<<temp->data<<" ";
    temp=temp->next;
    while(temp!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"Head"<<endl;
}
int main(){
node *head=NULL;
node *head1=NULL;
for(int i=1;i<=6;i++){
    insertfi(head,i);
    insert(head1,i);
}
display1(head1);
cout<<check_circular(head1)<<endl;
cout<<check_circular(head);
}
