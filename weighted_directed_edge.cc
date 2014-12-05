#ifndef __WEIGHTDIRECTEDEDEDGE_HPP__
#define __WEIGHTDIRECTEDEDEDGE_HPP__

class WeightedDirectedEdge
{
private:
	int _from;
	int _to;
	double _weight;
	WeightedDirectedEdge();
public:
	WeightedDirectedEdge(int from, int to, double weight);
	int from();
	int to();
	double weight();
	bool operator<( WeightedDirectedEdge& that ) const;
};

WeightedDirectedEdge::WeightedDirectedEdge(int from, int to, double weight)
{
	this->_from = from;
	this->_to = to;
	this->_weight = weight;
}

int WeightedDirectedEdge::from()
{
	return this->_from;
}

int WeightedDirectedEdge::to()
{
	return this->_to;
}

double WeightedDirectedEdge::weight()
{
	return this->_weight;
}

bool WeightedDirectedEdge::operator<( WeightedDirectedEdge& that ) const
{
	if( this->_weight < that._weight )
	{
		return true;
	}
	else
		return false;
}
#endif //__WEIGHTDIRECTEDEDEDGE_HPP__
