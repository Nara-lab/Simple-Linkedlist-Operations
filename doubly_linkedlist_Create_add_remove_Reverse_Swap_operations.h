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
    cre(1);
    cre(2);
    cre(3);
    cre(4);
    cre(5);
    cre(6);
    dis();
    return 0;
}