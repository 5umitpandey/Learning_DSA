/*
Stack
Push()
Pop()
Peak()
IsEmpty()
IsFull()
size()
*/

#include <iostream>
#include <stack>
using namespace std;

void PrintStack(std::stack<int>& s) 
{
    if (s.empty()) {
        return;
    }
    int x = s.top();

    s.pop();

    PrintStack(s);
    cout << x << " ";

    s.push(x);
}
int main()
{
    stack<int> s;

    //Pushing elements in the top
    for(int i=0; i<5; i++)
    {
        s.push(i+1);
        //cout << "Pushed: " << i+1;
    }

    //Printing elements (print the topmost element)
    cout << "\nElements are: ";
    PrintStack(s);

    //Popping elements (Removes the topmost element)
    while( !s.empty() )
    {
        s.pop();
    }
    
    if( s.empty() )
        cout << "\nStack is Empty";

    //Pushing elements in the top AGAIN (after popping all)
    for(int i=5; i<10; i++)
    {
        s.push(i+1);
    }

    //Printing elements (print the topmost element)
    cout << "\nElements are: ";
    PrintStack(s);

    cout << "\nTop Most Element is: " << s.top();

    cout << "\nSize of element is: " << s.size();
}