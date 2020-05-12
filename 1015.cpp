
#include <bits/stdc++.h>
using namespace std;

namespace p1015 {
int64_t N, D;
bool prime(int64_t n) {
  if (n == 1) {
    return false;
  }
  for (int64_t i = 2, ie = sqrt(n); i <= ie; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
int64_t reverse(int64_t n, int64_t radix) {
  string represent;
  while (n) {
    represent += n % radix + '0';
    n /= radix;
  }
  return stoi(represent, nullptr, radix);
}
int main() {
  while (cin >> N && N >= 0) {
    cin >> D;
    cout << (prime(N) && prime(reverse(N, D)) ? "Yes" : "No") << endl;
  }
  return 0;
}
} // namespace p1015

int main() { return p1015::main(), 0; }
