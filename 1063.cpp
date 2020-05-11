
#include <bits/stdc++.h>
using namespace std;

namespace p1063 {
int N, K;
int main() {
  cin >> N;
  vector<set<int>> sets(N + 1);
  for (int i = 1; i <= N; ++i) {
    int M;
    cin >> M;
    for (int j = 0; j < M; ++j) {
      int v;
      cin >> v;
      sets[i].insert(v);
    }
  }
  cin >> K;
  for (int i = 0; i < K; ++i) {
    int a, b;
    cin >> a >> b;
    auto &aset = sets[a], &bset = sets[b];
    vector<int> tmp;
    set_intersection(aset.begin(), aset.end(), bset.begin(), bset.end(),
                     back_inserter(tmp));
    size_t NC = tmp.size(), NT = aset.size() + bset.size() - NC;
    cout << setprecision(1) << fixed << 100.0 * NC / NT << "%\n";
  }
  return 0;
}
} // namespace p1063

int main() { return p1063::main(), 0; }
