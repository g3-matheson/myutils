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
    Node<N> removeNode(const Node<N>& n);
    Node<N> getNode(Node<N> n);
    Node<N> getNode(N n, bool (*comparator)(const N&, const N&));

    Edge<N,D> addEdge(Edge<N,E> e, bool rebuildGraph = false);
    Edge<N,D> removeEdge(Edge<N,E> e);
    Edge<N,D> removeEdge(E e, bool (*comparator)(const E&, const E&))

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

    Edge<N,D>* addEdge(Edge<N,E> e, rebuildGraph = false);
    Edge<N,D> removeEdge(Edge<N,E>* e)

    void buildGraph();

private:
    unordered_set<Node<N>*>* nodes;
    unordered_set<Edge<N,E>*>* edges;
    unordered_map<Node<N>*, Edge<N,E>*>* graph;
};

#endif