/*
Find all pairs with a given sum 
https://practice.geeksforgeeks.org/problems/find-all-pairs-whose-sum-is-x/0
Given two unsorted arrays A[] of size n and B[] of size m of distinct elements, 
the task is to find all pairs from both arrays whose sum is equal to x.

Examples:

Input :  A[] = {-1, -2, 4, -6, 5, 7}
         B[] = {6, 3, 4, 0}  
         x = 8
Output : 4 4, 5 3

Input : A[] = {1, 2, 4, 5, 7} 
        B[] = {5, 6, 3, 4, 8}  
        x = 9
Output : 1 8, 4 5, 5 4


Input:
The first line of input contains an integer T denoting the no of test cases. 
Then T test cases follow. Each test case contains 3 lines . 
The first line contains 3 space separated integers n, m, x. Then in the next two lines are space separated values of the array A and B respectively.

Output:
For each test case in a new line print the sorted space separated values of all the pairs u,v 
where u belongs to array A and v belongs to array B, 
such that each pair is separated from the other by a ',' 
without quotes also add a space after the ',' . If no such pair exist print -1.

Constraints:
1<=T<=100
1<= n, m, x=1000
-1000<= A[], B[]<=1000

Example:
Input:
2
5 5 9
1 2 4 5 7
5 6 3 4 8
2 2 3
0 2
1 3
Output:
1 8, 4 5, 5 4
0 3, 2 1

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findAllPairsOfSum(int *a, int *b, int N, int M, int x)
{
        std::sort(a, a + N);
        std::sort(b, b + M);
        vector<pair<int, int>> sumpairs;

        int i = 0;
        int j = M - 1;

        while (i < N && j >= 0)
        {
                if ( (a[i] + b[j]) == x)
                {
                  sumpairs.push_back(pair<int,int>(a[i],b[j]));
                  //Since distinct elements, we move all pointer.
                  ++i;
                  --j;      
                }
                else if( (a[i] + b[j]) > x)
                {
                        --j;
                }
                else
                {
                        ++i;
                }
        }
        
        if(sumpairs.empty())
        {
                cout<<-1<<endl;
        }
        else
        {
                int i = 0;
                for(i = 0; i<sumpairs.size()-1; ++i)
                {
                        cout<<sumpairs[i].first<<" "<< sumpairs[i].second<<", ";
                }
                 cout<<sumpairs[i].first<<" "<< sumpairs[i].second<<endl;
        }

        return 0;
}

int main()
{
        int t = 0;
        int a[1001];
        int b[1001];
        int n, m, x;

        cin >> t;

        while (t > 0)
        {
                --t;
                cin >> n >> m >> x;
                int i = 0;
                while (i < n)
                {
                        cin >> a[i++];
                }
                i = 0;
                while (i < m)
                {
                        cin >> b[i++];
                }
                findAllPairsOfSum(a, b, n, m, x);
        }

        return 0;
}