/*
Modify array to maximize sum of adjacent differences 
https://practice.geeksforgeeks.org/problems/modify-array-to-maximize-sum-of-adjacent-differences/0
https://www.geeksforgeeks.org/modify-array-to-maximize-sum-of-adjacent-differences/

Given an array, we need to modify values of this array in such a way that sum of absolute differences 
between two consecutive elements is maximized. 
If the value of an array element is X, then we can change it to either 1 or X.


Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
The first line of each test case contains an integer N denoting the size of the array A.
The second line of each test case contains N space separated integers denoting elements of the array A[ ].


Output:
Print the maximum sum of adjacent differences after modifying the array for each test case in a new line.


Constraints:
1<= T <=100
1<= N <=100000
1<= A[ ] <=100000

Example:

Input:

1
5
3 2 1 4 5
Output:
8
Explanation:

Modified array: 3 1 1 4 1

ans = | 1 - 3 | + | 1 - 1 | + | 4 - 1 | + | 1 - 4 | = 8
*/

/*

vs[i][0] = max{  
                    vs[i-1][0] + |a[i]-a[i-1]|,
                    vs[i-1][1] + |a[i]-1|
                }

vs[i][1] = max {       
                    vs[i-1][0] + |1-a[i-1]|
                    vs[i-1][1] + |1-1|
            }

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int maximizeSum(vector<int>& a)
{
    vector< vector<int> > vs(a.size(), vector<int>(2,0));
    
    for(int i = 1; i<a.size(); ++i)
    {
        vs[i][0] = vs[i-1][0] + abs(a[i]-a[i-1]);
        if(vs[i][0] < vs[i-1][1] + abs(a[i]-1))
        {
            vs[i][0] = vs[i-1][1] + abs(a[i]-1);
        }
        
        vs[i][1] = vs[i-1][0] + abs(1-a[i-1]);
        if(vs[i][1]<vs[i-1][1])
        {
            vs[i][1] = vs[i-1][1];
        }
    }
    cout<<max(vs[a.size()-1][1], vs[a.size()-1][0])<<endl;

    return 0;
}

int main(int argc, char const *argv[])
{
    int t = 0;
    
    cin>>t;
    
    while(t--)
    {
        int N = 0;
        cin>>N;
        vector<int> a(N,0);
        int i = 0;
        while(i<N)
        {
            cin>>a[i];
            ++i;
        }
        maximizeSum(a);
    }
    return 0;
}
