/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 *
 * https://leetcode-cn.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (56.02%)
 * Total Accepted:    4.9K
 * Total Submissions: 8.6K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
 * 
 * 示例:
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // 返回 true
 * trie.search("app");     // 返回 false
 * trie.startsWith("app"); // 返回 true
 * trie.insert("app");   
 * trie.search("app");     // 返回 true
 * 
 * 说明:
 * 
 * 
 * 你可以假设所有的输入都是由小写字母 a-z 构成的。
 * 保证所有输入均为非空字符串。
 * 
 * 
 */

#include<iostream>
#include<string>
#include<vector>
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
    void insert(string word) 
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
    bool search(string word) 
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
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

