#include "graph.h"

template <Graphable N, Graphable E>
Graph<N,E>::Graph()
{
    nodes = new unordered_set<Node<N>>();
    edges = new unordered_set<Edge<N,E>>();
    graph = new unordered_map<Node<N>, Edge<N,E>>();
    
}

template <Graphable N, Graphable E>
Graph<N,E>::~Graph()
{
    delete nodes;
    delete edges;
    delete graph;
}

template <Graphable N, Graphable E>
Node<N> Graph<N,E>::addNode(const Node<N>& n, bool rebuildGraph)
{
    nodes->insert(n);
    if(rebuildGraph) { buildGraph(); }
}

template <Graphable N, Graphable E>
Node<N> Graph<N,E>::removeNode(const Node<N>& n, bool rebuildGraph)
{
    nodes->erase(n);
    if(rebuildGraph) { buildGraph(); }
}

template <Graphable N, Graphable E>
Node<N> Graph<N,E>::removeNode(const N& n, bool (*comparator)(const N&, const N&), bool rebuildGraph)
{
    // locate the node using the passed in equality comparator (works on types N which are Node::entry)
    const auto it = std::find_if(nodes->begin(), nodes->end(), [&](const Node<N>& elem) {return comparator(elem.entry, n)});
    if(it != nodes->end()) { nodes->erase(it); }
    
    if(rebuildGraph) { buildGraph(); }
}

template <Graphable N, Graphable E>
Node<N> Graph<N,E>::getNode(const N& n, bool (*comparator)(const N&, const N&))
{
    const auto it = std::find_if(nodes->begin(), nodes->end(), [&](const Node<N>& elem) { return comparator(elem.entry, n)});
    if(it != nodes->end()) { return *it; }
}

template <Graphable N, Graphable E>
Edge<N,E> Graph<N,E>::addEdge(const Edge<N,E>& e, bool rebuildGraph = false)
{
    edges->insert(e);
    if(rebuildGraph) { buildGraph(); }
}



template <Graphable N, Graphable E>
Edge<N,E> Graph<N,E>::removeEdge(const Edge<N,E>& e, bool rebuildGraph = false)
{
    edges->erase(n);
    if(rebuildGraph) { buildGraph(); }
}

template <Graphable N, Graphable E>
Edge<N,E> Graph<N,E>::removeEdge(const E& e, bool (*comparator)(const E&, const E&), bool rebuildGraph = false)
{
    // locate the node using the passed in equality comparator (works on types N which are Node::entry)
    const auto it = std::find_if(edges->begin(), edges->end(), [&](const Node<N>& elem) {return comparator(elem.data, e)});
    if(it != edges->end()) { edges->erase(it); }
    
    if(rebuildGraph) { buildGraph(); }
}

template <Graphable N, Graphable E>
void Graph<N,E>::buildGraph()
{
    
}