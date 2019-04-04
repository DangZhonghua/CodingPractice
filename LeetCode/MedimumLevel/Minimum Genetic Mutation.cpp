/*
https://leetcode-cn.com/problems/minimum-genetic-mutation/
433. Minimum Genetic Mutation
A gene string can be represented by an 8-character long string, with choices from "A", "C", "G", "T".
Suppose we need to investigate about a mutation (mutation from "start" to "end"), 
where ONE mutation is defined as ONE single character changed in the gene string.
For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.
Also, there is a given gene "bank", which records all the valid gene mutations. 
A gene must be in the bank to make it a valid gene string.
Now, given 3 things - start, end, bank, 
your task is to determine what is the minimum number of mutations needed to mutate from "start" to "end". 
If there is no such a mutation, return -1.
Note:
Starting point is assumed to be valid, so it might not be included in the bank.
If multiple mutations are needed, all mutations during in the sequence must be valid.
You may assume start and end string is not the same.
 
Example 1:
start: "AACCGGTT"
end:   "AACCGGTA"
bank: ["AACCGGTA"]

return: 1
 
Example 2:
start: "AACCGGTT"
end:   "AAACGGTA"
bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]

return: 2
 
Example 3:
start: "AAAAACCC"
end:   "AACCCCCC"
bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]

return: 3
 
*/




/*

use Trie tree to search the word.
Use Trie as foundmental is faster for search string.

*/

#include<vector>
#include<string>
#include<queue>
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
            int index = word[i]-'A';
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
            int index = word[i]-'A';
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
            int index = word[i]-'A';
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
            int index = prefix[i]-'A';
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

    int minMutation(string beginWord, string endWord, vector<string>& bank) 
    {

        queue<string> levelQ;
        int nCurCount   = 0;
        int nNextCount  = 0;
        int nLevel      = 0;
         BuildDictionary(bank);
         //There is no endWord in the dictionary.
         if( !m_pDict->search(endWord) )
         {
             return -1;
         }

         levelQ.push(beginWord);
         nCurCount = 1;

         bool bExit = false; 
         char szG[4] = {'A','C','G','T'};
         while(nCurCount && !bExit)
         {
             while(nCurCount  && !bExit) // handle current level
             {
                 string& strFront = levelQ.front();
                 for(int i = 0; i<strFront.length()  && !bExit; ++i)
                 {
                     char tc = strFront[i];
                     for(int j=0; j<4 && !bExit; ++j)
                     {
                         char c = szG[j];
                         if( c == tc)
                         {
                             continue;
                         }
                         strFront[i] = c;
                         
                         if(m_pDict->search(strFront))
                         {
                            if(m_pVisited->search(strFront)) // avoid the same string into queue many many time
                            {
                                continue;
                            }
                            m_pVisited->insert(strFront);

                            if(strFront == endWord)
                            {
                                bExit = true;
                                break;   
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
        return nLevel= (bExit? nLevel:-1);
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
