/*
Find if there is a path of more than k length from a source
https://www.geeksforgeeks.org/find-if-there-is-a-path-of-more-than-k-length-from-a-source/

Given a graph, a source vertex in the graph and a number k, 
find if there is a simple path (without any cycle) starting from given source and ending at any other vertex.

One important thing to note is, simply doing BFS or DFS and picking the longest edge at every step would not work. 
The reason is, a shorter edge can produce longer path due to higher weight edges connected through it.

The idea is to use Backtracking. We start from given source, explore all paths from current vertex. 
We keep track of current distance from source. If distance becomes more than k, we return true. 
If a path doesn’t produces more than k distance, we backtrack.

How do we make sure that the path is simple and we don’t loop in a cycle? 
The idea is to keep track of current path vertices in an array. 
Whenever we add a vertex to path, we check if it already exists or not in current path. If it exists, we ignore the edge.

*/