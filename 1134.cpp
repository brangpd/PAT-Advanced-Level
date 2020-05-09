
#include <bits/stdc++.h>
using namespace std;

namespace p1134 {
enum { maxn = 10000 + 10 };
struct Edge {
  int v[2];
};
Edge edges[maxn];
int N, M, K;
int main() {
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    auto &edge = edges[i];
    auto &[l, r] = edge.v;
    cin >> l >> r;
  }
  cin >> K;
  while (K--) {
    int nv;
    cin >> nv;
    vector<bool> vertex(N, false);
    for (int i = 0; i < nv; ++i) {
      int v;
      cin >> v;
      vertex[v] = true;
    }
    for (int i = 0; i < M; ++i) {
      auto &edge = edges[i];
      auto &[l, r] = edge.v;
      if (vertex[l] || vertex[r]) {
        continue;
      }
      goto L_NO;
    }
    goto L_YES;
  L_NO:
    cout << "No" << endl;
    continue;
  L_YES:
    cout << "Yes" << endl;
    continue;
  }

  return 0;
}
} // namespace p1134

int main() { return p1134::main(), 0; }
