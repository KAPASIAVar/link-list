
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
int main()
{
    node *head=new node(100);
    node *a1=new node(200);
    node *a2=new node(300);
    node *a3=new node(400);
    node *a4=new node(500);
    head->next=a1;
    a1->next=a2;
    a2->next=a3;
    
    a3->next=a4;
    a4->next=a2;
    if(check_loop(head))cout<<"Loop"<<endl;
    else cout<<"No loop"<<endl;
    
    

    return 0;
}
