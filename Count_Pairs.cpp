
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void append( Node** headRef,  Node** tailRef, int newData) {
    struct Node* new_node = new Node(newData);

    if (*headRef == NULL) {
        *headRef = new_node;
    }

    else {
        (*tailRef)->next = new_node;
    }
    *tailRef = new_node;
}

void printList(struct Node* head) {
    while (head) {
        cout << head->data << ' ';
        head = head->next;
    }
}



class Solution{
  public:
    
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        
        int count=0;
        unordered_set<int>st;
        while(head2){
            st.insert(head2->data);
            head2=head2->next;
        }
        while(head1){
            int data=head1->data;
            if(st.find(x-data)!=st.end())count++;
            head1=head1->next;
        }
        return count;
    }
};


int main() {
    int T;
    cin >> T;
    while (T--) {
        struct Node* head1 = NULL;
        struct Node* tail1 = NULL;
        struct Node* tail2 = NULL;
        struct Node* head2 = NULL;
        int n1, n2, tmp, x;
        cin >> n1;
        while (n1--) {
            cin >> tmp;
            append(&head1, &tail1, tmp);
        }
        cin >> n2;
        while (n2--) {
            cin >> tmp;
            append(&head2, &tail2, tmp);
        }
        cin >> x;
        Solution obj;
        cout << obj.countPairs(head1, head2, x) << '\n';
    }
    return 0;
}
