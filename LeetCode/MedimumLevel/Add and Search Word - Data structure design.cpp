/*
https://leetcode-cn.com/problems/add-and-search-word-data-structure-design/
Add and Search Word - Data structure design

Design a data structure that supports the following two operations:
void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
Example:
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.\

*/

#include<string>
#include<iostream>
using namespace std;

class WordDictionary 
{
    struct Node
    {
        char    arrC[26];
        bool    arrEnd[26];
        Node*   arrChidren[26];
        Node()
        {
            for(int i = 0; i< 26; ++i)
            {
                arrC[i]         = 0;
                arrEnd[i]       = false;
                arrChidren[i]   = nullptr;
            }
        }    
    };
public:
    /** Initialize your data structure here. */
    WordDictionary() 
    {
        m_pDict = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) 
    {
        Node* p = m_pDict;
        int N = word.length();
        int i = 0;
        int index = 0;
        while(i<N)
        {
            index = word[i]-'a';
            p->arrC[index] = 1;
            if(nullptr == p->arrChidren[index])
            {
                p->arrChidren[index] = new Node();    
            }
             p = p->arrChidren[index];
            ++i;
        }
        p->arrEnd[index] = true;
        
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) 
    {
        Node* p = m_pDict;
        int N = word.length();
        int i = 0;
        bool bExist = true;
        int index = 0;
        while(i<N && nullptr != p)
        {
            cout<<word[i]<<endl;
            index = word[i]-'a';
            if( 0==p->arrC[index])
            {
                bExist = false;
                break;
            }
            if( i+1 == N)
            {
                if(!p->arrEnd[index])
                {
                    bExist = false;    
                }
                break;
            }
            p = p->arrChidren[index];
            ++i;
            if(nullptr == p)
            {
                bExist = false;
                break;
            }
        }
        
        return bExist;
    }
private:
    bool SearchIndex()
    {

        return false;
    }
private:
    Node* m_pDict{nullptr};
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */