#ifndef ADT GRAPH H
#define ADT GRAPH H

#include <unordered_set>
#include <unordered_map>
#include <concepts>
#include <vector>

using namespace std;

template<typename T>
concept Graphable = requires(T t1, T t2)
{
    { t1 == t2 } -> std::same_as<bool>;
    { std::hash<T>{}(t1) } -> std::convertible_to<size_t>;
};

template<Graphable N>
struct Node
{
    N entry;
};

template<Graphable N, Graphable E>
struct Edge
{
    E data;
    unordered_set<Node<N>> connections;
};

template<Graphable N, Graphable E> 
class Graph
{
public:
    Graph();
    ~Graph();
    
    Node<N> addNode(const Node<N>& n, bool rebuildGraph = false);
    Node<N> removeNode(const Node<N>& n, bool rebuildGraph = false);
    Node<N> removeNode(const N& n, bool (*comparator)(const N&, const N&), bool rebuildGraph = false);
    Node<N> getNode(const N& n, bool (*comparator)(const N&, const N&));

    Edge<N,E> addEdge(const Edge<N,E>& e, bool rebuildGraph = false);
    Edge<N,E> removeEdge(const Edge<N,E>& e, bool rebuildGraph = false);
    Edge<N,E> removeEdge(const E& e, bool (*comparator)(const E&, const E&), bool rebuildGraph = false);

    void buildGraph();

private:
    unordered_set<Node<N>>* nodes;
    unordered_set<Edge<N,E>>* edges;
    unordered_map<Node<N>, Edge<N,E>>* graph;
};

template<Graphable N, Graphable E> 
class PointerGraph
{
public:
    PointerGraph();
    ~PointerGraph();
    
    Node<N>* addNode(Node<N>* n, bool rebuildGraph = false);
    Node<N>* removeNode(Node<N>* n);
    Node<N>* getNode(int i);

    Edge<N,E>* addEdge(Edge<N,E>* e, rebuildGraph = false);
    Edge<N,E> removeEdge(Edge<N,E>* e)

    void buildGraph();

private:
    unordered_set<Node<N>*>* nodes;
    unordered_set<Edge<N,E>*>* edges;
    unordered_map<Node<N>*, Edge<N,E>*>* graph;
};

#endif