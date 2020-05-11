
#include <bits/stdc++.h>
using namespace std;

namespace p1065 {
using int128_t = __int128;
istream &operator>>(istream &is, int128_t &i) {
  string s;
  is >> s;
  bool negative = false;

  if (s[0] == '-') {
    negative = true;
  }
  i = 0;
  for (auto it = s.rbegin(); it != s.rend() && *it != '-'; ++it) {
    i *= 10;
    i += *it - '0';
  }
  if (negative) {
    i = -i;
  }

  return is;
}
int main() {
  int T;
  cin >> T;
  for (int k = 1; k <= T; ++k) {
    int128_t a, b, c;
    cin >> a >> b >> c;
    cout << "Case #" << k << ": " << boolalpha << (a + b > c) << '\n';
  }
  return 0;
}
} // namespace p1065

int main() { return p1065::main(), 0; }
