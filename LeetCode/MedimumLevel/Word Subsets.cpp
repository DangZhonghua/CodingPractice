/*
https://leetcode-cn.com/problems/word-subsets/
Word Subsets

We are given two arrays A and B of words.  Each word is a string of lowercase letters.

Now, say that word b is a subset of word a if every letter in b occurs in a, including multiplicity.
For example, "wrr" is a subset of "warrior", but is not a subset of "world".

Now say a word a from A is universal if for every b in B, b is a subset of a. 

Return a list of all universal words in A.  You can return the words in any order.

 

Example 1:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","o"]
Output: ["facebook","google","leetcode"]
Example 2:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["l","e"]
Output: ["apple","google","leetcode"]
Example 3:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","oo"]
Output: ["facebook","google"]
Example 4:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["lo","eo"]
Output: ["google","leetcode"]
Example 5:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["ec","oc","ceo"]
Output: ["facebook","leetcode"]
 

Note:

1 <= A.length, B.length <= 10000
1 <= A[i].length, B[i].length <= 10
A[i] and B[i] consist only of lowercase letters.
All words in A[i] are unique: there isn't i != j with A[i] == A[j].

*/


#include<unordered_map>
#include<vector>
#include<iostream>
using namespace std;

class Solution
{
public:
	vector<string> wordSubsets(vector<string>& A, vector<string>& B)
	{
		vector<string> vr;
		//build super set for B
		unordered_map<char, int> bSuperSetMap;
		for (int i = 0; i < B.size(); ++i)
		{
			unordered_map<char, int> bSetMap;
			for (int j = 0; j < B[i].size(); ++j)
			{
				bSetMap[B[i][j]] += 1;
			}
			for (auto it = bSetMap.begin(); it != bSetMap.end(); ++it)
			{
				if (bSuperSetMap[it->first] < it->second)
				{
					bSuperSetMap[it->first] = it->second;
				}
			}
		}


		for (int i = 0; i < A.size(); ++i)
		{
			unordered_map<char, int> mapcount;
			for (int j = 0; j < A[i].size(); ++j)
			{
				mapcount[A[i][j]] += 1;
			}
			bool bSubset = true;
			for (auto it = bSuperSetMap.begin(); it != bSuperSetMap.end(); ++it)
			{
				if (mapcount[it->first] < it->second)
				{
					bSubset = false;
					break;
				}
			}
			if (bSubset)
			{
				vr.push_back(A[i]);
			}
		}

		return vr;
	}
};

int main()
{
	vector<string> a{ "amazon", "apple", "facebook", "google", "leetcode" };
	vector<string> b{ "e", "o" };
	
	Solution sol;
	sol.wordSubsets(a, b);
	
	return 0;
}