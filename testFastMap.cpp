#include <cstdio>
#include <boost/progress.hpp>
#include "utils.h"


class Index: public FastMapIndex {
  unsigned int a,b,c;
};

int main() {

  FastMap<Index, 1000000, unsigned int> f;
  int f2[1000000];

  Index i;
  i.setID( 5 );

  //boost::progress_display show_progress( 100000000 );
  boost::progress_timer ptimer;

for(int c=0;c<100;++c)
  for(unsigned int k=0;k<1000000;++k) {
    i.setID(k);
    f[i] = k;
    k = f[i];
//    ++show_progress;
  }

}
