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
		unordered_set<int> dict;

		int maxr = ratings[0];
		int minr = ratings[0];
		for (int i = 0; i < ratings.size(); ++i)
		{
			if (maxr < ratings[i])
			{
				maxr = ratings[i];
			}
			if (minr > ratings[i])
			{
				minr = ratings[i];
			}
			dict.insert(ratings[i]);
		}

		vector<int> vc(ratings.size(), 0);
        

		return 0;

	}
};


int main()
{
	vector<int> a{ 1,0,2 };
	Solution sol;
	sol.candy(a);

	return 0;
}