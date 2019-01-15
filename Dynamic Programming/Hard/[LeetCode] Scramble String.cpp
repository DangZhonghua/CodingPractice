/*
[LeetCode] Scramble String
http://www.lifeincode.net/programming/leetcode-scramble-string-java/

    Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

    Below is one possible representation of s1 = "great":
        great
       /    \
      gr    eat
     / \    /  \
    g   r  e   at
               / \
              a   t
    1
    2
    3
    4
    5
    6
    7
    	
        great
       /    \
      gr    eat
     / \    /  \
    g   r  e   at
               / \
              a   t

    To scramble the string, we may choose any non-leaf node and swap its two children.

    For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
        rgeat
       /    \
      rg    eat
     / \    /  \
    r   g  e   at
               / \
              a   t
    1
    2
    3
    4
    5
    6
    7
    	
        rgeat
       /    \
      rg    eat
     / \    /  \
    r   g  e   at
               / \
              a   t

    We say that "rgeat" is a scrambled string of "great".

    Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
        rgtae
       /    \
      rg    tae
     / \    /  \
    r   g  ta  e
           / \
          t   a
    1
    2
    3
    4
    5
    6
    7
    	
        rgtae
       /    \
      rg    tae
     / \    /  \
    r   g  ta  e
           / \
          t   a

    We say that "rgtae" is a scrambled string of "great".

    Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

Analysis

If string s1 and s2 are scramble strings, there must be a point that breaks s1 to two parts s11, s12, 
and a point that breaks s2 to two parts, s21, s22, and isScramble(s11, s21) && isScramble(s12, s22) is true, 
or isScramble(s11, s22) && isScramble(s12, s21) is true.

So we can make it recursively. We just break s1 at different position to check if 
there exists one position satisfies the requirement.

Some checks are needed otherwise it will time out. For example, 
if the lengths of two strings are different, they can’t be scramble. 
And if the characters in two strings are different, they can’t be scramble either.

Another way is to use DP. I use a three dimension array scramble[][][] to save the states. 
What scramble[k][i][j] means is that two substrings of length k, one starts from i of string s1, 
another one starts from j of string s2, are scramble. We are trying to find scramble[L][0][0]. For every length k, 
we try to divide the string to two parts differently, checking if there is a way that can make it true.
Code
Recursive version

Java
public class Solution {
    public boolean isScramble(String s1, String s2) {
        //Check lengths.
        if (s1.length() != s2.length())
            return false;
        if (s1.equals(s2))
            return true;
            
        int L = s1.length();
        //Check characters.
        int[] chars = new int[26];
        for (int i = 0; i < L; i++) {
            chars[s1.charAt(i) - 'a']++;
            chars[s2.charAt(i) - 'a']--;
        }
            
        for (int i = 0; i < 26; i++) {
            if (chars[i] != 0)
                return false;
        }

        //More letters
        for (int i = 1; i < L; i++) {
            String s11 = s1.substring(0, i);
            String s12 = s1.substring(i, L);
            String s21 = s2.substring(0, i);
            String s22 = s2.substring(i, L);
            if (isScramble(s11, s21) && isScramble(s12, s22))
                return true;
            s21 = s2.substring(0, L - i);
            s22 = s2.substring(L - i, L);
            if (isScramble(s11, s22) && isScramble(s12, s21))
                return true;
        }
        return false;
    }
}
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
	
public class Solution {
    public boolean isScramble(String s1, String s2) {
        //Check lengths.
        if (s1.length() != s2.length())
            return false;
        if (s1.equals(s2))
            return true;
            
        int L = s1.length();
        //Check characters.
        int[] chars = new int[26];
        for (int i = 0; i < L; i++) {
            chars[s1.charAt(i) - 'a']++;
            chars[s2.charAt(i) - 'a']--;
        }
            
        for (int i = 0; i < 26; i++) {
            if (chars[i] != 0)
                return false;
        }
 
        //More letters
        for (int i = 1; i < L; i++) {
            String s11 = s1.substring(0, i);
            String s12 = s1.substring(i, L);
            String s21 = s2.substring(0, i);
            String s22 = s2.substring(i, L);
            if (isScramble(s11, s21) && isScramble(s12, s22))
                return true;
            s21 = s2.substring(0, L - i);
            s22 = s2.substring(L - i, L);
            if (isScramble(s11, s22) && isScramble(s12, s21))
                return true;
        }
        return false;
    }
}

DP version

Java
public class Solution {
    public boolean isScramble(String s1, String s2) {
        //Check lengths.
        if (s1.length() != s2.length())
            return false;
        if (s1.equals(s2))
            return true;
            
        int L = s1.length();
        boolean[][][] scramble = new boolean[L][L][L];
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L; j++)
                if (s1.charAt(i) == s2.charAt(j))
                    scramble[0][i][j] = true;
        }
        
        for (int k = 2; k <= L; k++) {
            for (int i = L - k; i >= 0; i--) {
                for (int j = L - k; j >= 0; j--) {
                    boolean canScramble = false;
                    for (int m = 1; m < k; m++) {
                        canScramble = (scramble[m - 1][i][j] && scramble[k - m - 1][i + m][j + m]) || (scramble[m - 1][i][j + k -m] && scramble[k - m - 1][i + m][j]);
                        if (canScramble)
                            break;
                    }
                    scramble[k - 1][i][j] = canScramble;
                }
            }
        }
        
        return scramble[L - 1][0][0];
    }
}
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
	
public class Solution {
    public boolean isScramble(String s1, String s2) {
        //Check lengths.
        if (s1.length() != s2.length())
            return false;
        if (s1.equals(s2))
            return true;
            
        int L = s1.length();
        boolean[][][] scramble = new boolean[L][L][L];
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L; j++)
                if (s1.charAt(i) == s2.charAt(j))
                    scramble[0][i][j] = true;
        }
        
        for (int k = 2; k <= L; k++) {
            for (int i = L - k; i >= 0; i--) {
                for (int j = L - k; j >= 0; j--) {
                    boolean canScramble = false;
                    for (int m = 1; m < k; m++) {
                        canScramble = (scramble[m - 1][i][j] && scramble[k - m - 1][i + m][j + m]) || (scramble[m - 1][i][j + k -m] && scramble[k - m - 1][i + m][j]);
                        if (canScramble)
                            break;
                    }
                    scramble[k - 1][i][j] = canScramble;
                }
            }
        }
        
        return scramble[L - 1][0][0];
    }
}

Complexity

The complexity of DP version is O(n4)
.
*/