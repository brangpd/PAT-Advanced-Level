
#include <bits/stdc++.h>
using namespace std;

namespace p1047 {
int main() {
  ios::sync_with_stdio(false);
  int N, K;
  cin >> N >> K;
  struct Comp {
    bool operator()(const shared_ptr<string> &a, const shared_ptr<string> &b) {
      return *a < *b;
    }
  };
  vector<vector<shared_ptr<string>>> table(K + 1);
  for (int i = 0; i < N; ++i) {
    auto pname = make_shared<string>();
    cin >> *pname;
    int n;
    cin >> n;
    while (n--) {
      int id;
      cin >> id;
      table[id].push_back(pname);
    }
  }
  for (int i = 1; i <= K; ++i) {
    auto &rec = table[i];
    cout << i << ' ' << rec.size() << '\n';
    sort(rec.begin(), rec.end(), Comp());
    for (auto &&pname : rec) {
      cout << *pname << '\n';
    }
  }
  return 0;
}
} // namespace p1047

int main() { return p1047::main(), 0; }
