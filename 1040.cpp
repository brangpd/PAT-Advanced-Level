
#include <bits/stdc++.h>
using namespace std;

namespace p1040 {
enum { PH = 0 }; // placeholder
vector<char> change(string const &s) {
  vector<char> res;
  res.reserve(s.size() * 2 + 1);
  res.push_back(PH);
  for (auto c : s) {
    res.push_back(c);
    res.push_back(PH);
  }
  return res;
}
int manacher(const vector<char> &str) {
  int right = -1;
  int mid = -1;
  vector<int> len(str.size(), 0);
  auto oor = [&](int idx) { // out of range
    return idx < 0 || idx > int(str.size());
  };
  auto extend = [&](int idx) {
    int delta = 0;
    if (idx <= right) {
      delta = len[mid * 2 - idx];
    }
    while (!oor(idx + delta + 1) && !oor(idx - delta - 1)) {
      if (str[idx + delta + 1] == str[idx - delta - 1]) {
        ++delta;
      } else {
        break;
      }
    }
    len[idx] = delta;
    if (idx + delta > right) {
      right = idx + delta;
      mid = idx;
    }
  };
  for (int i = 0, ie = str.size(); i < ie; ++i) {
    extend(i);
  }
  return *max_element(len.begin(), len.end());
}
int main() {
  string s;
  getline(cin, s);
  auto changed = change(s);
  cout << manacher(changed) << '\n';
  return 0;
}
} // namespace p1040

int main() { return p1040::main(), 0; }
