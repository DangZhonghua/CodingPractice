/*
https://leetcode-cn.com/problems/word-search/
Word Search

The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.
Example:
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.

*/

#include<vector>
#include<string>
#include<iostream>
using namespace std;

int rBN[4] = { 0, -1, 0, 1 };
int cBN[4] = { -1, 0, 1, 0 };

class Solution 
{
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
      m_wordLen = word.length();
      m_R = board.size();
      m_C = board[0].size();
      vector< vector<bool> > vflag(m_R, vector<bool>(m_C,false));
      
      string combWord;
      for( int r = 0; r<m_R; ++r)
      {
        for(int c = 0; c<m_C; ++c)
        {
            combWord.push_back(board[r][c]);
            vflag[r][c] = true;
            if( DFSearchWord(board,vflag,word,combWord,0,r,c) )
            {
              return true;
            }
            combWord.pop_back();
            vflag[r][c] = false;
        }
      }
      return false;
    }

private:
  bool DFSearchWord(vector<vector<char>>& board, vector< vector<bool> >& vflag, string& word, string& combWord, int index, int r, int c)
  {
    if(index == m_wordLen)
    {
      return false;
    }
    if(combWord[index] != word[index])
    {
      return false;
    }
    if( index == m_wordLen-1)
    {
      return true;
    }
    
    for(int i = 0; i<4; ++i)
    {
      int nr = r+ rBN[i];
      int nc = c+ cBN[i];
      if( 0<=nr && nr<m_R && 0<=nc && nc<m_C && !vflag[nr][nc])
      {
        combWord.push_back(board[nr][nc]);
        vflag[nr][nc] = true;
        
        if(DFSearchWord(board,vflag,word,combWord,index+1,nr,nc) )
        {
          return true;
        }
        combWord.pop_back();
        vflag[nr][nc] = false;
      }
    }
    return false;
  }

private:
 int m_R{0};
 int m_C{0};
 int m_wordLen{0};

};