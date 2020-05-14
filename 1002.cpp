
#include <bits/stdc++.h>
using namespace std;

namespace p1002 {
map<int, double, greater<>> m;

int main() {
  for (int i = 0; i < 2; ++i) {
    int k;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      int n;
      cin >> n;
      double a;
      cin >> a;
      m[n] += a;
      if (!m[n]) {
        m.erase(n);
      }
    }
  }
  cout << m.size();
  for (auto [n, a] : m) {
    cout << ' ' << n << ' ' << setprecision(1) << fixed << a;
  }
  cout << endl;
}
} // namespace p1002

int main() { return p1002::main(), 0; }
