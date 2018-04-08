/*

https://practice.geeksforgeeks.org/problems/kill-captain-america/0

Captain America is hiding from Thanos in a maze full of rooms.
The maze is designed in such a way that the room, within it, leads to another room via gate. 
Captain America is hiding only in those rooms which are accessible directly/indirectly through every other room in the maze.
Further provided that, the movement from one room (R1) to another room (R2) is one way(unidirectional) only .
Now, you being on Thanos side, want to kill Captain America.  

Input:
First line of the input contains T, the number of test cases.
First line of each test case contains n(no of rooms) and m(no of gates).
Each m line of test case contains p and q denoting room p is connected to room q .

Output:
Each new line of the output contains Total no of rooms .

Constraints:
1 ≤ T ≤ 100
1 ≤ n ≤ 30000
1 ≤ m ≤ 200000
1 ≤ p,q ≤ n

Example:
Input:
1
5 5
1 2
2 3
3 4
4 3
5 4

Output:
2

*/