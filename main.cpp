#include "graph.hpp"
#include <iostream>

int main()
{
    Graph graph;
    graph.read_adjacency_matrix_from_file("input.txt");
    graph.print_adj_mtr();
    std::cout << "*******BFS********" << std::endl;
    graph.dfs(0);
    graph.bfs(0);
    return 0;
}
