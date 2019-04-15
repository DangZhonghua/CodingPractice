/*
https://leetcode-cn.com/problems/maximum-swap/
Maximum Swap

Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. 
Return the maximum valued number you could get. 
Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.

Example 2:
Input: 9973
Output: 9973
Explanation: No swap.

Note:
The given number is in the range [0, 10^8]


*/

#include<vector>
using namespace std;

class Solution 
{
public:
    int maximumSwap(int num) 
    {
        int i = 0;
        int N = num;

        while(N/10)
        {
            ++i;
            N /= 10;
        }
        ++i;
        vector<int> vd(i,0);
        
        N = num;
        
        int j = i-1;
        while(N/10)
        {
            vd[j] = (N%10);
            --j;
            N /=10;
        }

        vd[j] = (N%10);

        vector<int> vmax(vd.size(),0);
        vmax[i-1] = i-1;

        for(int j = i-2; j>=0; --j)
        {
            vmax[j] = j;
            if(vd[j]<= vd[ vmax[j+1] ] ) // pay attention here: use <= to make least siffignent bit to be exchanged.
            {
                vmax[j] = vmax[j+1];
            }
        }
        for(int j = 0; j<vd.size(); ++j)
        {
            if(vd[j]<vd[vmax[j]])
            {
                int t = vd[j];
                vd[j] = vd[vmax[j]];
                vd[vmax[j]] = t;
                break;
            }
        }

        int base = 1;
        int result = 0;
        
        for(int j = vd.size()-1; j>=0; --j)
        {
            result +=  base* vd[j];
            base *=10;
        }
        return result;
    }
};