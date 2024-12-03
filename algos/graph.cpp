#include "graph.h"

template <Graphable N, Graphable E>
Graph<N,E>::Graph()
{
    nodes = new unordered_set<Node<N>>();
    edges = new unordered_set<Edge<N,E>>();
    graph = new unordered_map<Node<N>, Edge<N,E>>();
    
}