
#include <bits/stdc++.h>
using namespace std;

namespace p1059 {
int main() {
  long N;
  cin >> N;
  cout << N << '=';
  map<long, long> cnt;
  for (long i = 2, ie = (long)sqrt(N); i <= ie; ++i) {
    while (N % i == 0) {
      ++cnt[i];
      N /= i;
    }
  }
  if (cnt.empty() || N != 1) {
    ++cnt[N];
  }
  bool first = true;
  for (auto &ent : cnt) {
    if (first) {
      first = false;
    } else {
      cout << '*';
    }
    cout << ent.first;
    if (ent.second > 1) {
      cout << '^' << ent.second;
    }
  }
  return 0;
}
} // namespace p1059

int main() { return p1059::main(), 0; }
