
#include <bits/stdc++.h>
using namespace std;

namespace p1041 {
int main() {
  int N;
  cin >> N;
  vector<int> arr(N);
  map<int, int> cnt;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    ++cnt[arr[i]];
  }
  for (int i = 0; i < N; ++i) {
    if (cnt[arr[i]] == 1) {
      cout << arr[i] << endl;
      return 0;
    }
  }
  cout << "None\n";
  return 0;
}
} // namespace p1041

int main() { return p1041::main(), 0; }
