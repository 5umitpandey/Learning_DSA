/*
Linked List
Linear DS | each node(data, pointer to next node) | Non-Contigous
Used in: Stack, Queue, Graphs, Hash Maps
Types: Singly | Doubly | Circular
Insertion, Deletion at beg: Ω(1)
Insertion, Deletion at end: O(n)
Search: O(n)
Space: O(n)

*/

#include <iostream>
using namespace std;

struct Node 
{
    int data;   // Data part of the node
    Node* next; // Pointer to the next node
};

void insert(Node*& head, int data, int position) 
{
    Node *newNode = new Node();  // Create a new node
    newNode -> data = data;      // Set the data for the new node
    newNode -> next = nullptr;   // Initialize the next pointer to nullptr

    if (position == 0)           // If inserting at the head
    { 
        newNode->next = head;    // Point the new node to the current head
        head = newNode;          // Update the head to the new node
        return;
    }

    Node* temp = head;          // Temporary pointer to traverse the list
    for (int i = 0; temp != nullptr && i < position - 1; i++) 
    {
        temp = temp->next;      // Move to the next node
    }

    if (temp == nullptr) { // If position is out of bounds
        cout << "Position out of bounds" << endl; // Print error message
        delete newNode; // Delete the new node
        return; // Exit the function
    }

    newNode->next = temp->next; // Point the new node to the next node
    temp->next = newNode; // Link the previous node to the new node
}

void deleteNode(Node*& head, int delEle) 
{
    Node* temp = head;    // Temporary pointer to traverse the list
    Node* prev = nullptr; // Pointer to the previous node

    if (temp != nullptr && temp->data == delEle) { // If the head node is to be deleted
        head = temp->next; // Update the head to the next node
        delete temp; // Delete the old head node
        return; // Exit the function
    }

    while (temp != nullptr && temp->data != delEle) { // Traverse the list to find the node
        prev = temp; // Update the previous node
        temp = temp->next; // Move to the next node
    }

    if (temp == nullptr) { // If the element is not found
        cout << "Element not found!" << endl; // Print error message
        return; // Exit the function
    }
    
    prev->next = temp->next; // Link the previous node to the next node
    delete temp; // Delete the node
}

int search(Node* head, int findEle) 
{
    Node *temp = head;      // Temporary pointer to traverse the list
    int index = 0;          // Index to keep track of the position
    while (temp != nullptr) // Traverse the list
    { 
        if (temp->data == findEle) 
            return index; 
        
        temp = temp->next; // Move to the next node
        index++;           // Increment the index
    }
    
    return -1; // Return -1 if the element is not found
}

void printList(Node* head) 
{
    Node* temp = head; // Temporary pointer to traverse the list

    while (temp != nullptr)          // Traverse the list
    {       
        cout << temp -> data << " "; // Print the data of each node
        temp = temp -> next;         // Move to the next node
    }
    cout << endl;
}

int main() {
    Node *head = nullptr; // Initialize the head of the list to nullptr

    insert(head, 10, 0);
    insert(head, 33, 1);
    insert(head, 27, 2);
    insert(head, 49, 3);

    cout << "Linked List: "; 
    printList(head);

    deleteNode(head, 27);
    cout << "After Deletion: "; 
    printList(head);

    int findEle = 49; // Element to search for

    if (search(head, findEle) != -1)
        cout << findEle << " is at: " << search(head, findEle) + 1 << endl;
    else
        cout << findEle << " Not Found" << endl;
    
    return 0;
}
