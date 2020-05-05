
#include <bits/stdc++.h>
using namespace std;

namespace p1051 {
int M, N, K;
int main() {
  ios::sync_with_stdio(false);
  cin >> M >> N >> K;
  cin.ignore();
  while (K--) {
    stack<int> stk;
    string line;
    getline(cin, line);
    istringstream iss(line);
    auto it = istream_iterator<int>(iss), ite = istream_iterator<int>();
    int minimum = 1;
    while (it != ite) {
      stk.push(minimum++);
      if (stk.size() > M) {
        goto L_fail;
      }
      while (!stk.empty() && *it == stk.top()) {
        stk.pop();
        ++it;
      }
    }
    if (stk.empty()) {
      goto L_success;
    }
  L_fail:
    cout << "NO\n";
    continue;
  L_success:
    cout << "YES\n";
    continue;
  }
  return 0;
}
} // namespace p1051

int main() { return p1051::main(), 0; }
