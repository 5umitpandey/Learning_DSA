/*
Q. Given a LL, reverse every K nodes.
Eg: K = 3, list should be changed from 
LL: 1, 2, 3, 4, 5, 6, 7, 8
New LL: 3 2 1 6 5 4 8 7
*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *nxt = nullptr;

    Node (int val) : data(val), nxt(nullptr) {}
};


Node *Rev_By_K(Node *head, int k) 
{
    Node *cur = head; Node *nxt = nullptr; Node *newHead = nullptr;
    int c = 0;

    while (cur != nullptr && c < k) 
    {
        nxt = cur -> nxt; cur -> nxt = newHead;

        newHead = cur; cur = nxt;

        c++;
    }

    if (nxt != nullptr) 
    {
        head -> nxt = Rev_By_K(nxt, k);
    }

    return newHead;
}


int main() 
{
    Node *head = new Node(11);
    Node *temp = head;
    for (int i = 12; i <= 18; i++) 
    {
        temp -> nxt = new Node(i);
        temp = temp -> nxt;
    }

    cout << "Linked List before reversing: ";
    temp = head;
    while (temp != nullptr) 
    {
        cout << temp -> data << " ";
        temp = temp -> nxt;
    }
    cout << "\n";


    head = Rev_By_K(head, 5);


    cout << "Linked List after reversing by 3 nodes: ";
    temp = head;
    while (temp != nullptr) 
    {
        cout << temp -> data << " ";
        temp = temp -> nxt;
    }
    cout << "\n";

    return 0;
}