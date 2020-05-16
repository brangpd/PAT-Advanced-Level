
#include <bits/stdc++.h>
using namespace std;

namespace p1067 {
int main() {
  int N;
  cin >> N;
  vector<int> arr(N);
  vector<int> pos(N);
  unordered_set<int> unordered;
  int cnt{};
  auto swap0 = [&arr, &pos, &cnt](int with) {
    swap(arr[pos[0]], arr[pos[with]]);
    swap(pos[0], pos[with]);
    ++cnt;
  };
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    pos[arr[i]] = i;
    if (arr[i] != i && arr[i] != 0) {
      unordered.insert(arr[i]);
    }
  }
  while (!unordered.empty()) {
    if (pos[0] == 0) {
      auto it = unordered.begin();
      auto v = *it;
      unordered.erase(it);
      swap0(v);
    }
    while (pos[0] != 0) {
      unordered.erase(pos[0]);
      swap0(pos[0]);
    }
  }
  cout << cnt;
  return 0;
}
} // namespace p1067

int main() { return p1067::main(), 0; }
