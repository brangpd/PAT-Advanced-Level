
#include <bits/stdc++.h>
using namespace std;

namespace p1009 {
int main() {
  ios::sync_with_stdio(false);
  int k;
  map<int /* expo */, double /* coe */, greater<>> m[3];
  cin >> k;
  for (int i = 0; i < k; ++i) {
    int n;
    double a;
    cin >> n >> a;
    m[0][n] = a;
  }
  cin >> k;
  for (int i = 0; i < k; ++i) {
    int n;
    double a;
    cin >> n >> a;
    for (auto [expo, coe] : m[0]) {
      m[1][n + expo] += a * coe;
    }
  }
  for (auto [expo, coe] : m[1]) {
    if (fabs(coe) >= 1e-6) {
      m[2].emplace(expo, coe);
    }
  }
  cout << m[2].size();
  for (auto [expo, coe] : m[2]) {
    cout << ' ' << expo << ' ' << fixed << setprecision(1) << coe;
  }
  return 0;
}
} // namespace p1009

int main() { return p1009::main(), 0; }
