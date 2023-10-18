
#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}



class Solution{
  public:
    
    Node *merge(Node *head1,Node *head2){
        if(head1==NULL)return head2;
        if(head2==NULL)return head1;
        Node *dummy=new Node(-1);
        Node *temp=dummy;
        while(head1 && head2){
            if(head1->data<head2->data){
                temp->next=head1;
                temp=head1;
                head1=head1->next;
            }
            else{
                temp->next=head2;
                temp=head2;
                head2=head2->next;
            }
            
        }
        while(head1){
            temp->next=head1;
                temp=head1;
                head1=head1->next;
        }
        while(head2){
            temp->next=head2;
                temp=head2;
                head2=head2->next;
        }
        temp->next=NULL;
        return dummy->next;
    }
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           if(K==1){
               return arr[0];
           }
           Node *ans=merge(arr[0],arr[1]);
           for(int i=2;i<K;i++){
               ans=merge(ans,arr[i]);
           }
           return ans;
    }
};

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends
