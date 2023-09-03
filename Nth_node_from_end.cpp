
#include <bits/stdc++.h>

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
void display(node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"end"<<endl;
}

int length(node *head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}
    int getNthFromLast(node *head, int n)
    {
           // Your code here
           if(length(head)<n)return -1;
           if(head==NULL)return 0;
           node *temp=head;
           int x=length(head);
           int y=x-n;
           int i=0;
           while(i<y){
               temp=temp->next;
               i++;
           }
           return temp->data;
           
           
    }
int main()
{
    node *head=new node(100);
    node *a1=new node(100);
    node *a2=new node(300);
    node *a3=new node(100);
    node *a4=new node(500);
    head->next=a1;
    a1->next=a2;
    a2->next=a3;
    
    a3->next=a4;
    a4->next=NULL;
    display(head);
    cout<<endl;cout<<getNthFromLast(head,3);
    
    
    
    

    return 0;
}
