
#include <bits/stdc++.h>
using namespace std;

namespace p1093 {
enum { P, A, T };
enum { maxn = 100000 + 5 };
enum { mod = 1000000007LL };
int precnts[3][maxn];
int main() {
  int64_t res{};
  auto add = [&res](int64_t n) {
    res += n;
    res %= mod;
  };
  string s;
  cin >> s;
  precnts[P][0] = s[0] == 'P';
  precnts[A][0] = s[0] == 'A';
  precnts[T][0] = s[0] == 'T';
  for (int i = 1, ie = s.size(); i < ie; ++i) {
    precnts[P][i] = precnts[P][i - 1] + (s[i] == 'P');
    precnts[A][i] = precnts[A][i - 1] + (s[i] == 'A');
    precnts[T][i] = precnts[T][i - 1] + (s[i] == 'T');
  }
  for (int i = 1, ie = s.size() - 1; i < ie; ++i) {
    if (s[i] == 'A') {
      add(precnts[P][i] * (precnts[T][ie] - precnts[T][i]));
    }
  }
  cout << res << endl;
  return 0;
}
} // namespace p1093

int main() { return p1093::main(), 0; }
