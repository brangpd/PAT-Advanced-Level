
#include <bits/stdc++.h>
using namespace std;

namespace p1039 {
int main() {
  ios::sync_with_stdio(false);
  int N, K;
  cin >> N >> K;
  unordered_map<string, vector<int>> table;
  string name;
  for (int j = 0; j < K; ++j) {
    int i, ni;
    cin >> i >> ni;
    for (int k = 0; k < ni; ++k) {
      cin >> name;
      table[name].push_back(i);
    }
  }
  for (int j = 0; j < N; ++j) {
    cin >> name;
    cout << name << ' ' << table[name].size();
    auto &tb = table[name];
    sort(tb.begin(), tb.end());
    for (auto &elem : tb) {
      cout << ' ' << elem;
    }
    cout << '\n';
  }
  return 0;
}
} // namespace p1039

int main() { return p1039::main(), 0; }
