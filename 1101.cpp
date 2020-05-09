
#include <bits/stdc++.h>
using namespace std;

namespace p1101 {
int N;
enum { maxn = 100000 + 10 };
int arr[maxn];
int mn[maxn];
int mx[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> arr[i];
  }
  for (int i = 1; i <= N; ++i) {
    mx[i] = max(mx[i - 1], arr[i]);
  }
  mn[N + 1] = numeric_limits<int>::max();
  for (int i = N; i >= 1; --i) {
    mn[i] = min(mn[i + 1], arr[i]);
  }
  vector<int> ans;
  for (int i = 1; i <= N; ++i) {
    if (mx[i - 1] < arr[i] && arr[i] < mn[i + 1]) {
      ans.push_back(arr[i]);
    }
  }
  //  sort(ans.begin(), ans.end()); // ? weak data
  cout << ans.size();
  if (ans.empty()) {
    // F**KING PE
    cout << "\n\n";
  }
  for (int i = 0, ie = ans.size(); i < ie; ++i) {
    cout << (i == 0 ? '\n' : ' ') << ans[i];
  }
  return 0;
}
} // namespace p1101

int main() { return p1101::main(), 0; }
