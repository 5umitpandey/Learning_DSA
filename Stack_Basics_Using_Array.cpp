/*
Stack
Linear DS | LIFO | Last element = Top

Push() -> Add to end, Pop() -> Remove from end, Peak() -> Check end, IsEmpty(), IsFull()
Precedence(), Infix To Postfix()
Balance Parenthesis
Reverse the contents of Stack
Evaluation of Postfix Expr

Time Complexity: push: O(1), pop: O(1), peek: O(1), is_empty: O(1), is_full: O(1), Converting: O(n)
Auxiliary Space: O(n)
*/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX1 5
#define MAX2 50

//Basic Stack functions
class Stack
{
    int top, arr[MAX1];

    public:
        Stack()
        {
            top = -1;
        }

        bool IsFull()
        {
            return (top == MAX1 - 1);
        }

        bool IsEmpty()
        {
            return (top == -1);
        }

        void Push(int x)
        {
            if( IsFull() )
            {
                cout << "\nStack Overflow!";
                return;
            }
            arr[++top] = x;
        }

        int Pop()
        {
            if( IsEmpty() )
            {
                cout << "\nStack Underflow!";
                return -1;
            }
            return arr[top--];
        }

        int Peek()
        {
            if( IsEmpty() )
            {
                cout << "\nStack is Empty";
                return -1;
            }
            return arr[top];
        }
};

//Precedence Function
int Precedence(char op)
{
    if( op == '+' || op == '-' ) return 1;
    if( op == '*' || op == '/' ) return 2;

    return 0;
}

void InfixToPostfix(const char* infix, char* postfix)
{
    Stack s;
    int k = 0;

    for( int i=0; i < strlen(infix); i++)
    {
        char c = infix[i];

        if( isalnum(c) )    //char or number, direct push to postfix
            postfix[k++] = c;
        else if( c == '(' )
            s.Push(c);
        else if( c == ')' )
        {
            while( !s.IsEmpty() && s.Peek() != '(' )
                postfix[k++] = s.Pop();
            s.Pop();    //Pop the '('
        }
        else //If Operators (+-*/)
        {
            while( !s.IsEmpty() && Precedence(c) <= Precedence(s.Peek()))
                postfix[k++] = s.Pop();
            s.Push(c);
        }
    }

    while( !s.IsEmpty() )
    {
        postfix[k++] = s.Pop();
    }

    postfix[k] = '\0';
}

//Balance the string
bool IsMatchingPair(char c1, char c2) 
{
    return ((c1 == '(' && c2 == ')') ||
            (c1 == '{' && c2 == '}') ||
            (c1 == '[' && c2 == ']'));
}

bool AreParenthesesBalanced(const std::string& expr) 
{
    Stack s;
    for (char ch : expr) 
    {
        if (ch == '(' || ch == '{' || ch == '[') 
            s.Push(ch);
        else if (ch == ')' || ch == '}' || ch == ']') 
        {
            if (s.IsEmpty() || !IsMatchingPair(s.Pop(), ch)) 
                return false;
        }
    }
    return s.IsEmpty();
}

//Insert element at the bottom
void InsertAtBottom(Stack& s, int item) {
    if (s.IsEmpty()) {
        s.Push(item);
    } else {
        int top = s.Pop();
        InsertAtBottom(s, item);
        s.Push(top);
    }
}

// Function to reverse the stack
void ReverseStack(Stack& s) {
    if (s.IsEmpty()) return;

    int top = s.Pop();
    ReverseStack(s);
    InsertAtBottom(s, top);
}


// Function to print the stack
void PrintStack(Stack s) {
    while (!s.IsEmpty()) {
        cout << s.Pop() << " ";
    }
    cout << endl;
}

// Check if an expression is postfix
bool IsPostfix(const std::string& expr) {
    int operandCount = 0;
    for (char c : expr) {
        if (isdigit(c)) {
            operandCount++;
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (operandCount < 2) {
                return false;
            }
            operandCount--; // Two operands are replaced by one result
        } else if (!isspace(c)) {
            return false;
        }
    }
    return operandCount == 1;
}

//Evaluation of Postfix Expr
int EvaluatePostfix(const char* postfix) 
{
    Stack s;
    for (int i = 0; i < strlen(postfix); i++) 
    {
        char c = postfix[i];
        if(isdigit(c)) 
        {
            s.Push(c - '0');
        } 
        else 
        {
            int val1 = s.Pop();
            int val2 = s.Pop();
            switch (c) 
            {
                case '+': s.Push(val2 + val1); break;
                case '-': s.Push(val2 - val1); break;
                case '*': s.Push(val2 * val1); break;
                case '/': s.Push(val2 / val1); break;
            }
        }
    }
    return s.Pop();
}

int main()
{
    Stack s;

    //Pushing elements in the top
    for(int i=0; i<5; i++)
    {
        s.Push(i+1);
        cout << "Pushed: " << i+1 << "\n";
    }

    if( s.IsEmpty() )
    {
        cout << "\nStack is Empty";
    }
    if( s.IsFull() )
    {
        cout << "\nStack is Full";
    }

    const char* infix = "A+B*C-D/E";
    char postfix[MAX2];

    InfixToPostfix(infix, postfix);

    cout << "\n\nInfix Exp: " << infix << endl;
    cout << "Postfix Exp: " << postfix << endl;

    string expr = "{}[]()[]{}()";

    if( AreParenthesesBalanced(expr) )
        cout << "\n" << expr << " is Balanced";
    else
        cout << "\n" << expr << " is Not Balanced";

    // Reverse and print the stack
    cout << "\n\nOriginal Stack: ";
    PrintStack(s);

    ReverseStack(s);

    cout << "Reversed Stack: ";
    PrintStack(s);
    cout << endl;
    //Evaluation of Postfix expr
    //string PostfixExpr = "23*4+";
    string PostfixExpr = "5+1*5-1/1";
    
    //Check if expr is postfix or not, evaluate if yes
    if( IsPostfix(PostfixExpr) )
        cout << "\nEvaluation of " << PostfixExpr << " is: " << EvaluatePostfix(PostfixExpr.c_str()) << endl;
    else
    {
        cout << PostfixExpr << " is not a Postfix expr! \nConverting to Postfix...";
        InfixToPostfix(PostfixExpr.c_str(), postfix);
        if( IsPostfix(postfix) )
        {
            cout << "\nEvaluation of " << PostfixExpr << " is: " << EvaluatePostfix(postfix) << endl;
        }
    }

    return 0;
}