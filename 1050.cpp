
#include <bits/stdc++.h>
using namespace std;

namespace p1050 {
int main() {
  string s1, s2;
  unordered_set<char> set2;
  getline(cin, s1);
  getline(cin, s2);
  for (auto c : s2) {
    set2.insert(c);
  }
  for (auto c : s1) {
    if (!set2.count(c)) {
      cout << c;
    }
  }
  cout << endl;
  return 0;
}
} // namespace p1050

int main() { return p1050::main(), 0; }
