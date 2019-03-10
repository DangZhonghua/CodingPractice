
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include <iostream>
using namespace std;

class Solution
{

public:
	int longestSubstring(string s, int k)
	{
		unordered_map<char, int> mapChar2Count;
		unordered_map<char, int>  mapChar2Pos;
		vector<bool> setCharLessK(256, false);
		for (auto c : s)
		{
			mapChar2Count[c] += 1;
		}
		for (auto it = mapChar2Count.begin(); it != mapChar2Count.end(); ++it)
		{
			if (it->second < k)
			{
				setCharLessK[it->first] = true;
			}
		}
		mapChar2Count.clear();
		int i = 0;
		int b = -1;
		int maxl = 0;

		while (i < s.length())
		{
			if (setCharLessK[s[i]] )
			{
				int largestPos = b;
				for (auto it = mapChar2Count.begin(); it != mapChar2Count.end(); ++it)
				{
					if (it->second < k && largestPos<mapChar2Pos[it->first])
					{
						largestPos = mapChar2Pos[it->first];
					}
				}
				if (maxl < (i - largestPos-1) && k<= (i - largestPos - 1))
				{
					maxl = (i - largestPos-1);
				}
				mapChar2Count.clear();
				mapChar2Pos.clear();
				b = i + 1; //update the window start point
			}
			else
			{
				mapChar2Count[s[i]] += 1;
				mapChar2Pos[s[i]] = i;
			}
			++i;
		}

		if (!mapChar2Count.empty())
		{
			int largestPos = b;
			for (auto it = mapChar2Count.begin(); it != mapChar2Count.end(); ++it)
			{
				if (it->second < k && largestPos < mapChar2Pos[it->first])
				{
					largestPos = mapChar2Pos[it->first];
				}
			}
			if (maxl < (i - largestPos - 1) && k<=(i - largestPos - 1))
			{
				maxl = (i - largestPos - 1);
			}
		}



		return maxl;
	}
};
