#include <bits/stdc++.h>
using namespace std;

struct Label
{
   unsigned ID;
   unsigned distance;

   inline bool operator>(const Label& l) const{
      return this->distance>l.distance;
   }
};


: