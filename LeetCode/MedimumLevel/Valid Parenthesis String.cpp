/*
https://leetcode-cn.com/problems/valid-parenthesis-string/
http://www.cnblogs.com/grandyang/p/7617017.html
678. Valid Parenthesis String

Given a string containing only three types of characters: '(', ')' and '*', 
write a function to check whether this string is valid. We define the validity of a string by these rules: 
Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.

Example 1:
Input: "()"
Output: True

Example 2:
Input: "(*)"
Output: True

Example 3:
Input: "(*))"
Output: True

Note:
The string size will be in the range [1, 100].

*/



#include<iostream>
#include<string>
#include<stack>
using namespace std;

/*

Dang Zhonghua Please Oversee the problem!!!!

*/

#include<stack>
#include<string>
#include<iostream>
using namespace std;

class Solution 
{
public:
    bool checkValidString(string s) 
    {
         bool bVaild = true;
         stack<int> leftS;
         stack<int> starS;
         int N = s.length();
         int i = 0;
         while(i<N && bVaild)
         {
             if('(' == s[i])
             {
                 leftS.push(i);
             }
             else if( '*' == s[i])
             {
                 starS.push(i);
             }
             else // ')' case
             {
                 if(!leftS.empty())
                 {
                     leftS.pop();
                 }
                 else if(!starS.empty())
                 {
                    starS.pop();
                 }
                 else
                 {
                     bVaild = false;
                     break;
                 }
             }
             ++i;
         }
         // Now, check the left '(' and '*'
         
         while(!starS.empty() && !leftS.empty())
         {
            if(leftS.top() > starS.top()) // "*(" case
            {
                bVaild = false;
                break;
            }
            leftS.pop();
            starS.pop();
         }
         if( !leftS.empty())
         {
             bVaild = false;
         }
        return bVaild;
    }
};


class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left, star;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') star.push(i);
            else if (s[i] == '(') left.push(i);
            else {
                if (left.empty() && star.empty()) return false;
                if (!left.empty()) left.pop();
                else star.pop();
            }
        }
        while (!left.empty() && !star.empty()) {
            if (left.top() > star.top()) return false;
            left.pop(); star.pop();
        }
        return left.empty();
    }
};

/*

如果你觉得上面的解法逻辑稍稍复杂了一些，我们来看一种逻辑无比简单的解法。
既然星号可以当左括号和右括号，那么我们就正反各遍历一次，正向遍历的时候，
我们把星号都当成左括号，此时用经典的验证括号的方法，即遇左括号计数器加1，
遇右括号则自减1，如果中间某个时刻计数器小于0了，直接返回false。如果最终计数器等于0了，
我们直接返回true，因为此时我们把星号都当作了左括号，可以跟所有的右括号抵消。
而此时就算计数器大于0了，我们暂时不能返回false，
因为有可能多余的左括号是星号变的，星号也可以表示空，所以有可能不多，
我们还需要反向q一下，哦不，是反向遍历一下，这是我们将所有的星号当作右括号，
遇右括号计数器加1，遇左括号则自减1，如果中间某个时刻计数器小于0了，直接返回false。
遍历结束后直接返回true，这是为啥呢？此时计数器有两种情况，要么为0，要么大于0。为0不用说，肯定是true，
为啥大于0也是true呢？因为之前正向遍历的时候，我们的左括号多了，我们之前说过了，
多余的左括号可能是星号变的，也可能是本身就多的左括号。
本身就多的左括号这种情况会在反向遍历时被检测出来，如果没有检测出来，
说明多余的左括号一定是星号变的。而这些星号在反向遍历时又变做了右括号，
最终导致了右括号有剩余，所以当这些星号都当作空的时候，左右括号都是对应的，即是合法的。
你可能会有疑问，右括号本身不会多么，其实不会的，如果多的话，会在正向遍历中被检测出来，参见代码如下：


*/

class Solution {
public:
    bool checkValidString(string s) {
        int left = 0, right = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' || s[i] == '*') ++left;
            else --left;
            if (left < 0) return false;
        }
        if (left == 0) return true;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')' || s[i] == '*') ++right;
            else --right;
            if (right < 0) return false;
        }
        return true;
    }
};