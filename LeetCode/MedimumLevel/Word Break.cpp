/*
https://leetcode-cn.com/problems/word-break/
Word Break
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
determine if s can be segmented into a space-separated sequence of one or more dictionary words.
Note:
The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:
Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

*/


#include<iostream>
#include<string>
#include<vector>
using namespace std;


/*

DP[i] = DP[k] + DP[k+1,j]
DP[m,n] whether the s[m,n] in the dictinoary
use Trie tree as dictinoary.

*/


class Trie 
{
    struct  Node
    {
        char  szLetter[26];
        Node* szNext[26];
        bool  szEnd[26];

        Node()
        {
            for(int i = 0; i<26; ++i)
            {
                szLetter[i] = 0;
                szNext[i]   = nullptr;
                szEnd[i]    = false;
            }
        }
    };

public:
    /** Initialize your data structure here. */
    Trie() 
    {
        m_root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(const string& word) 
    {
        int   N = word.length();
        int   i = 0;
        Node* p = m_root;

        while(i< N)
        {
            int index = word[i]-'a';
            p->szLetter[index] = 1;
            if(i+1 == N)
            {
                p->szEnd[index] = true;
                break;
            }
            if(nullptr == p->szNext[index])
            {
                p->szNext[index] = new Node();       
            }
            p = p->szNext[index];
            ++i;       
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(const string& word) 
    {
        int N = word.length();
        int i = 0;
        bool bExist = true;
        Node* p = m_root;

        while(i<N)
        {
            int index = word[i]-'a';
            if( 0 == p->szLetter[index])
            {
                bExist = false;
                break;
            }
            if( i+1 == N)
            {
                if(!p->szEnd[index])
                {
                    bExist = false;
                }
                break;
            }
            p = p->szNext[index];
            if(nullptr == p)
            {
                bExist = false;
                break;
            }
            ++i;
        }
        return bExist;    
    }

    bool search(const char* word, int N) 
    {
        int i = 0;
        bool bExist = true;
        Node* p = m_root;

        while(i<N)
        {
            int index = word[i]-'a';
            if( 0 == p->szLetter[index])
            {
                bExist = false;
                break;
            }
            if( i+1 == N)
            {
                if(!p->szEnd[index])
                {
                    bExist = false;
                }
                break;
            }
            p = p->szNext[index];
            if(nullptr == p)
            {
                bExist = false;
                break;
            }
            ++i;
        }
        return bExist;    
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string& prefix) 
    {
        int N = prefix.length();
        int i = 0;
        bool bExist = true;
        Node* p = m_root;

        while(i<N)
        {
            int index = prefix[i]-'a';
            if( 0 == p->szLetter[index])
            {
                bExist = false;
                break;
            }
            if( i+1 == N)
            {
                break;
            }
            p = p->szNext[index];
            if(nullptr == p)
            {
                bExist = false;
                break;
            }
            ++i;
        }
        return bExist;   
    }

private:
   Node* m_root{nullptr};
};


class Solution 
{
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        int N = s.length();
        vector<bool>  vFlag(N+2, false);
        char* szText = new char[N+2];
        //strcpy_s(szText,N+1,s.c_str());
        strcpy(szText+1,s.c_str());
        
        vFlag[0] = true;
        BuildDictinoary(wordDict);

        for(int i = 1; i<=N; ++i )
        {
            for(int j = 0; j<i; ++j)
            {
                if(vFlag[j]) //Find a position which is the next start matching point
                {
                    char c = szText[i+1];
                    szText[i+1] = '\0';
                    if(SearchWord(szText+j+1, i-j))
                    {
                        vFlag[i] = true;
                        szText[i+1] = c;
                        break;
                    }
                     szText[i+1] = c;
                }
            }
        }
        return vFlag[N];
    }
private:
    void BuildDictinoary(vector<string>& wordDict)
    {
        m_pDict = new Trie();
        for(auto s: wordDict)
        {
            m_pDict->insert(s);
        }
    }

    bool SearchWord(const char* szWord, int Len)
    {
        bool bExist = true;

        bExist = m_pDict->search(szWord,Len);

        return bExist;
    }

private:
    Trie* m_pDict{nullptr};
};