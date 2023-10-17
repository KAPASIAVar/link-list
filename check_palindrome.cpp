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
