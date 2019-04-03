/*
https://leetcode-cn.com/problems/word-break-ii/
Word Break II

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.
Note:
The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:
Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
Example 2:
Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:
Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]

*/

#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;


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
    struct range
    {
        int rs;
        int re;
    };
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        int N = s.length();
        vector< vector<int> >  dp(N+1, vector<int>(N+1,0));
        vector< int > vcount(N+1, 0);
        char* szText = new char[N+2];
        strcpy(szText+1,s.c_str());
        vector<string>   vs;
        string   strSent;

        vcount[0] = 1;
        dp[0][0]  = 0;

        BuildDictinoary(wordDict);

        for(int i = 1; i<=N; ++i)
        {
          for( int j = 0; j< i; ++j)
          {
            if( vcount[j] )
            {
                char c = szText[i+1];
                szText[i+1] = '\0';
                if(SearchWord(szText+j+1, i-j))
                {
                    dp[i][ vcount[i] ] = j;
                    vcount[i] += 1;
                }
                 szText[i+1] = c;
            }
          }
        }

        if(vcount[N])
        {
            vector<range> stackr;
          BuildSentence(dp,vcount,vs,stackr,szText,N);
        }
        return vs;
    }

private:

    void BuildSentence(vector< vector<int> >& dp,  vector< int >& vcount, 
                      vector<string>& vs,vector<range>& stackr ,char* szText, int s)
    {
        if(0 == s)
        {
            CreateSentence(vs,stackr,szText);
            return;
        }
        for( int i = 0; i<vcount[s]; ++i)
        {
          range seg;
          seg.rs = dp[s][i]+1;
          seg.re = s;
          stackr.push_back(seg);
          BuildSentence(dp,vcount,vs,stackr,szText,dp[s][i]);
          stackr.pop_back();
        }
    }
    void CreateSentence(vector<string>& vs,vector<range>& stackr,char* szText)
    {
        string strSentence;
        for(int i = stackr.size()-1; i>=0; --i)
        {
            char c = szText[stackr[i].re+1];
            szText[stackr[i].re+1] = '\0';
            strSentence += (szText+stackr[i].rs);
            if(i > 0)
            {
                strSentence += " ";
            }
            szText[stackr[i].re+1] = c;
        }
        vs.push_back(strSentence);
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
