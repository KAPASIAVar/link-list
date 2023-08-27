
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
int check_loop(node *head){
    node *slow=head;
    node *fast=head;
    while(fast!=NULL && fast->next!=NULL){
        
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return 1;
        }
    }
    return 0;
}
void remove_loop(node * &head){
    node *slow=head;
    node *fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast || fast->next==slow){
            node *temp=slow;
            while(temp->next!=slow){
                temp=temp->next;
            }
            temp->next=NULL;
            return;
        }
    }
}
void display(node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"end"<<endl;
}
void remove_duplicate(node * &head ){
    if(head==NULL || head->next==NULL){
        return;
    }
    node *prev=NULL;
    unordered_set<int>st;
    node *curr=head;
    while(curr!=NULL){
        if(st.find(curr->data)!=st.end()){
            node *temp=curr;
            
            curr=curr->next;
            prev->next=curr;
            delete temp;
        }
        else{
            st.insert(curr->data);
            prev=curr;
            curr=curr->next;
        }
    }
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
    remove_loop(head);
    cout<<check_loop(head);
    cout<<endl;
    display(head);
    remove_duplicate(head);
    display(head);
    
    
    

    return 0;
}
