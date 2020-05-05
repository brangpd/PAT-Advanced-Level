
#include <bits/stdc++.h>
using namespace std;

namespace p1092 {
int main() {
  string a, b;
  cin >> a >> b;
  map<char, int> cnt;
  for (auto c : a) {
    ++cnt[c];
  }
  for (auto c : b) {
    --cnt[c];
  }
  int negative = 0;
  int positive = 0;
  for (auto [c, n] :cnt) {
    if (n < 0) {
      negative -= n;
    } else {
      positive += n;
    }
  }
  if (negative) {
    cout << "No " << negative << endl;
  } else {
    cout << "Yes " << positive << endl;
  }
  return 0;
}
} // namespace p1092

int main() { return p1092::main(), 0; }
