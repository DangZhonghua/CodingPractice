/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙 Word Ladder
 *
 * https://leetcode-cn.com/problems/word-ladder/description/
 * http://www.cnblogs.com/grandyang/p/4539768.html
 * algorithms
 * Medium (32.05%)
 * Total Accepted:    4.3K
 * Total Submissions: 13.5K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord
 * 的最短转换序列的长度。转换需遵循如下规则：
 * 
 * 
 * 每次转换只能改变一个字母。
 * 转换过程中的中间单词必须是字典中的单词。
 * 
 * 
 * 说明:
 * 
 * 
 * 如果不存在这样的转换序列，返回 0。
 * 所有单词具有相同的长度。
 * 所有单词只由小写字母组成。
 * 字典中不存在重复的单词。
 * 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * 输出: 5
 * 
 * 解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * ⁠    返回它的长度 5。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * 输出: 0
 * 
 * 解释: endWord "cog" 不在字典中，所以无法进行转换。
 * 
 */



/*

 every position in the word has 26 choice ['a'~'z'] to transform.
 BFS: one vertex has 26 adjacency vertices. 

*/



#include<string>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;


/*

use Trie tree to search the word.
Use Trie as foundmental is faster for search string.

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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        
    }
};

