/*
https://leetcode-cn.com/problems/palindrome-number/
Palindrome Number
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
Example 1:
Input: 121
Output: true
Example 2:
Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:
Coud you solve it without converting the integer to a string?

*/


/*

首先，我们应该处理一些临界情况。所有负数都不可能是回文，例如：-123 不是回文，因为 - 不等于 3。
所以我们可以对所有负数返回 false。
现在，让我们来考虑如何反转后半部分的数字。 对于数字 1221，如果执行 1221 % 10，我们将得到最后一位数字 1，
要得到倒数第二位数字，我们可以先通过除以 10 把最后一位数字从 1221 中移除，1221 / 10 = 122，再求出上一步结果除以10的余数，122 % 10 = 2，
就可以得到倒数第二位数字。如果我们把最后一位数字乘以10，再加上倒数第二位数字，1 * 10 + 2 = 12，
就得到了我们想要的反转后的数字。 如果继续这个过程，我们将得到更多位数的反转数字。
现在的问题是，我们如何知道反转数字的位数已经达到原始数字位数的一半？
我们将原始数字除以 10，然后给反转后的数字乘上 10，所以，当原始数字小于反转后的数字时，就意味着我们已经处理了一半位数的数字。

*/

class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x<0 || (x%10 ==0 && x!=0))
        {
            return false;
        }
        int reversenumber = 0;
        while(x>reversenumber)
        {
            reversenumber = 10*reversenumber + x%10;
            x /=10;
        }

        return (x == reversenumber || x == reversenumber/10);
    }
};