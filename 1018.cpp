// I fail to solve this problem.
// If you know the solution, share it with me pls :)
//
// Some blogs would give a solution of DFS after applying the Dijkstra's
// algorithm, however, the DFS leads to the worst time complexity of O(2^n).
// (The PAT online judge gives weak data that accepts it.)
// Consider the following situation:
// full input:
//  https://paste.ubuntu.com/p/hsrB2kYZb4/
//  or generate with 1018gen.py
//
// Cmax = 100, N = 498, Sp = 498, M = 664.
//    1     4     ...
//  /   \ /   \ /     \
// 0     3     6  ...  498
//  \   / \   / \     /
//    2     5     ...
// All the paths have the same cost of 1.
// The numbers of bikes Ci is defined as:
//   Ci = 50, if i % 3 == 2 (2, 5, 8... all nodes in the bottom)
//   Ci = 10, otherwise
//
// It is obvious that the answer is unique and should be
//  0 -> 2 -> 3 -> 5 -> 6 -> ... -> 498
// and the DFS solution causes TLE.

#include <bits/stdc++.h>
using namespace std;

namespace p1018 {
int Cmax;
int N;
int Sp;
int M;
enum { maxn = 600, inf = numeric_limits<int>::max() / 2 };
int costs[maxn][maxn];
int d[maxn];
struct Record {
  int distance; // distance from 0
  int delta;
  vector<int> previous;
} records[maxn];
int C[maxn];
void dijkstra() {
  unordered_set<int> unvisited;
  for (int i = 1; i <= N; ++i) {
    unvisited.insert(i);
  }
  Record infrec{.distance = inf};
  while (!unvisited.empty()) {
    Record *rec = &infrec;
    int i = 0;
    for (auto node : unvisited) {
      auto &currec = records[node];
      if (currec.distance < rec->distance) {
        rec = &currec;
        i = node;
      }
    }
    unvisited.erase(i);
    for (auto node : unvisited) {
      auto &currec = records[node];
      auto newdis = rec->distance + costs[i][node];
      if (currec.distance >= newdis) {
        currec.distance = newdis;
        currec.previous.push_back(node);
      }
    }
  }
}
int main() {
  cin >> Cmax >> N >> Sp >> M;
  for (int i = 1; i <= N; ++i) {
    cin >> C[i];
    auto delta = (Cmax / 2) - C[i];
    records[i].delta = delta;
  }
  for (auto &i : costs) {
    for (auto &j : i) {
      j = inf;
    }
  }
  for (int i = 0; i < M; ++i) {
    int Si, Sj, Tij;
    cin >> Si >> Sj >> Tij;
    costs[Si][Sj] = Tij;
    costs[Sj][Si] = Tij;
  }
  for (auto &rec : records) {
    rec.distance = inf;
  }
  for (int i = 1; i <= N; ++i) {
    records[i].distance = costs[0][i];
  }
  dijkstra();
  return 0;
}
} // namespace p1018

int main() { return p1018::main(), 0; }
