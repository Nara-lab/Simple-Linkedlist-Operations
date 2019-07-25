#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;
    Node *prev;
};
Node *head,*current;
void cre(int value)
{
    Node *temp = new Node;
    temp ->data = value;
    temp ->next = NULL;
    temp ->prev = NULL;
    if(head == NULL)
    {
        head = temp;
        current = temp;
    }
    else
    {
      current ->next = temp;
      temp ->prev = current;
      current = temp;
    }
}
void insert_at_end(int value)
{
    Node *temp = current,*temp_new = new Node;
    temp_new ->data = value;
    temp_new ->next = NULL;
    temp_new ->prev = NULL;
    temp_new ->prev = temp;
    temp ->next = temp_new;
    temp = temp_new;
    current = temp;
}
void insert_at_bigin(int value)
{
    Node *temp_new = new Node,*temp1 = head;
    temp_new ->data = value;
    temp_new ->next = NULL;
    temp_new ->prev = NULL;
    temp1 ->prev = temp_new;
    temp_new ->next = temp1;
    head = temp_new;
    
}
void insert_at_middle(int value)
{
    Node *new_node = new Node,*current = head,*current1 = head -> next;;
    new_node ->data = value;
    new_node -> next = NULL;
    new_node -> prev = NULL;
    while(current != NULL && current1 != NULL)
    {
        if(current -> data == 3)
        {
            Node *tem1 = current -> next;
            Node *tem2 = current1 -> prev;
            new_node ->next = current -> next;
            current -> next = new_node;
            current1 -> prev = new_node;
            new_node ->prev = tem2;
        }
        current = current -> next;
        current1 = current1 -> next;
    }
}
void dis()
{

    Node *temp = head, *temp1 = current;
    while(temp != NULL)
    {
        std::cout << temp ->data << "=" << temp << std::endl;
        temp = temp -> next;
    }
    cout << "print through previous pointer in reverse order"<< endl;
    while(temp1 != NULL)
    {
         std::cout << temp1 ->data << "=" << temp1 << std::endl;
        temp1 = temp1 -> prev;
    }
}
int main()
{
    for(int i = 2;i<=4;i++)
    {
        cre(i);
    }
    insert_at_end(5);
    insert_at_bigin(1);
    insert_at_middle(20);
    dis();
    return 0;
}