#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

class Graph
{
public:
    explicit Graph();
    explicit Graph(const std::vector<std::vector<int> > &adj_mtr);
    void read_adjacency_matrix_from_file(const std::string &path_to_file);
    void dfs(int from);
    void bfs(int from);
    void print_adj_mtr() const;
private:
    std::vector<std::vector<int> > m_adj_mtr;
    std::vector<bool> m_visited;
    const int INF {9999};
    inline bool is_vertex_valid(int v) { return v >= 0 && v < int(m_adj_mtr.size()); }
};

#endif // GRAPH_H
