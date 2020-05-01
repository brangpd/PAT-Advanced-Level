
#include <bits/stdc++.h>
using namespace std;

namespace p1007 {
int K;
enum { maxk = 10005 };
int a[maxk];
enum { dSum, dLeft };
enum { ninf = numeric_limits<int>::min() / 2 };
int d[maxk][3];
int main() {
  cin >> K;
  for (int i = 1; i <= K; ++i) {
    cin >> a[i];
  }
  d[0][dSum] = ninf;
  d[0][dLeft] = 1;
  for (int i = 1; i <= K; ++i) {
    if (d[i - 1][dSum] >= 0) {
      d[i][dSum] = d[i - 1][dSum] + a[i];
      d[i][dLeft] = d[i - 1][dLeft];
    } else {
      d[i][dSum] = a[i];
      d[i][dLeft] = i;
    }
  }
  int anssum = -1, ansleft = 1, ansright = K;
  for (int i = 1; i <= K; ++i) {
    if (d[i][dSum] > anssum) {
      anssum = d[i][dSum];
      ansleft = d[i][dLeft];
      ansright = i;
    }
  }
  cout << (anssum == -1 ? 0 : anssum) << ' ' << a[ansleft] << ' ' << a[ansright]
       << endl;
  return 0;
}
} // namespace p1007

int main() { return p1007::main(), 0; }
