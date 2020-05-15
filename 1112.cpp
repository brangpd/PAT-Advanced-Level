
#include <bits/stdc++.h>
using namespace std;

namespace p1112 {
int main() {
  int k;
  string s;
  cin >> k >> s;
  bitset<1000> possible;
  possible.set();
  string detected;
  string res;
  for (int i = 0, ie = s.size(); i < ie; ++i) {
    if (s.substr(i, k) != string(k, s[i])) {
      possible[s[i]] = false;
    } else {
      i += k - 1;
    }
  }
  for (int i = 0, ie = s.size(); i < ie; ++i) {
    string dupk(k, s[i]);
    string sub = s.substr(i, k);
    if (possible[s[i]] == true && sub == dupk) {
      if (detected.find_first_of(s[i]) == string::npos) {
        detected += s[i];
      }
      i += k - 1;
    }
    res += s[i];
  }

  cout << detected << '\n' << res;
  return 0;
}
} // namespace p1112

int main() { return p1112::main(), 0; }
