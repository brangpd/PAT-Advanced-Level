
#include <bits/stdc++.h>
using namespace std;

namespace p1011 {
int main() {
  double mx[3];
  for (int i = 0; i < 3; ++i) {
    double v[3];
    for (int j = 0; j < 3; ++j) {
      cin >> v[j];
    }
    auto idx = max_element(v, v + 3) - v;
    cout << "WTL"[idx] << ' ';
    mx[i] = v[idx];
  }
  cout << setprecision(2) << fixed << (mx[0] * mx[1] * mx[2] * 0.65 - 1) * 2;
  return 0;
}
} // namespace p1011

int main() { return p1011::main(), 0; }
