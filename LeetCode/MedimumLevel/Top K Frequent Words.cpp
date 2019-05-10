/*
https://leetcode-cn.com/problems/top-k-frequent-words/
Top K Frequent Words

Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. 
If two words have the same frequency, 
then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<queue>
#include<stack>
using namespace std;

class Solution 
{
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string,int> wordfreq;
        for(string& word:words)
        {
            wordfreq[word] += 1;
        }
        
        auto comp = [&](const string& a,const string& b)->bool
        {
            if( wordfreq[a]>=wordfreq[b] )
            {
                if(wordfreq[a]>wordfreq[b])
                {
                    return true;
                }
                else
                {
                    if(a.compare(b)<0)
                    {
                        return true;
                    }
                }   
            }
            return false;
        };

        priority_queue<string, vector<string>, decltype(comp) > minHeap(comp);

        for(auto wf:wordfreq)
        {
            if(k == minHeap.size() )
            {
                if(wf.second>wordfreq[minHeap.top()] )
                {
                    minHeap.pop();
                    minHeap.push(wf.first);
                }
                else if( wf.second==wordfreq[minHeap.top()] && wf.first.compare(minHeap.top())<0 )
                {
                    minHeap.pop();
                    minHeap.push(wf.first);
                }
            }
            else
            {
                minHeap.push(wf.first);
            }
        }

        stack<string> ss;
        
        while( !minHeap.empty())
        {
            ss.push(minHeap.top());
            minHeap.pop();
        }
        vector<string> vr;
        
        while(!ss.empty())
        {
            vr.push_back(ss.top());
            ss.pop();
        }
        return vr;
    }
};