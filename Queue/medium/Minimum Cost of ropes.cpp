/*

Minimum Cost of ropes
https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes/0/?ref=self

There are given n ropes of different lengths, we need to connect these ropes into one rope. 
The cost to connect two ropes is equal to sum of their lengths. We need to connect the ropes with minimum cost.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N,N is the number of ropes.
The second line of each test case contains N input L[i],length of ropes.

Output:

Print the minimum cost.

Constraints:

1 ≤ T ≤ 200
1 ≤ N ≤ 500
1 ≤ L[i] ≤ 500

Example:

Input:
1
4
4 3 2 6

Output:
29

Explanation:

For example if we are given 4 ropes of lengths 4, 3, 2 and 6. We can connect the ropes in following ways.
1) First connect ropes of lengths 2 and 3. Now we have three ropes of lengths 4, 6 and 5.
2) Now connect ropes of lengths 4 and 5. Now we have two ropes of lengths 6 and 9.
3) Finally connect the two ropes and all ropes have connected.

Total cost for connecting all ropes is 5 + 9 + 15 = 29. This is the optimized cost for connecting ropes. 
Other ways of connecting ropes would always have same or more cost. For example, 
if we connect 4 and 6 first (we get three strings of 3, 2 and 10), then connect 10 and 3 (we get two strings of 13 and 2). 
Finally we connect 13 and 2. Total cost in this way is 10 + 13 + 15 = 38.

*/

/*

This is Geedy algorithm: use min-heap to store the rops, add them, remove them, add the sum into the min-heap.
min-heap is priority queue.

*/


#include<iostream>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;


int MinimumCostOfRops(int*a, int N)
{
    int mincost = 0;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    
    for(int i = 0; i<N; ++i)
    {
        minHeap.push(a[i]);
    }
    
    while(minHeap.size()>=2)
    {
        int a = minHeap.top();
        minHeap.pop();
        int b = minHeap.top();
        minHeap.pop();
        mincost += (a+b);
        minHeap.push((a+b));
    }

    cout<<mincost<<endl;
    
    return 0;
}


int main()
{
    int t = 0;
    int N = 0;
    int a[1000];
    
    cin>>t;
    
    while(t--)
    {
        cin>>N;
        int i = 0;
        while(i<N)
        {
            cin>>a[i++];
        }
        MinimumCostOfRops(a,N);
    }

}
