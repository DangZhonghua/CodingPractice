/*
Joey doesn't share food 
https://practice.geeksforgeeks.org/problems/joey-doesnt-share-food/0
Every friends fan know that joey loves food and monica loves to cook. 
So, on a occassion of thanksgiving monica made N types of food 
containing exactly 6 ingredients each. 
Monica is an excellent cook so she can cook food by adding any 
ingredient at any order. 
All ingredients contains protein on the scale of 1 to 10^6. 
Now, Chandler invented the fun game where everyone needs to 
find the successive protein rate in all N food of the ingredient 
on the top(6th ingredient is on top). 
Ross being the most curious wants to finish this game before dinner, 
so he wants your help to complete the task.

Input:
First line consists of T test cases. First line of every test case consists of N. 
Next N lines contains the 6 integers each.

Output:
Single line output, print the longest chain formed.

Constraints:
1<=T<=10
1<=N<=50000
1<=Aij<=10^6

Example:
Input:
2
2
1 2 3 4 5 6
8 9 10 11 12 13
4
1 2 3 4 5 6
2 3 4 5 6 7
3 4 5 6 7 10
4 5 6 7 8 9
Output:
1
4

Explanation:
Test 1: self-explanatory

Test 2: If ingredients are arranged in any order and let say if don't rearrange it, ans will be 2.

As 6 7 or 10 9. These are the successive protein rate existing.

If we arrange it in order:

1 2 3 4 5 6

2 3 4 5 6 7

3 4 6 7 10 5

4 5 6 7 9 8

Now the answer will be 4.

As 6 7 5 8, so these protein rates are successive(5 6 7 8).


*/