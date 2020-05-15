
#include <bits/stdc++.h>
using namespace std;

namespace p1106 {
struct Node {
  vector<Node *> children;
};
void dfs(Node *p, int depth,
         function<void(Node *leaf, int depth)> const &actForLeaf) {
  if (p->children.empty()) {
    actForLeaf(p, depth);
  } else {
    for (auto &&elem : p->children) {
      dfs(elem, depth + 1, actForLeaf);
    }
  }
}
int main() {
  int N;
  double P, r;
  cin >> N >> P >> r;
  vector<Node> nodes(N);
  for (int i = 0; i < N; ++i) {
    auto &node = nodes[i];
    int K;
    cin >> K;
    node.children.reserve(K);
    while (K--) {
      int id;
      cin >> id;
      node.children.push_back(&nodes[id]);
    }
  }
  enum { inf = numeric_limits<int>::max() };
  int mindepth = inf;
  dfs(&nodes[0], 0,
      [&mindepth](Node *node, int depth) { mindepth = min(mindepth, depth); });
  int cnt{};
  dfs(&nodes[0], 0, [&cnt, mindepth](Node *node, int depth) {
    if (depth == mindepth) {
      ++cnt;
    }
  });
  cout << fixed << setprecision(4) << pow(1 + r / 100, mindepth) * P << ' '
       << cnt;
  return 0;
}
} // namespace p1106

int main() { return p1106::main(), 0; }
