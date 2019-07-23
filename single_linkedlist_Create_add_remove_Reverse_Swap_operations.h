#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;
void create_and_insert(int value)
{
    Node *current,*temp = new Node;
    temp ->data = value;
    temp ->next = NULL;
    if(head == NULL)
    {
        head = temp;
        current = temp;
    }
    else
    {
        current ->next = temp;
        current = temp;
    }
}
void  insert_at_L(int value)
{
    Node *current = head,*temp = new Node;
    
    temp->data = value;
    temp->next = NULL;
    while(current != NULL)
    {
     if(current ->next == NULL)
     {
         current->next = temp;
         current = temp;
     }
     current = current ->next;
    }
    
}

void  insert_at_B(int value)
{
    Node *current = head,*temp = new Node;
    temp ->data = value;
    temp ->next = current;
    current = temp;
    head = current;
    
}
void  insert_at_M(int value)
{
     Node *current = head,*temp = new Node;
     temp ->data = value;
     temp ->next = NULL;
     while(current != NULL)
     {
         if(current ->data == 303)
         {
             temp ->next = current ->next;
             current -> next = temp;
             current = temp;
         }
         current = current ->next;
     }
    
}
void  reverse()
{
    Node *prev = NULL,*current = head,*temp = NULL;
    while(current != NULL)
    {
        temp = current ->next;
        current ->next = prev;
        prev = current;
        current = temp;
    }
    head = prev;
}
void delete_node()
{
    // Node *temp = head;                              // at bigining
    // head = head -> next;
    // delete temp;
    
    Node * temp = head;                                // at end
    while(temp ->next ->next != NULL)
    {
        temp = temp -> next;
    }
    delete temp -> next;
    temp ->next = NULL;
    
    // Node *prev  = head,*current = head ->next;     // at middle
    // while(prev != NULL && current != NULL)
    // {
    //   if(current ->data == 318)
    //      {
    //          prev ->next = current ->next;
    //          delete current;
    //      }
    //     prev = prev ->next;
    //     current = current -> next;
    // }
}
void swap_two_nodes()
{
    // Node *temp = head;      //  swap two nodes by changing data
    // int d = temp ->data;
    // temp ->data = temp -> next ->data;
    // temp ->next -> data = d;
    
    Node *current = head;  // swap two nodes without changing data // by node links
    Node *temp = current;
    current = current -> next;
    temp -> next = current -> next;
    current -> next = temp;
    head = current;
}
void display()
{
    Node *temp = head;
    while(temp != NULL)
    {
        std::cout << temp ->data <<" = " << temp << std::endl;
        temp = temp ->next;
    }
    
}
int main()
{
    for(int i = 301;i<=320;i++)
    {
        create_and_insert(i);
    }
     insert_at_L(56);
     insert_at_L(57);
     insert_at_L(58);
     insert_at_B(3);
     insert_at_B(4);
     insert_at_B(5);
     insert_at_B(6);
     insert_at_M(101);
     insert_at_M(102);
     delete_node();
     swap_two_nodes();
//   reverse();
     display();
 return 0;
}