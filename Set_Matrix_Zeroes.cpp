//https://leetcode.com/problems/set-matrix-zeroes/

/*
    void MarkRow(vector<vector<int>> &matrix, int n, int m, int i)
    {
        for( int j = 0; j<m; j++ )
        {
            if( matrix[i][j] != 0 )
            {
                matrix[i][j] = INT_MIN + 1;
            }
        }
    }

    void MarkCol(vector<vector<int>> &matrix, int n, int m, int j)
    {
        for( int i = 0; i<n; i++ )
        {
            if( matrix[i][j] != 0 )
            {
                matrix[i][j] =  INT_MIN + 1;
            }
        }
    }

    //Approach 1 | Bruteforce
    void setZeroes(vector<vector<int>>& matrix) 
    {   
        int n = matrix.size();
        int m = matrix[0].size();

        for( int i=0; i<n; i++ )
        {
            for( int j=0; j<m; j++ )
            {
                if( matrix[i][j] == 0 )
                {
                    MarkRow(matrix, n, m, i);
                    MarkCol(matrix, n, m, j);
                }
            }
        }

        for( int i=0; i<n; i++ )
        {
            for( int j=0; j<m; j++ )
            {
                if( matrix[i][j] ==  INT_MIN + 1 )
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    */

    /*
    //Approach 2 | Bruteforce | Fixing for negative input
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> row(n, 0), col(m, 0);

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (matrix[i][j] == 0) 
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (row[i] || col[j]) 
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    */

    //Optimal Space Approach
    void setZeroes(vector<vector<int>>& matrix)
    {
        
    }
