/*

Print all possible paths from top left to bottom right of a mXn matrix
https://www.geeksforgeeks.org/print-all-possible-paths-from-top-left-to-bottom-right-of-a-mxn-matrix/

The problem is to print all the possible paths from top left to bottom right of a mXn matrix 
with the constraints that from each cell you can either move only to right or down.

Examples :

Input : 1 2 3
        4 5 6
Output : 1 4 5 6
         1 2 5 6
         1 2 3 6

Input : 1 2 
        3 4
Output : 1 2 4
         1 3 4

The algorithm is a simple recursive algorithm, 
from each cell first print all paths by going down 
and then print all paths by going right. Do this recursively for each cell encountered.

*/

#include<iostream>
#include<vector>
using namespace std;

void outputPath( vector<int>& path)
{
    for(auto v:path)
    {
        cout<<v<<" ";
    }
    cout<<endl;
}

void btFormPath(vector< vector<int> >& M, vector<int>& path,int R, int C, int r, int c )
{
    path.push_back(M[r][c]);
    
    if(R-1 == r && C-1 ==  c)
    {
        outputPath(path);
        path.pop_back();
        return;
    }

    //1: lets start down direction first
    if(r+1<R)
    {
        btFormPath(M,path,R,C,r+1,c);
    }
    
    //2: backtrack, then try right direction.

    if(c+1<C)
    {
        btFormPath(M,path,R,C,r,c+1);
    }


    path.pop_back();
}

int PrintAllPath( vector< vector<int> >& M)
{
    int ret = 0; 
    vector<int> path;
    int R = M.size();
    int C = M[0].size();
    
    btFormPath(M,path,R,C,0,0);

    return ret;
}

int main(int argc, char const *argv[])
{
    vector< vector<int> > m1{ {1, 2, 3},
                              {4, 5, 6}
                            };

    PrintAllPath(m1);
    return 0;
}
