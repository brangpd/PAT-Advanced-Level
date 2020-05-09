
#include <bits/stdc++.h>
using namespace std;

namespace p1128 {
int K, N;
enum { maxn = 1005 };
int q[maxn];
inline int toleftdown(int r, int c) { return r + c; }
inline int torightdown(int r, int c) { return r + (N - 1 - c); }
int main() {
  ios::sync_with_stdio(false);
  cin >> K;
  while (K--) {
    cin >> N;
    bitset<maxn * 2> rowvisited, leftdownvisited, rightdownvisited;
    for (int i = 0; i < N; ++i) {
      cin >> q[i];
    }
    for (int i = 0; i < N; ++i) {
      if (rowvisited[q[i]]) {
        goto L_no;
      } else {
        rowvisited[q[i]] = true;
      }
      if (leftdownvisited[toleftdown(q[i], i)]) {
        goto L_no;
      } else {
        leftdownvisited[toleftdown(q[i], i)] = true;
      }
      if (rightdownvisited[torightdown(q[i], i)]) {
        goto L_no;
      } else {
        rightdownvisited[torightdown(q[i], i)] = true;
      }
    }
    goto L_yes;
  L_no:
    cout << "NO\n";
    continue;
  L_yes:
    cout << "YES\n";
    continue;
  }
  return 0;
}
} // namespace p1128

int main() { return p1128::main(), 0; }
