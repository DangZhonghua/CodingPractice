/*
https://www.geeksforgeeks.org/find-minimum-cost-buy-books/
Find minimum cost to buy all books

Given an array of ratings for n books. Find the minimum cost to buy all books with below conditions :

    Cost of every book would be at-least 1 dollar.
    A book has higher cost than an adjacent (left or right) if rating is more than the adjacent.

Examples :

Input : Ratings[] = {1, 3, 4, 3, 7, 1}
Output : 10
Exp :- 1 + 2 + 3 + 1 + 2 + 1 = 10

Input : ratings[] = {1, 6, 8, 3, 4, 1, 5, 7}
Output : 15
Exp :- 1 + 2 + 3 + 1 + 2 + 1 + 2 + 3 = 15 

*/

/*
Dynamic Programming: optimal substructure and overlapped subproblems.

*/