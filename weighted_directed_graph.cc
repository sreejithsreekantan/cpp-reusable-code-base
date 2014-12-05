#ifndef __WEIGHTDIRECTEDGRAPH_HPP__
#define __WEIGHTDIRECTEDGRAPH_HPP__

// TODO : (INCOMPLETE)

#include <set>

class WeightedDirectedGraph
{
private:
	std::vector< std::set<WeightedDirectedEdge> > adjList;
	WeightedDirectedEdge();
public:
	WeightedDirectedEdge(int size);
};

WeightedDirectedEdge::WeightedDirectedEdge(int size)
{
	adjList.resize(size);
}
#endif //__WEIGHTDIRECTEDGRAPH_HPP__
