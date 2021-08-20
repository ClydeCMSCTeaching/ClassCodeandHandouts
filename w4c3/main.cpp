#include <iostream>
#include "graph.hpp"
#include <vector>

int main() {
    // 0 -> 1 -> 2 then goes back to 0
    std::vector<Edge> line_graph = {{0,1}, {1,4}, {4, 3}, 
    
                                    {3, 2}, {2, 3}, {0, 2}};

    DirectedGraph graph = DirectedGraph(line_graph);

    std::cout << "this has " << graph.numNodes() << "nodes and "
              << graph.numEdges() << "edges." << std::endl;

    std::cout << "there is an edge (1,2) " << graph.isEdge(1,2) << " but not (2,1) " << graph.isEdge(2,1)
               << std::endl;
    

    std::cout << "BFS on our graph" << std::endl;

    std::cout << "\nRunning BFS\n";
    graph.BFS(0);
    std::cout << "\nRunning DFS\n";
    graph.DFS(0);
}