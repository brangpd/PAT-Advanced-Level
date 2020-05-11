
#include <bits/stdc++.h>
using namespace std;

namespace p1117 {
int N;
enum { maxn = 100000 + 10 };
int arr[maxn];
int main() {
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> arr[i];
  }
  sort(arr + 1, arr + N + 1);
  int ans{0};
  for (int i = 1; i <= N; ++i) {
    auto rest = N - i + 1;
    ans = max(ans, min(rest, arr[i] - 1));
  }
  cout << ans << endl;
  return 0;
}
} // namespace p1117

int main() { return p1117::main(), 0; }
