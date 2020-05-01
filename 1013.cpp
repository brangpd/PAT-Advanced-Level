
#include <bits/stdc++.h>
using namespace std;

namespace p1013 {
int N, M, K;
enum { maxn = 1005 };
vector<int> to[maxn];
int dsu[maxn];
int find(int n) { return dsu[n] == n ? n : dsu[n] = find(dsu[n]); }
void broken(int city) {
  iota(dsu, dsu + maxn, 0);
  for (int i = 1; i <= N; ++i) {
    if (i == city) {
      continue;
    }
    int pi = find(i);
    for (auto &j : to[i]) {
      if (j == city) {
        continue;
      }
      int pj = find(j);
      if (pi != pj) {
        dsu[pi] = pj;
      }
    }
  }
  vector<int> nums;
  for (int i = 1; i <= N; ++i) {
    if (i != city) {
      nums.push_back(find(i));
    }
  }
  auto end = unique(nums.begin(), nums.end());
  cout << end - nums.begin() - 1 << '\n';
}
int main() {
  cin >> N >> M >> K;
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  for (int i = 0; i < K; ++i) {
    int city;
    cin >> city;
    broken(city);
  }
  return 0;
}
} // namespace p1013

int main() { return p1013::main(), 0; }
