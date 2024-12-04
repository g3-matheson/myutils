#ifndef DIJKSTRA
#define DIJKSTRA

#include <vector>
#include "graph.h"

using namespace std;

class Dijkstra
{
    template<Graphable N, Graphable E>
    static unordered_map<TraversalNode<N>,E> getAllNodes(const LinkedGraph<N,E>& g,
                                             const TraversalNode<N>& origin,
                                             E (*traverseSumFn)(E,E))
    {
        unordered_map<TraversalNode<N>, E> sums;
        unordered_set<Edge<N,E>> rawPaths = g.getConnections(origin);
        unordered_set<TraversalEdge<N,E>> paths;
        transform(rawPaths.begin(), rawPaths.end(),
                  inserter(paths, paths.end()),
                  [](const Edge<N,E>& e)
                    {
                        return static_cast<TraversalEdge<N,E>>(e);
                    });

        unordered_set<Node<N>> rawNeighbors;
        unordered_set<TraversalNode<N>> neighbors;

        for(auto p : paths)
        {   
            rawNeighbors = p.connections;
            transform(rawNeighbors.begin(), rawNeighbors.end(),
                      inserter(neighbors, neighbors.end()),
                      [](const Node<N>& n)
                      {
                        return static_cast<TraversalNode<N>(n);
                      });
            for(auto neighbor : neighbors)
            {
                sum.at(neighbor) = traverseSumFn(sum.at(neighbor), e.data)
            }
        }

    }


};

#endif