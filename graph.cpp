#include "graph.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>

Graph::Graph()
{}

Graph::Graph(const std::vector<std::vector<int> > &adj_mtr):
    m_adj_mtr{adj_mtr}, m_visited(adj_mtr.size(), false)
{}

void Graph::read_adjacency_matrix_from_file(const std::string &path_to_file)
{
    std::ifstream fi(path_to_file);
    size_t counter {0};
    if(fi.is_open())
    {
        m_adj_mtr.clear();
        while(!fi.eof())
        {
            std::string line;
            std::getline(fi, line);
            std::stringstream ss;
            ss << line;
            if(counter == 0)
            {
                auto num_vertex = std::atoi(line.c_str());
                std::vector row(num_vertex, INF);
                m_adj_mtr.resize(num_vertex, row);
                for(int i{0}; i < num_vertex; ++i)
                    m_adj_mtr[i][i] = 0;
                ++counter;
                continue;
            }
            int from, to, weight;
            ss >> from >> to >> weight;
            m_adj_mtr[from][to] = m_adj_mtr[to][from] = weight;
            ++counter;
        }
        fi.close();
        m_visited.clear();
        m_visited.resize(m_adj_mtr.size(), false);
    }
}

void Graph::dfs(int from)
{
    if(!is_vertex_valid(from)) return;
    m_visited[from] = true;
    std::cout << "in " << from << std::endl;
    for(size_t i{0}; i < m_adj_mtr.size(); ++i)
    {
        if(m_adj_mtr[from][i] != INF && !m_visited[i])
            dfs(i);
    }
    std::cout << "out " << from << std::endl;
}

void Graph::bfs(int from)
{
    if(!is_vertex_valid(from)) return;
    std::cout << "*******BFS********" << std::endl;
    std::fill(m_visited.begin(), m_visited.end(), false);
    std::queue<int> q;
    q.push(from);
    m_visited[from] = true;
    int level{0};
    int size{0};
    while(!q.empty())
    {
        std::cout << "LEVEL: " << ++level << std::endl;
        size = q.size();
        while(size--)
        {
            int v = q.front();
            q.pop();
            std::cout << v << std::endl;
            for(size_t i{0}; i < m_adj_mtr.size(); ++i)
            {
                if(m_adj_mtr[v][i] != INF && !m_visited[i])
                {
                    q.push(i);
                    m_visited[i] = true;
                }
            }
        }
    }
}

void Graph::print_adj_mtr() const
{
    for(size_t i{0}; i < m_adj_mtr.size(); ++i)
    {
        for(size_t j{0}; j < m_adj_mtr[i].size(); ++j)
            std::cout << m_adj_mtr[i][j] << " ";
        std::cout << std::endl;
    }
}
