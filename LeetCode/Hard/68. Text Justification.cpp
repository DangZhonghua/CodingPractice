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
		int N			= words.size();
		vector<int>		vWordsLen(N + 1, 0);
		vector<int>		dp(N + 1, INT_MAX);
		vector<int>		vline(N, -1);
		vector<string>	vset;

		vWordsLen[1] = words[0].length();
		for (int i = 1; i < words.size(); ++i)
		{
			vWordsLen[i+1] = vWordsLen[i] + words[i].length();
		}

		dp[N] = 0; 
		for (int i = N - 1; i >= 0; --i)
		{
			for (int j = i + 1; j <= N; ++j) // word[i,j-1] will be putted into the same line.
			{
				int cost = CalcCost(vWordsLen, i+1, j+1, N+1,maxWidth);
				if (INT_MAX == cost) // this line has been fullfilled.
				{
					break;
				}
				if (INT_MAX == dp[i])
				{
					dp[i] = cost;
					vline[i] = j;
				}
				else if (dp[i] >= dp[j] + cost)
				{			
					dp[i] = dp[j] + cost;
					vline[i] = j;	
				}
			}
		}
		//dp[0] is the minimum value
		//Now, the next starting word has been in vline. Lets construct the lines.
		int start = 0;
		while (N != start)
		{
			int end = vline[start];
			string strline;
			if (N == end || 1 == end - start) //the end
			{
				strline = words[start];
				if (strline.length() < maxWidth)
				strline += " ";
				for (int i = start + 1; i < end; ++i)
				{
					strline += words[i];
					if(strline.length() < maxWidth)
					strline += " ";
				}
				strline.append(maxWidth - strline.length(), ' ');
				vset.push_back(strline);
			}
			else
			{
				int nSpace = (maxWidth - (vWordsLen[end] - vWordsLen[start]));
				int nSpaceCount		= (end - start - 1);
				int nSpaceLen		= nSpace / nSpaceCount;
				int nSpaceLeft		= nSpace % nSpaceCount;

				strline += words[start];
				strline.append(nSpaceLen, ' ');
				if (nSpaceLeft)
				{
					strline.append(1, ' ');
					--nSpaceLeft;
				}
				
				for (int i = start + 1; i < end; ++i)
				{
					strline += words[i];
					if (i + 2 < end)
					{
						strline.append(nSpaceCount, ' ');
					}
					else if( i+2 ==end)
					{
						strline.append(nLastSpaceCount, ' ');
					}
				}
				vset.push_back(strline);
			}
			start = vline[start];
		}
		for (auto str : vset)
		{
			cout << str << endl;
		}
		return vset;
	}

private:
	int CalcCost(vector<int> & vWordsLen, int s, int e, int maxCount, int maxWidth)
	{
		int cost = INT_MAX;
		int nWordLen = 0;
		nWordLen = (vWordsLen[e-1] - vWordsLen[s-1]);
		nWordLen += (e - s-1);

		if (nWordLen <= maxWidth)
		{
			cost = maxWidth - nWordLen;
			cost = (cost *cost*cost);
			if (e == maxCount)
			{
				cost = 0;
			}
		}

		return cost;
	}
};

//["Science  is  what we", 
//"understand      well", 
//"enough to explain to", 
//"a  computer.  Art is", 
//"everything  else  we", 
//"do                  "]

int main()
{
	int maxWidth = 20;
	Solution sol;
	vector<string> words{"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};

	sol.fullJustify(words, maxWidth);

	vector<string> words1{ "This", "is", "an", "example", "of", "text", "justification." };
	maxWidth = 16;

	//sol.fullJustify(words1, maxWidth);


	//["The", "important", "thing", "is", "not", "to", "stop", "questioning.", "Curiosity", "has", "its", "own", "reason", "for", "existing."]
	//17

	return 0;
}


