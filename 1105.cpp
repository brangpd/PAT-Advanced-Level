
#include <bits/stdc++.h>
using namespace std;

namespace p1105 {
int N;
int m, n;
vector<vector<int>> mat;
vector<int> arr;
bool outOfRange(int i, int j) { return i < 0 || j < 0 || i >= m || j >= n; }
int main() {
  cin >> N;
  copy_n(istream_iterator<int>(cin), N, back_inserter(arr));
  sort(begin(arr), end(arr), greater<int>());
  for (m = ceil(sqrt(N));; ++m) {
    n = N / m;
    if (N % m == 0) {
      break;
    }
  }
  mat.resize(m);
  for (auto &row : mat) {
    row.resize(n);
  }
  int i{}, j{};
  const int deltas[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  auto deltait = begin(deltas), deltaite = end(deltas);
  for (auto it = begin(arr), ite = end(arr); it != ite; ++it) {
    mat[i][j] = *it;
    auto &&[newi, newj] = make_tuple(i + (*deltait)[0], j + (*deltait)[1]);
    if (outOfRange(newi, newj) || mat[newi][newj] != 0) {
      if (++deltait == deltaite) {
        deltait = begin(deltas);
      }
    }
    tie(i, j) = make_tuple(i + (*deltait)[0], j + (*deltait)[1]);
  }
  for (i = 0; i < m; ++i) {
    for (j = 0; j < n; ++j) {
      cout << mat[i][j] << " \n"[j == n - 1];
    }
  }

  return 0;
}
} // namespace p1105

int main() { return p1105::main(), 0; }
