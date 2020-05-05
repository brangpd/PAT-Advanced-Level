
#include <bits/stdc++.h>
using namespace std;

namespace p1054 {
int main() {
  int M, N;
  cin >> M >> N;
  vector<int> colors(N * M);
  for (auto &i : colors) {
    cin >> i;
  }
  auto k = (N * M) / 2;
  nth_element(colors.begin(), colors.begin() + k, colors.end());
  cout << colors[k];
  return 0;
}
} // namespace p1054

int main() { return p1054::main(), 0; }
