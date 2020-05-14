
#include <bits/stdc++.h>
using namespace std;

namespace p1001 {
int main() {
  static_assert(__cplusplus >= 201700);
  int a, b;
  cin >> a >> b;
  a += b;
  if (a < 0) {
    cout << '-';
    a = -a;
  }
  deque<int> v;
  do {
    v.push_front(a % 1000);
    a /= 1000;
  } while (a);
  bool first{true};
  for (auto i : v) {
    if (first) {
      cout << i;
      first = false;
    } else {
      cout << ',';
      cout << setfill('0') << setw(3) << i;
    }
  }
}
} // namespace p1001

int main() { return p1001::main(), 0; }
