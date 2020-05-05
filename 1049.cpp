
#include <bits/stdc++.h>
using namespace std;

namespace p1049 {
enum { maxn = 20 };
char num[maxn];
int len;
int d[maxn /*idx*/][2 /*limited*/][maxn /*previous1s*/];
int search(int idx, bool limited, int previous1s) {
  int &cnt = d[idx][limited][previous1s];
  if (cnt != -1) {
    return cnt;
  }
  if (idx >= len) {
    return cnt = previous1s;
  }
  char cur = num[idx];
  cnt = 0;
  for (char c = '0', upper = limited ? cur : '9'; c <= upper; ++c) {
    bool cur1 = c == '1';
    bool nextlimited = limited && cur == c;
    cnt += search(idx + 1, nextlimited, previous1s + cur1);
  }
  return cnt;
}
int main() {
  cin >> &num[1];
  num[0] = '0';
  len = strlen(num);
  memset(d, -1, sizeof d);
  cout << search(0, true, 0) << endl;
  return 0;
}
} // namespace p1049

int main() { return p1049::main(), 0; }
