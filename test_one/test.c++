#include <array>
#include <algorithm>
#include <cassert>
#include <iostream> 
#include <list>
#include <cassert>

  using namespace std;
template <class BidirectionalIterator>
  void reversed (BidirectionalIterator first, BidirectionalIterator last)
{
  while ((first!=last)&&(first!=--last)) {
    std::iter_swap (first,last);
    ++first;
  }
}
int main() {
  list <int> a = {1, 2, 3, 4};
  list <int> b = {1, 2, 3, 4};

  list <int>::iterator it = a.begin();
  list <int>::iterator it2 = a.begin();

  reversed(it, it2);
  bool b = std::equal(a.begin(),a.end(),b.begin());
  cout << b;
}


