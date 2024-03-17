#include <bits/stdc++.h>
using namespace std;

int N, cache[31];

int tiling(int width){
	if(width&0x1)
		return 0;
	int& ret=cache[width];
	if(ret!=-1)
		return ret;

	for(int piece=2; piece<width/2; piece+=2)
