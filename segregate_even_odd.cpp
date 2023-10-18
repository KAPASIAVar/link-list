#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insert(node *&head, int data)
{
    if (head == NULL)
    {
        node *temp = new node(data);
        head = temp;
    }
    else
    {
        node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        node *p = new node(data);
        temp->next = p;
    }
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "END" << endl;
}
int mid(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}
node *solve(node *head)
{
    node *dummy1 = new node(-1);
    node *dummy2 = new node(-1);
    node *temp1 = dummy1;
    node *tem2 = dummy2;
    while (head != NULL)
    {
        if (head->data % 2 == 0)
        {
            temp1->next = head;
            temp1 = head;
            head = head->next;
        }
        else
        {
            tem2->next = head;
            tem2 = head;
            head = head->next;
        }
    }
    temp1->next = NULL;
    tem2->next = NULL;
    temp1->next = dummy2->next;
    return dummy1->next;
}
int main()
{
    node *head = NULL;
    for (int i = 1; i <= 6; i++)
    {
        insert(head, i);
    }
    display(head);
    node *temp = solve(head);
    display(temp);
}
