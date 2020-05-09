
#include <bits/stdc++.h>
using namespace std;

namespace p1046 {
int N, M;
enum { maxn = 100000 + 5 };
int64_t d[maxn];
int64_t prefix[maxn];
int64_t sum;
int main() {
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> d[i];
    prefix[i] = prefix[i - 1] + d[i];
  }
  sum = prefix[N];
  cin >> M;
  while (M--) {
    int a, b;
    cin >> a >> b;
    if (a > b) {
      swap(a, b);
    }
    int64_t dis = prefix[b - 1] - prefix[a - 1];
    cout << min(dis, sum - dis) << '\n';
  }
  return 0;
}
} // namespace p1046

int main() { return p1046::main(), 0; }
