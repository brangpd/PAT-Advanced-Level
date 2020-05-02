
#include <bits/stdc++.h>
using namespace std;

namespace p1058 {
struct N {
  int g, s, k;
} a, b;
enum { MAXS = 17, MAXK = 29 };
N operator+(N const &na, N const &nb) {
  N res = na;
  res.k += nb.k;
  res.s += nb.s;
  res.g += nb.g;
  if (res.k >= MAXK) {
    res.k -= MAXK;
    res.s++;
  }
  if (res.s >= MAXS) {
    res.s -= MAXS;
    res.g++;
  }
  return res;
}
int main() {
  char c;
  cin >> a.g >> c >> a.s >> c >> a.k;
  cin >> b.g >> c >> b.s >> c >> b.k;
  N res = a + b;
  cout << res.g << '.' << res.s << '.' << res.k;
  return 0;
}
} // namespace p1058

int main() { return p1058::main(), 0; }
