
#include <bits/stdc++.h>
using namespace std;

namespace p1027 {
int main() {
  const char *table = "0123456789ABC";
  cout << '#';
  for (int i = 0; i < 3; ++i) {
    int color;
    cin >> color;
    string color13;
    color13 += table[color / 13];
    color13 += table[color % 13];
    cout << color13;
  }
  return 0;
}
} // namespace p1027

int main() { return p1027::main(), 0; }
