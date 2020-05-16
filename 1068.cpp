
#include <bits/stdc++.h>
using namespace std;

namespace p1068 {
enum { maxn = 10000 + 10, maxm = 105 };
int N;
int M;
int values[maxn];
enum { OK = 1, UNDEFINED = 0, NO = -1 };
int d[maxn][maxm];
vector<int> selected;
int dfs(int i, int m) {
  if (m == 0) {
    return d[i][m] = OK;
  }
  if (i > N) {
    return d[i][m] = NO;
  }
  if (d[i][m] != UNDEFINED) {
    return d[i][m];
  }
  if (m - values[i] >= 0) {
    if (dfs(i + 1, m - values[i]) == OK) {
      selected.push_back(values[i]);
      return d[i][m] = OK;
    }
    if (dfs(i + 1, m) == OK) {
      return d[i][m] = OK;
    }
  }
  return d[i][m] = NO;
}
template <class OutIt> void output(OutIt it, OutIt ite) {
  bool first = true;
  while (it != ite) {
    if (first) {
      first = false;
    } else {
      cout << ' ';
    }
    cout << *it++;
  }
  cout << '\n';
}
int main() {
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> values[i];
  }
  sort(values, values + N);
  if (dfs(0, M) == OK) {
    output(selected.rbegin(), selected.rend());
  } else {
    cout << "No Solution\n";
  }
  return 0;
}
} // namespace p1068

int main() { return p1068::main(), 0; }
