
#include <bits/stdc++.h>
using namespace std;

namespace p1010 {
using ll = long long;

ll cmp(ll a, ll b) { return a - b; }
ll mystoll(const string &s, void *, ll rdx) {
  auto ctoi = [rdx](char c) {
    int res;
    if (isdigit(c)) {
      res = c - '0';
    } else {
      res = c - 'a' + 10;
    }
    return res < rdx ? res : throw "";
  };
  ll res{};
  for (auto c : s) {
    res *= rdx;
    res += ctoi(c);
  }
  return res;
}

string n[3];
ll tag, taganother;
ll radix;
int main() {
  cin >> n[1] >> n[2] >> tag >> radix;
  taganother = 3 - tag;
  if (n[tag] == "0" && n[taganother] == "0") {
    cout << 1;
    return 0;
  }
  if (n[tag] == "0" || n[taganother] == "0") {
    cout << "Impossible";
    return 0;
  }
  ll tagint = mystoll(n[tag], nullptr, radix);
  ll prevCmp = 0;
  for (int i = 1;; ++i) {
    try {
      auto res = mystoll(n[taganother], nullptr, i);
      if (res > 10000000000) {
        break;
      }
      auto resCmp = cmp(res, tagint);
      if (resCmp == 0) {
        cout << i;
        return 0;
      } else {
        if (resCmp <= prevCmp && prevCmp < 0) {
          break;
        }
        if (resCmp >= prevCmp && prevCmp > 0) {
          break;
        }
      }
      prevCmp = resCmp;
    } catch (...) {
    }
  }
  cout << "Impossible";
  return 0;
}
} // namespace p1010

int main() { return p1010::main(), 0; }
