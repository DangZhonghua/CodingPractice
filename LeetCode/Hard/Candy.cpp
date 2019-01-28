/*
Candy
https://leetcode-cn.com/problems/candy/
There are N children standing in a line. Each child is assigned a rating value.
You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give?
Example 1:
Input: [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:
Input: [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
			 The third child gets 1 candy because it satisfies the above two conditions.

*/

#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings)
	{
		vector<int> vsrat;
		vsrat = ratings;
		std::sort(vsrat.begin(),vsrat.end());

		int minr = 	ratings[0];
		int maxr = *(vsrat.rbegin());

		vector<int> vc(ratings.size(), 0);
        
		for(int i = 0; i<vsrat.size(); ++i)
		{
			for(int j = 0; j<ratings.size(); ++j)
			{
				if(vsrat[i] == ratings[j])
				{
					vc[j] = 1;
					if( j-1>=0 && ratings[j]> ratings[j-1] && vc[j]< (vc[j-1]+1))
					{
						vc[j] = vc[j-1]+1;
					}
					if(j+1<ratings.size() && ratings[j]>ratings[j+1] && vc[j]< (vc[j+1]+1) )
					{
						vc[j] = vc[j+1]+1;
					}
				}
			}
		}
		
		int miniCandy = 0;
		for( auto c: vc)
		{
			miniCandy += c;
		}
		return miniCandy;

	}
};


int main()
{
	vector<int> a{ 1,0,2 };
	Solution sol;
	sol.candy(a);

	return 0;
}