#!/bin/bash

touch $1
echo "#include <bits/stdc++.h>" >> $1
echo "using namespace std;" >> $1
echo "#define FOR(i,n) for(auto i=0; i<(n); ++i)" >> $1
vi $1
