//
//  endian.cc
//  CPP reusable code base
//
//  Created by Sreejith Sreekantan.
//  Copyright (c) 2013 Sreejith Sreekantan. All rights reserved.
//

#include <boost/detail/endian.hpp>
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#ifdef BOOST_LITTLE_ENDIAN

uint64_t htonll(uint64_t l_num){
  uint64_t mask = 0xFF00000000000000ULL;
	uint64_t res = 0;
	for (int i=0; i<4; i++,mask=mask>>8) {
		res |= ((l_num&mask)>>(56-(i*16)));
	}
	for (int i=3; i>-1; i--,mask=mask>>8) {
		res |= ((l_num&mask)<<(56-(i*16)));
	}
	return res;
}

uint64_t ntohll(uint64_t b_num){
	uint64_t mask = 0xFF00000000000000ULL;
	uint64_t res = 0;
	for (int i=0; i<4; i++,mask=mask>>8) {
		res |= ((b_num&mask)>>(56-(i*16)));
	}
	for (int i=3; i>-1; i--,mask=mask>>8) {
		res |= ((b_num&mask)<<(56-(i*16)));
	}
	return res;
}

#elif defined BOOST_BIG_ENDIAN

uint64_t htonll(uint64_t l_num) {
	return l_num; // no change to make
}

uint64_t ntohll(uint64_t b_num){
	return b_num; // no change to make
}
	
#else

#error Endian conversion unsupported on this platform.

#endif

int main() {

	
	uint64_t n = 0x0123456789ABCDEF;
	
	htonll(n);
	n = ntohll(n);
	
}
