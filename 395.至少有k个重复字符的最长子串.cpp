
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
		// unordered_set<char> setCharLessK;
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
		int b = 0;
		int maxl = 0;

		while (i < s.length())
		{
			if (setCharLessK[s[i]])
			{
				bool bFind = false;
				for (auto it = mapChar2Count.begin(); it != mapChar2Count.end(); ++it)
				{
					if (it->second < k)
					{
						bFind = true;
						break;
					}
				}
				if (!bFind && maxl < (i - b))
				{
					maxl = (i - b);
				}
				mapChar2Count.clear();
				b = i + 1; //update the window start point
			}
			else
			{
				mapChar2Count[s[i]] += 1;
			}
			++i;
		}

		if (!mapChar2Count.empty())
		{
			bool bFind = false;
			for (auto it = mapChar2Count.begin(); it != mapChar2Count.end(); ++it)
			{
				if (it->second < k)
				{
					bFind = true;
					break;
				}
			}

			if (!bFind && maxl < (s.length() - b))
			{
				maxl = (s.length() - b);
			}
		}

		return maxl;
	}
};

int main()
{
	Solution sol;
	string s1 = "aaabb";
	int k = 3;

	
	
	//cout << sol.longestSubstring(s1, k) << endl;

	string s2 = "bbaaacbd";

	cout << sol.longestSubstring(s2, k) << endl;
	
	return 0;
}