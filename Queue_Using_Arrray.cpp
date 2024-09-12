/*
Queue
Linear DS | FIFO
Enqueue() -> Add to end, Dequeue() -> Remove from end and return first element
Peek() -> Returns first element

Best Case: Ω (1)
Avg Case:  θ (1)
Worst Case: O (1)
Space: O (n)

*/
#include <iostream>
using namespace std;

struct Queue
{
    int front, rear, capacity;
    int *queue;

    Queue(int c)    //Constructor
    {
        front = 0, rear = -1, capacity = c, queue = new int[c];
    }

    ~Queue()        //Destructor
    {
        delete[] queue;
    }

    void queueEnqueue(int data)
    {
        if( rear == capacity - 1 )
        {
            cout << "\nQueue is FULL!";
            return;
        }
        
        queue[++rear] = data;   //Insert at rear
    }

    void queueDequeue()
    {
        if( front > rear )
        {
            cout << "\nQueue is EMPTY!";
            return;
        }

        for( int i=0; i<rear; i++ ) //Shift all elements from index 1 till rear to the left by one
        {
            queue[i] = queue[i+1];
        }

        rear--;     //Decrement rear
    }

    void queueDisplay()     //Display all elements
    {
        if( front > rear )
        {
            cout << "\nQueue is EMPTY!";
            return;
        }

        for( int i= front; i <= rear; i++ )
        {
            printf(" %d <-- ", queue[i]);
        }
        cout << "\n";
    }

    void queueFront()   //Display Front element
    {
        if( rear == -1 )
        {
            cout << "\nQueue is EMPTY";
            return;
        }
        cout << "\nFront Element is: " << queue[front];
    }
};

int main()
{
    Queue q(5);

    cout << "\nAll emements are: "; q.queueDisplay();

    q.queueEnqueue(20);
    q.queueEnqueue(50);
    q.queueEnqueue(20);
    q.queueEnqueue(90);
    q.queueEnqueue(10);

    cout << "\nAll emements are: "; q.queueDisplay();

    q.queueEnqueue(77);

    cout << "\nAll emements are: "; q.queueDisplay();

    q.queueDequeue();
    q.queueDequeue();

    cout << "\nAfter two node deletion: ";
    cout << "\nAll emements are: "; q.queueDisplay();

    q.queueEnqueue(55);
    cout << "\nAfter one node insertion: ";
    cout << "\nAll emements are: "; q.queueDisplay();

    q.queueFront();

    return 0;
}