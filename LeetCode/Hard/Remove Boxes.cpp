/*
https://leetcode-cn.com/problems/remove-boxes/
https://leetcode.com/problems/remove-boxes/discuss/101310/java-top-down-and-bottom-up-dp-solutions
546. Remove Boxes
Given several boxes with different colors represented by different positive numbers.
You may experience several rounds to remove boxes until there is no box left. 
Each time you can choose some continuous boxes with the same color (composed of k boxes, k >= 1), 
remove them and get k*k points.
Find the maximum points you can get.

Example 1:
Input:

[1, 3, 2, 2, 2, 3, 4, 3, 1]

Output:

23

Explanation:

[1, 3, 2, 2, 2, 3, 4, 3, 1] 
----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
----> [1, 3, 3, 3, 1] (1*1=1 points) 
----> [1, 1] (3*3=9 points) 
----> [] (2*2=4 points)

Note: The number of boxes n would not exceed 100.

*/


#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


class Solution 
{
public:
    int removeBoxes(vector<int>& boxes) 
    {
        int N = boxes.size();
        if(0 == N)
        {
            return 0;
        }

        vector< vector< vector<int> > > dp(N,vector< vector<int> >(N, vector<int>(N,0)));
        
        for(int i = 0; i<N; ++i )
        {
            for(int k = 0; k<=i; ++k)
            {
                dp[i][i][k] = (k+1)*(k+1); //for the window length = 1 case
            }
        }
        //range[i,j]
        for(int L = 2; L<=N; ++L)
        {
            for(int i = 0; i+L<=N; ++i )
            {
                int j = i+L-1;
                //Now we have range[i,j] with length = L
                //Find the suitable k, since we DO NOT know which one, we try every possible
                for(int k = 0; k<=i; ++k)
                {
                    int maxp = (k+1)*(k+1)+ dp[i+1][j][0];
                    
                    for(int m = i+1; m<=j; ++m)
                    {
                        if(boxes[m] == boxes[i])
                        {
                            maxp = max(maxp, dp[i+1][m-1][0] + dp[m][j][k+1]);
                        }               
                    }
                    dp[i][j][k] = maxp;
                }
            }
        }
    return dp[0][N-1][0];

    }
};
// public int removeBoxes(int[] boxes) {
//     int n = boxes.length;
//     int[][][] dp = new int[n][n][n];
    	
//     for (int j = 0; j < n; j++) {
//     	for (int k = 0; k <= j; k++) {
//     	    dp[j][j][k] = (k + 1) * (k + 1);
//     	}
//     }
    	
//     for (int l = 1; l < n; l++) {
//     	for (int j = l; j < n; j++) {
//     	    int i = j - l;
    	        
//     	    for (int k = 0; k <= i; k++) {
//     	        int res = (k + 1) * (k + 1) + dp[i + 1][j][0];
    	            
//     	        for (int m = i + 1; m <= j; m++) {
//     	            if (boxes[m] == boxes[i]) {
//     	                res = Math.max(res, dp[i + 1][m - 1][0] + dp[m][j][k + 1]);
//     	            }
//     	        }
    	            
//     	        dp[i][j][k] = res;
//     	    }
//     	}
//     }
    
//     return (n == 0 ? 0 : dp[0][n - 1][0]);
// }