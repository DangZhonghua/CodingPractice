class Solution 
{
public:
    int peakIndexInMountainArray(vector<int>& A) 
    {
        int i = 0;
        for(i = 1; i<A.size()-1; ++i)
        {
            if(A[i-1]<A[i] && A[i]>A[i+1])
            {
                break;
            }
        }
        return i;
    }
};