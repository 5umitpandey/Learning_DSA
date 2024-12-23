//https://www.geeksforgeeks.org/problems/print-1-to-n-without-using-loops-1587115620/1?page=1&difficulty=School,Basic&sortBy=submissions

void printNos(int n) 
    {
        // Your code here
        if( n > 0 )
        {
            printNos(n-1);
            cout << n << " ";
        }
        
    }
