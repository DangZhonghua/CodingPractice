class Solution
{
public:
	int shortestSubarray(vector<int>& A, int K)
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
};
