/*

https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix/0
Largest square formed in a matrix 

Given a binary matrix, find out the maximum size square sub-matrix with all 1s.
Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is n and m,n is the number of rows and m is the number of columns.
The second line of each test case contains array C[n][m] in row major form.

Output:
Print maximum size square sub-matrix.

Constraints:
1 ≤ T ≤ 100
1 ≤ n,m ≤ 50
0 ≤ C[n][m] ≤ 1

Example:
Input:
3
5 6
0 1 0 1 0 1 1 0 1 0 1 0 0 1 1 1 1 0 0 0 1 1 1 0 1 1 1 1 1 1
2 2
1 1 1 1
2 2
0 0 0 0
Output:
3
2
0

*/


/*

Algorithm:
Let the given binary matrix be M[R][C]. The idea of the algorithm is to construct an auxiliary size matrix S[][] 
in which each entry S[i][j] represents size of the square sub-matrix with all 1s including M[i][j] 
where M[i][j] is the rightmost and bottommost entry in sub-matrix.

1) Construct a sum matrix S[R][C] for the given M[R][C].
     a)    Copy first row and first columns as it is from M[][] to S[][]
     b)    For other entries, use following expressions to construct S[][]
         If M[i][j] is 1 then
            S[i][j] = min(S[i][j-1], S[i-1][j], S[i-1][j-1]) + 1
         Else If M[i][j] is 0
            S[i][j] = 0
2) Find the maximum entry in S[R][C]
3) Using the value and coordinates of maximum entry in S[i], print 
   sub-matrix of M[][]
*/

#include<iostream>
using namespace std;

int m[50][50];
int s[50][50];


int largestSquareInMatrix(int R, int C);

int main()
 {
    int t = 0;
    int R = 0;
    int C = 0;
    
    cin>>t;
    
    while(t>0)
    {
        --t;
        cin>>R;
        cin>>C;
        
        for(int r = 0; r<R;++r)
        {
            for(int c = 0; c<C; ++c)
            {
                cin>>m[r][c];
            }
        }
        largestSquareInMatrix(R,C);
    }


	return 0;
}

int largestSquareInMatrix(int R, int C)
{
    int maxs = 0;
    
    for(int r = 0; r<R; ++r)
    {
        for(int c = 0; c<C; ++c)
        {
            if(m[r][c])
            {
                s[r][c] = 1;
                maxs = 1;
            }
            else
            {
                s[r][c] = 0;
            }
        }
    }
    
    for(int r = 1; r<R; ++r)
    {
        for(int c = 1; c<C; ++c)
        {
            if(m[r][c] && s[r-1][c-1])
            {
                int sr = 0;
                int sc = 0;
                
                while( sr< s[r-1][c-1] && m[r-1-sr][c])
                {
                    ++sr;
                }
                
                while(sc < s[r-1][c-1] && m[r][c-1-sc])
                {
                    ++sc;
                }
                int mins = sr>sc? sc:sr;
                if(s[r][c]<mins+1)
                {
                    s[r][c] = mins+1;
                }
                if(maxs<s[r][c])
                {
                    maxs = s[r][c];
                }
            }
        }
    }
    
    cout<<maxs<<endl;
    
    
    return 0;
}