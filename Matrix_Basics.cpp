/*
Matrix Creation
Matrix Multiplication
Matrix Transpose
*/

#include <iostream>
using namespace std;

void Matrix_Multiplication(int arr1[][3], int arr2[][3], int m, int n, int x, int y, int m_arr[][3])
{   
    for( int i=0; i<m; i++ )
    {
        for(int j=0; j<n; j++ )
        {   
            m_arr[i][j] = 0;
            for(int k=0; k<n; k++ ) //Loop through elements for dot product
            {
                m_arr[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

void Matrix_Transpose(int arr[][3], int m, int n, int t_arr[][3])
{
    for( int i=0; i<m; i++ )
    {
        for(int j=0; j<n; j++ )
        {   
            t_arr[j][i] = arr[i][j];
        }
    }
}

void PrintArray(int arr[][3], int m, int n )
{
    for( int i=0; i<m; i++ )
    {
        for(int j=0; j<n; j++ )
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{   
    int m = 3, n = 3;
    int x = 3, y = 3;
    int arr1[3][3] = {
                        {1, 2, 3},
                        {1, 2, 3},
                        {1, 2, 3}
                    };
    int arr2[3][3] = {
                        {1, 1, 1},
                        {2, 2, 2},
                        {1, 1, 1}
                    };

    cout << "Matrix 1 is: \n"; PrintArray(arr1, m , n);
    cout << "Matrix 2 is: \n"; PrintArray(arr2, x , y);

    //Multiplied Matrix
    int m_arr[3][3];

    cout << "Multiplied Matrix is: \n";
    Matrix_Multiplication(arr1, arr2, m, n, x, y, m_arr);
    PrintArray(m_arr, m, n);

    int arr3[3][3] = {
                        {1, 2, 3},
                        {5, 4, 6},
                        {0, 8, 9}
                    };
    //Transposed Matrix
    int t_arr[3][3];
    cout << "Transposed Matrix is: \n";
    Matrix_Transpose(arr3, m, n, t_arr);
    PrintArray(t_arr, m, n);

return 0;
    
}