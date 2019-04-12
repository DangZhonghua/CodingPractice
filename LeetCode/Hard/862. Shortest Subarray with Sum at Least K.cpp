
/*
https://leetcode-cn.com/problems/shortest-subarray-with-sum-at-least-k/
Shortest Subarray with Sum at Least K


Return the length of the shortest, non-empty, contiguous subarray of A with sum at least K.
If there is no non-empty subarray with sum at least K, return -1.


Example 1:
Input: A = [1], K = 1
Output: 1
Example 2:
Input: A = [1,2], K = 4
Output: -1
Example 3:
Input: A = [2,-1,2], K = 3
Output: 3

Note:
1 <= A.length <= 50000
-10 ^ 5 <= A[i] <= 10 ^ 5
1 <= K <= 10 ^ 9

*/

/*

https://leetcode.com/articles/shortest-subarray-with-sum-atleast-k/#

Approach 1: Sliding Window

Intuition

We can rephrase this as a problem about the prefix sums of A. Let P[i] = A[0] + A[1] + ... + A[i-1]. 
We want the smallest y-x such that y > x and P[y] - P[x] >= K.

Motivated by that equation, let opt(y) be the largest x such that P[x] <= P[y] - K. We need two key observations:

    If x1 < x2 and P[x2] <= P[x1], then opt(y) can never be x1, as if P[x1] <= P[y] - K, then P[x2] <= P[x1] <= P[y] - K but y - x2 is smaller. 
    This implies that our candidates x for opt(y) will have increasing values of P[x].
    
    p[x] is increasing along with the x increasing.

    If opt(y1) = x, then we do not need to consider this x again. For if we find some y2 > y1 with opt(y2) = x, 
    then it represents an answer of y2 - x which is worse (larger) than y1 - x.

Algorithm

Maintain a "monoqueue" of indices of P: a deque of indices x_0, x_1, ... such that P[x_0], P[x_1], ... is increasing.

When adding a new index y, we'll pop x_i from the end of the deque so that P[x_0], P[x_1], ..., P[y] will be increasing.

If P[y] >= P[x_0] + K, then (as previously described), we don't need to consider this x_0 again, and we can pop it from the front of the deque.



class Solution {
    public int shortestSubarray(int[] A, int K) {
        int N = A.length;
        long[] P = new long[N+1];
        for (int i = 0; i < N; ++i)
            P[i+1] = P[i] + (long) A[i];

        // Want smallest y-x with P[y] - P[x] >= K
        int ans = N+1; // N+1 is impossible
        Deque<Integer> monoq = new LinkedList(); //opt(y) candidates, as indices of P

        for (int y = 0; y < P.length; ++y) {
            // Want opt(y) = largest x with P[x] <= P[y] - K;
            while (!monoq.isEmpty() && P[y] <= P[monoq.getLast()])
                monoq.removeLast();
            while (!monoq.isEmpty() && P[y] >= P[monoq.getFirst()] + K)
                ans = Math.min(ans, y - monoq.removeFirst());

            monoq.addLast(y);
        }

        return ans < N+1 ? ans : -1;
    }
}

*/


#include<vector>
#include<deque>
#include<map>
#include<iostream>
using namespace std;


class Solution
{
public:
	int shortestSubarray(vector<int>& A, int K)
	{
        int ans = 0;
        if(0)
        {
            ans = SearchShortestSubarray(A,K);
        }
        else
        {
            ans = LinearShortestSubarray(A,K);
        }
        
        return ans;
	}

private:
    int SearchShortestSubarray(vector<int>& A, int K)
    {
        map<int, int> mapSum2Index;
		int sum = 0;
		int minLen = A.size() + 1;
		for (int i = 0; i < A.size(); ++i)
		{
			sum += A[i];
			if (sum >= K)
			{
				if (minLen > (i + 1))
				{
					minLen = i + 1;
				}
                // int d = sum-K;
                // map<int,int>::iterator it = mapSum2Index.lower_bound(d);

                // if(mapSum2Index.end() != it )
                // {
                    
                // }
			}
			//else
			{
				map<int,int>::iterator it = mapSum2Index.lower_bound(sum - K);
				if (mapSum2Index.end() != it)
				{
					if (it->first != (sum - K))
					{
                         //cout<<(sum-K)<<" "<<it->first<<" "<<i<<endl;
                        if( it != mapSum2Index.begin())
                        {
                            --it;
                        }
                        else
                        {
                            it = mapSum2Index.end();
                        }
						
					}
					if (it != mapSum2Index.end() && minLen > (i - it->second))
					{
						minLen = i - it->second;
                       // cout<<(sum-K)<<" "<<it->first<<" "<<i<<endl;
					}
				}
			}
			mapSum2Index[sum] = i;
		}
		return minLen = (minLen ==(A.size() + 1)?-1:minLen );
    }


private:
    int LinearShortestSubarray(vector<int>& A, int K)
    {
        int ans = 0;
        int N = A.size();
        vector<long long> presum(N+1, 0);

        ans = N+1;
        for(int i = 0; i<N; ++i)
        {
            presum[i+1] = presum[i] + A[i];
        }
        
        deque<int> monoque; //queue is used to store the index but make the presum@index is increasing.
        
        for(int i = 0; i<=N; ++i)
        {
            while(!monoque.empty() && presum[i] < monoque.back())
        }

        
    }
};
