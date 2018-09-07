/*
Water Jug Problem using Memoization
https://www.geeksforgeeks.org/water-jug-problem-using-memoization/

Water Jug Problem using Memoization

Given two jugs with the maximum capacity of m and n liters respectively. The jugs don’t have markings on them which can help us to measure smaller quantities. The task is to measure d liters of water using these two jugs. Hence our goal is to reach from initial state (m, n) to final state (0, d) or (d, 0).

Examples:

    Input: 4 3 2
    Output: (0, 0) –> (4, 0) –> (4, 3) –> (0, 3) –> (3, 0) –> (3, 3) –> (4, 2) –> (0, 2)

    Input: 5 2 4
    Output: (0, 0) –> (5, 0) –> (5, 2) –> (0, 2) –> (2, 0) –> (2, 2) –> (4, 0)

*/