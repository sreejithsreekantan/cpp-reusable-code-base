#ifndef __UNIONFIND_HPP__
#define __UNIONFIND_HPP__

#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
	vector< int > *_size;
	vector< int > *_parent;
	int _rows, _cols, _total_num_nodes;
public:
	UnionFind(int rows, int cols): _rows( rows ), _cols( cols ), _total_num_nodes(_rows * _cols + 2) {
		// clog << "_total_num_nodes = " << _total_num_nodes << endl;
		_parent = new vector< int >( _total_num_nodes );
		_size = new vector< int >( _total_num_nodes );
		// clog << "size of _parent = " << ( *_parent ).size() << endl;
		for ( int i = 0; i < _total_num_nodes; i++ ) {
			( *_parent )[ i ] = i;
			( *_size )[ i ] = 1;
		}
		for( int i = 1; i <= _cols; i++ ) {
			// clog << i << " " << _total_num_nodes - 1 - i << endl;
			union_nodes( 0, i );
			union_nodes( _total_num_nodes - 1, _total_num_nodes - 1 - i );
		}
	}
	
	void open( int a ) {
		if( a-1 != ( *_parent )[ a-1 ] ) union_nodes( a, a-1 );
		if( a+1 != ( *_parent )[ a+1 ] ) union_nodes( a, a+1 );
		if( a - _cols != ( *_parent )[ a - _cols ] ) union_nodes( a, a - _cols );
		if( a + _cols != ( *_parent )[ a + _cols ] ) union_nodes( a, a + _cols );
	}
	
	int root( int a ) {
		int p = a;
		while( p != ( *_parent )[ p ] ) {
			( *_parent )[ p ] = ( *_parent )[ ( *_parent )[ p ] ];
			p = ( *_parent )[ p ];
		}
		return p;
	}
	
	void union_nodes( int a, int b ) {
		int root_a = root( a );
		int root_b = root( b );
		if( ( *_size )[ root_a ] < ( *_size )[ root_a ] ) {
			( *_parent )[ root_a ] = root_b;
			( *_size )[ root_b ] += ( *_size )[ root_a ];
		}
		else {
			( *_parent )[ root_b ] = root_a;
			( *_size )[ root_a ] += ( *_size )[ root_b ];
		}
	}
	
	bool connected( int a, int b ) {
		return ( root( a ) == root( b ) );
	}
	
	~UnionFind() {
		delete _parent;
		delete _size;
	}
	
	void toString() {
		for ( int i = 0; i < _total_num_nodes; i++ ) {
			cout << "(" << i << ", " << ( *_parent )[ i ] << ", " << ( *_size )[ i ] << ")\t\t";
			if( i % _cols == 0 ) {
				cout << endl;
			}  
		}
		cout << endl;
	}
	
private:
	UnionFind() {
	}
};

#endif // __UNIONFIND_HPP__
