
#include <bits/stdc++.h>
using namespace std;

namespace p1037 {
enum { maxn = 100000 + 10 };
int64_t nc[maxn];
int64_t np[maxn];
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> nc[i];
  }
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> np[i];
  }
  auto comp = [](int a, int b) {
    if (a <= 0 || b <= 0) {
      return a < b;
    }
    return a > b;
  };
  auto ncit = nc, ncite = nc + n;
  auto npit = np, npite = np + n;
  sort(ncit, ncite, comp);
  sort(npit, npite, comp);
  int64_t ans{};
  while (ncit != ncite && npit != npite) {
    auto tmp = *ncit * *npit;
    if (tmp > 0) {
      ans += tmp;
      ++ncit;
      ++npit;
      continue;
    }
    while (ncit != ncite && *ncit <= 0) {
      ++ncit;
    }
    while (npit != npite && *npit <= 0) {
      ++npit;
    }
  }
  cout << ans << endl;
  return 0;
}
} // namespace p1037

int main() { return p1037::main(), 0; }
