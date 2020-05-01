//
// Created by brang on 4/11/20.
//

#include <algorithm>
#include <bitset>
#include <ios>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

namespace p1003 {
using ll = long long;

enum { maxn = 505, inf = numeric_limits<ll>::max() / 2 };

ll n, m, s, t;
ll menof[maxn];
ll disof[maxn][maxn];
ll men[maxn];
ll cnt[maxn];
ll ans;
ll dis[maxn];
bitset<maxn> vis;
ll disans;

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  for (int i = 0; i < maxn; ++i) {
    for (int j = 0; j < maxn; ++j) {
      disof[i][j] = inf;
    }
  }
  cin >> n >> m >> s >> t;
  for (int i = 0; i < n; ++i) {
    cin >> menof[i];
  }
  for (int i = 0; i < m; ++i) {
    ll c1, c2, l;
    cin >> c1 >> c2 >> l;
    disof[c1][c2] = disof[c2][c1] = l;
  }

  cnt[s] = 1;
  men[s] = menof[s];

  for (int i = 0; i < n; ++i) {
    dis[i] = disof[i][s];
  }

  vis[s] = true;
  // Dijkstra min path
  for (int j = 0; j < n; ++j) {
    ll curdis = inf;
    ll curidx{};
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        if (curdis > dis[i]) {
          curdis = dis[i];
          curidx = i;
        }
      }
    }
    vis[curidx] = true;
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        if (dis[i] > curdis + disof[curidx][i]) {
          dis[i] = curdis + disof[curidx][i];
        }
      }
    }
  }
  disans = dis[t];

  // Bfs for answer
  queue<ll> q;
  q.push(s);
  while (!q.empty()) {
    auto p = q.front();
    q.pop();

  }

  return 0;
}
} // namespace p1003

int main(int argc, char *argv[]) { return p1003::main(argc, argv), 0; }
