
#include <bits/stdc++.h>
using namespace std;

namespace p1004 {
using ll = int64_t;
ll n, m;
enum { root = 1 };
enum { maxn = 105 };
vector<ll> children[maxn];
map<ll, ll> cnt;
bool vis[maxn];

void count(ll p = root, ll layer = 0) {
  if (vis[p]) {
    return;
  }
  vis[p] = true;
  cnt[layer];
  if (children[p].empty()) {
    ++cnt[layer];
    return;
  }
  for (auto child : children[p]) {
    count(child, layer + 1);
  }
}

int main() {
  cin >> n >> m;
  if (!n) {
    return 0;
  }
  for (int i = 0; i < m; ++i) {
    ll id, k;
    cin >> id >> k;
    for (int j = 0; j < k; ++j) {
      ll id2;
      cin >> id2;
      children[id].push_back(id2);
    }
  }
  count();
  bool first{true};
  for (auto &&pair : cnt) {
    auto num = pair.second;
    if (!first) {
      cout << ' ';
    }
    first = false;
    cout << num;
  }
  return 0;
}
} // namespace p1004

int main() { return p1004::main(), 0; }
