/*
Temple Offerings
https://practice.geeksforgeeks.org/problems/temple-offerings/0

Consider a devotee wishing to give offerings to temples along a mountain range. The temples are located in a row at different heights. Devotee is very religious and wants to offer each temple at least one offering. If two adjacent temples are at different altitudes, then the temple that is higher up should receive more offerings than the one that is lower down. If two adjacent temples are at the same height, then their offerings relative to each other does not matter. Find the minimum number of offerings to bring.

Input:
The first line of the input contains an integer T, denoting the number of test cases. Then T test cases follow. First line of each test case contains an integer N denoting the total number of temples. Next line contains N space seperated integers denoting the height of the respective temple.

Output:
For each test case output a single line denoting the minimum number of offering that the devotee should bring.

Constraints:
1<=T<=104
1<=N<=106
1<=templeHeight<=103

Example:
Input:
2
3
1 2 2
6
1 4 3 6 2 1

Output:
4
10

Explanation:

Test case 1:

All temples must receive at-least one offering. Now, the second temple is at a higher altitude compared to the first one. Thus it receives one extra offering. The second temple and third temple are at the same height, so we do not need to modify the offerings. Offerings given are therefore: 1, 2, 1 giving a total of 4.

Test case 2:

We can distribute the offerings in the following way, 1, 2, 1, 3, 2, 1. The second temple has to receive more offerings than the first due to its height being higher. The fourth must receive more than the fifth, which in turn must receive more than the sixth. Thus the total becomes 10.

*/