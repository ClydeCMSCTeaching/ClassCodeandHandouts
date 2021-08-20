#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <list>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <stack>    

typedef int NodeLabel;

struct Edge {
    NodeLabel src;
    NodeLabel dst;
};


/// 
/// if we use a vector where vec[0] -> a list of 0th node's neighbors.... "Roscoe Street" 
//
struct DirectedGraph {
public:
    DirectedGraph() = default;
    DirectedGraph(std::vector<Edge> init_edges);


    void addEdge(Edge const& edge);
    bool hasVertex(NodeLabel i) const;
    bool isEdge(NodeLabel i, NodeLabel j);
    int numNodes() const;
    int numEdges() const;

    void BFS(NodeLabel s);
    void DFS(NodeLabel s);
    
private:
    std::unordered_map<NodeLabel, std::list<NodeLabel>> adj_list; 
};


DirectedGraph::DirectedGraph(std::vector<Edge> init_edges) {
    for (auto edge : init_edges) 
        addEdge(edge);
}

bool DirectedGraph::hasVertex(NodeLabel i) const{
    return (adj_list.count(i) > 0);
}

void DirectedGraph::addEdge(Edge const& edge) {
    //edge = (u, v).... what if u or v isn't in our graph?
    if (hasVertex(edge.src)) {
        adj_list[edge.src].push_back(edge.dst);
    } else {
        adj_list.insert({edge.src, {edge.dst}});
    }
}

bool DirectedGraph::isEdge(NodeLabel i, NodeLabel j) {
    auto neighs = adj_list[i]; // neighs is the list of i's neighboors
    for (auto p : neighs) {
        if (p == j) {return true;}
    }
    return false;
}

int DirectedGraph::numNodes() const{
    std::unordered_map<NodeLabel, bool> counter;
    for (auto node_neighs : adj_list) { // for every node
        if (counter.count(node_neighs.first) == 0) {
            counter.insert({node_neighs.first, true});
        }
        for (auto edge : node_neighs.second) { // and for every node's neighbors
            if (counter.count(edge) == 0) {
                counter.insert({edge, true});
            }
        }
    }

    return counter.size();
}

int DirectedGraph::numEdges() const{
    //in a directed graph we don't have to worry about double counting edges...
    int counter = 0;
    for (auto node_neighs : adj_list) { // for every node
        for (auto edge : node_neighs.second) { // and for every node's neighbors
            counter++; // well darn thats an edge
        }    
    }
    return counter;
}


void DirectedGraph::BFS(NodeLabel s) {
    std::unordered_map<NodeLabel, bool> visited; 
    std::list<NodeLabel> queue;

    visited.insert({s, true}); // mark s seen
    queue.push_back(s); // add it to our queue

    while (not queue.empty()) {
        NodeLabel current = queue.front(); // get first thing
        std::cout << "VISTING: " << current << std::endl;
        queue.pop_front(); // remove from queue

        for (auto p : adj_list[current]) {
            if (visited.count(p) == 0) {
                queue.push_back(p);
                visited.insert({p, true});
            }
        }
    }
}

void DirectedGraph::DFS(NodeLabel s) {
    std::unordered_map<NodeLabel, bool> visited; 
    std::stack<NodeLabel> stack;

    stack.push(s); // add it to our queue

    while (not stack.empty()) {
        NodeLabel current = stack.top(); // get first thing
        stack.pop(); // remove from queue

        if (visited.count(current) == 0) {
            visited.insert({current, true}); // mark s seen
            std::cout << "VISTING: " << current << std::endl;
        }

        for (auto p : adj_list[current]) {
            if (visited.count(p) == 0) {
                stack.push(p);
            }
        }
    }
}




#endif