
#include <bits/stdc++.h>
using namespace std;

namespace p1006 {
int main() {
  int n;
  cin >> n;
  enum { tpid, tpin, tpout };
  using tuple_t = tuple<string /*id*/, string /*in*/, string /*out*/>;
  vector<tuple_t> tuples;
  while (n--) {
    string id, in, out;
    cin >> id >> in >> out;
    tuples.emplace_back(id, in, out);
  }
  sort(tuples.begin(), tuples.end(), [](const tuple_t &a, const tuple_t &b) {
    return get<tpin>(a) < get<tpin>(b);
  });
  cout << get<tpid>(tuples.front()) << ' ';
  sort(tuples.begin(), tuples.end(), [](const tuple_t &a, const tuple_t &b) {
    return get<tpout>(a) < get<tpout>(b);
  });
  cout << get<tpid>(tuples.back());
  return 0;
}
} // namespace p1006

int main() { return p1006::main(), 0; }
