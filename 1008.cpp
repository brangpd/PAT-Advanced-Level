
#include <bits/stdc++.h>
using namespace std;

namespace p1008 {
int main() {
  int n;
  cin >> n;
  int cur = 0;
  int sum = 0;
  while (n--) {
    int a;
    cin >> a;
    if (cur != a) {
      sum += (cur < a ? 6 : 4) * abs(cur - a);
    }
    cur = a;
    sum += 5;
  }
  cout << sum;

  return 0;
}
} // namespace p1008

int main() { return p1008::main(), 0; }
