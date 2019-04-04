/*

https://leetcode-cn.com/problems/word-ladder-ii/
Word Ladder II
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:
Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
Example 2:
Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: []

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

*/



/*

use Trie tree to search the word.
Use Trie as foundmental is faster for search string.

*/

#include<vector>
#include<string>
#include<queue>
#include<iostream>
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


class Solution {
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        vector<vector<string> > vvs;
        vector<string> vs;

        queue<string> levelQ;
        int nCurCount   = 0;
        int nNextCount  = 0;

         BuildDictionary(wordList);
         //There is no endWord in the dictionary.
         if( !m_pDict->search(endWord) )
         {
             return vvs;
         }

         levelQ.push(beginWord);
         nCurCount = 1;

         bool bExit = false; 

         while(nCurCount && !bExit)
         {
             while(nCurCount  && !bExit) // handle current level
             {
                 string& strFront = levelQ.front();
                 for(int i = 0; i<strFront.length()  && !bExit; ++i)
                 {
                     char tc = strFront[i];
                     for(char c='a'; c<='z' && !bExit; ++c)
                     {
                         if( c == tc)
                         {
                             continue;
                         }
                         strFront[i] = c;
                         
                         if(m_pDict->search(strFront))
                         {
                            // if(m_pVisited->search(strFront)) // avoid the same string into queue many many time
                            // {
                            //     continue;
                            // }
                            // m_pVisited->insert(strFront);

                            if(strFront == endWord)
                            {
                                vs.push_back(strFront);

                                //bExit = true;
                                //break;   
                            } 
                            else
                            {
                                levelQ.push(strFront);
                                ++nNextCount;
                            }
                         }
                     }
                     strFront[i] = tc;
                 }
                 levelQ.pop();
                --nCurCount;
             }

             nCurCount  = nNextCount;
             nNextCount = 0;
             ++nLevel;
         }
        return nLevel= (bExit? nLevel:0);
    }
private:
    void BuildDictionary(vector<string>& wordList)
    {
        m_pVisited = new Trie();
        m_pDict = new Trie();
        for(auto str:wordList)
        {
            m_pDict->insert(str);
        }
    }

private:
    Trie* m_pDict{nullptr};
    Trie* m_pVisited{nullptr};
};