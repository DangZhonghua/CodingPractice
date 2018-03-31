# There are many,many algorithms and data structures in the word
## At least, studying algorithm and data structures will make brain sharp.

#Basic Algorithm
1. Sort
    1.1 merge sort
    1.2 quick sort
    1.3 count sort
    1.4 heap sort
2. Search
    2.1 binary search
    2.2 hash
3. common
    3.1 level-order, pre-order, in-order, post-order Tree Traveral

#Basic data structure
1. tree
    1.1 Binary Search Tree(BST): properties of BST
2. array
3. string
4. list
5. queue: first in first out
6. stack: first in last out
7. heap:  heap sort and priority queue
8. Graph: build mode for practice problem into graph form.
##Graph
    Graph can be representedn by adjacency list and adjacency matrix. for sparse graph, adjacency list can save space; for dense graph, adjacency matrix have low cost for graph access.
    Vertex and edges(connection or relationship between vertex) are basic  elements of graph.

1. Connect Graph, Disconnect Graph
2. Direct Graph
3. Direct acyclic Graph(DAG):There is topological sort for DAG.
4. UnDirect Graph
5. Weight Graph
### Graph related algorithm
1. Search Graph
    1.1 breath first search **BFS**
    1.2 Depth first search **DFS**
2. Graph Search Application
    2.1 **BFS** can be use to compute the shortest path if the edge is unit.
    2.2 **DFS**: there are many application for **DFS**.
    Such as Strong Connected Components detect-- SCC detect

        2.2.1 one dfs for graph. Transpose Graph, another dfs.
        2.2.2  Tarjan algorithm
        2.2.3  Biconnected graph detect
        2.2.4  Cut vertex detection
        2.2.5  Topological Sort
3. Minimum Spanning Tree(MST)
    Only connected Graph has MSTs. Since tree is connected graph.
    3.1 kruskal algorithm to create MST: Treat graph vertices as disjoint forest: select minmum edge between forest.
    3.2 Prim algorithm to create MST: prim exend one vertex to connect left vertices to build a tree.
4. Single Shortest Path
    4.1, Dijkstra algorithm--for non-negative weight graph
    4.2, Bellman-Ford algoritm, This allow negative edge exist, but it should not exist negative-cycle. and if can report negative-cycle.

5. All Pairs Shortest Path
    5.1, Floyd-Warshall Algorithm, its cute dynamic programming typical example.
    5.2, |G(V)| times dijkstra or bellman-ford algorithm.

# Algorithm Design Technique
1. Divide and conquer
   Find a principle to divide original problem into dependent sub-problem, slove
   the sub-problem, combine sub-solution to slove original problem.
   merge-sort, quick-sort
2. Dynamic Programming
3. Geedy Programming
4. Linear Pogramming
      