/*
https://www.geeksforgeeks.org/wildcard-pattern-matching-three-symbols/
WildCard pattern matching having three symbols

Given a text and a wildcard pattern, implement wildcard pattern matching algorithm that finds if wildcard pattern is matched with text. The matching should cover the entire text (not partial text).
The wildcard pattern can include the characters ‘?’, ‘*’ and ‘+’.
‘?’ – matches any single character
‘*’ – Matches any sequence of characters
      (including the empty sequence)
'+' – Matches previous single character
      of pattern 
Examples:
Input :Text = "baaabaaa",
Pattern = “****+ba*****a+", output : true
Pattern = "baaa?ab", output : false 
Pattern = "ba*a?", output : true
Pattern = "+a*ab", output : false 

Input : Text = "aab"
Pattern = "*+"  output : false 
Pattern = "*+b" output : true    

*/