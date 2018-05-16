/*
https://practice.geeksforgeeks.org/problems/villain-con/0

The minions are very elitist in nature.
If minion x admires minion y, then y thinks too high of himself and does not admire x
back.Also, if x admires y, x also admires everyone that y admires. All minions are going
to be present at the “Villain Con”.The minions wanted to make sure that they do not
wear dress of same color as someone who admires them.
Given who admires whom Gru (Minion’s Master) thought of finding the minimum
number of different colored dresses that minions will be seen.

 

Input: 

1st Line Contains T number of test cases
The next line contains the number of minions (N) and the number of relations the
minions will have (M).
Next M lines will contain Xi and Yi separated with space
i.e. Yi admires Xi

Output: 

Minimum no. Of different colored dresses

Constraints:

T ≤ 10

0 ≤ N ≤ 100000

1 ≤ M ≤ 2*100000

1<= Xi,Yi <= N

 

Input:

1
5 6
1 3
2 3
3 4
1 4
2 5
3 5


Output:

3


Explaination:

1, 3, and 5 cannot wear the same dress. so the count is 3

*/