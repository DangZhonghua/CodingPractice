/*
https://leetcode-cn.com/problems/text-justification/
68. Text Justification

Given an array of words and a width maxWidth, format the text such that
each line has exactly maxWidth characters and is fully (left and right) justified.
You should pack your words in a greedy approach; that is, pack as many words as you can in each line.
Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
Extra spaces between words should be distributed as evenly as possible.
If the number of spaces on a line do not divide evenly between words,
the empty slots on the left will be assigned more spaces than the slots on the right.
For the last line of text, it should be left justified and no extra space is inserted between words.
Note:
A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
Example 1:
Input:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:
Input:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be",
			 because the last line must be left-justified instead of fully-justified.
			 Note that the second line is also left-justified becase it contains only one word.
Example 3:
Input:
words = ["Science","is","what","we","understand","well","enough","to","explain",
		 "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
*/

/*

suffix is the subproblem.
The relationship between subproblems:

DP[i] = min{ DP[j] + cost[i,j] }  for j = i+1...

*/

#include <vector>
#include <string>
#include <climits>
#include <iostream>
using namespace std;

class Solution
{
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth)
	{
		int N = words.size();
		vector<int> vWordsLen(N + 1, 0);
		vector<int> dp(N, INT_MAX);
		vector<int> vline(N, -1);
		vector<string> vset;

		vWordsLen[1] = words[0].length();

		for (int i = 2; i <= words.size(); ++i)
		{
			vWordsLen[i] = vWordsLen[i - 1] + words[i - 1].length();
		}

		//dp[N - 1] = 0;
		for (int i = N - 2; i >= 0; --i)
		{
			for (int j = i + 1; j < N; ++j) // word[i,j-1] will be putted into the same line.
			{
				int cost = CalcCost(vWordsLen, i, j, maxWidth);
				if (INT_MAX == cost) // this line has been fullfilled.
				{
					break;
				}
				if (INT_MAX == dp[i])
				{
					dp[i] = cost;
					vline[i] = j;
				}
				else
				{
					if (dp[i] < dp[j] + cost)
					{
						dp[i] = dp[j] + cost;
						vline[i] = j;
					}
				}

			}
		}
		//dp[0] is the minimum value
		//Now, the next starting word has been in vline. Lets construct the lines.
		int start = 0;
		while (-1 != start)
		{
			int end = vline[start];
			if (-1 == vline[start])
			{
				end = N;
			}
			string strline;
			int nSpace = (maxWidth - (vWordsLen[end] - vWordsLen[start]));


			start = vline[start];
		}

		return vset;
	}

private:
	int CalcCost(vector<int> & vWordsLen, int s, int e, int maxWidth)
	{
		int cost = INT_MAX;
		int nWordLen = 0;
		nWordLen = (vWordsLen[e] - vWordsLen[s]);
		nWordLen += (e - s);

		if (nWordLen <= maxWidth)
		{
			cost = maxWidth - nWordLen;
			cost *= cost;
			cost *= cost;
		}

		return cost;
	}
};


int main()
{
	int maxWidth = 16;
	Solution sol;
	vector<string> words{ "This", "is", "an", "example", "of", "text", "justification." };
	
	sol.fullJustify(words, maxWidth);
	

	return 0;
}