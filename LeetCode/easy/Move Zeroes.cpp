//https://leetcode-cn.com/problems/move-zeroes/submissions/



/*

i is the last element which next to zero
j is the loop index.

*/


class Solution 
{
public:
    void moveZeroes(vector<int>& a) 
    {
            int i = -1;
    int j = 0;
    
    for(int j = 0; j<a.size(); ++j)
    {
        if(0 != a[j])
        {
            ++i;
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    for(int i = 0; i< a.size(); ++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    }
};