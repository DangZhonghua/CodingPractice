/*
Buying Vegetables 

https://practice.geeksforgeeks.org/problems/buying-vegetables/0


Rahul wanted to purchase vegetables mainly brinjal, carrot and tomato. There are N different vegetable sellers in a line. Each vegetable seller sells all three vegetable items, but at different prices. Rahul, obsessed by his nature to spend optimally, decided not to purchase same vegetable from adjacent shops. Also, Rahul will purchase exactly one type of vegetable item (only 1 kg) from one shop. Rahul wishes to spend minimum money buying vegetables using this strategy. Help Rahul determine the minimum money he will spend.

Input:
First line indicates number of test cases T. Each test case in its first line contains N denoting the number of vegetable sellers in Vegetable Market. Then each of next N lines contains three space separated integers denoting cost of brinjal, carrot and tomato per kg with that particular vegetable seller.

Output:
For each test case, output the minimum cost of shopping taking the mentioned conditions into account in a separate line.

Constraints:
1 <= T <= 10
1 <= N <= 100000
Cost of each vegetable(brinjal/carrot/tomato) per kg does not exceed 10^4

Example
Input:
1
3
1 50 50
50 50 50
1 50 50
Output:
52
Explanation:
There are two ways, each one gives 52 as minimum cost. One way is buy brinjals from first shop, carrots from second shop and brinjals from third shop or he can buy brinjals from first shop, tomatoes from second shop and brinjals from third shop.
Both ways , cost comes up to 1 + 50 + 1 = 52


*/