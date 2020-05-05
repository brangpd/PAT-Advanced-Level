
#include <bits/stdc++.h>
using namespace std;

namespace p1096 {
uint64_t N;
struct Ans {
  uint64_t lefti, len;
};
bool operator<(const Ans &a, const Ans &b) {
  if (a.len != b.len) {
    return a.len > b.len;
  }
  return a.lefti < b.lefti;
}
vector<Ans> ans;
int main() {
  cin >> N;
  ans.push_back({N, 1});
  uint64_t i = 2, j = 3, end = sqrt(N) + 1;
  uint64_t product = 2;
L_begin:
  while (j <= end) {
    while (i < j && N % product != 0) {
      product /= i++;
      if (i == j) {
        product *= j++;
        goto L_begin;
      }
    }
    while (j <= end && N % (product * j) == 0) {
      product *= j++;
    }
    ans.push_back({i, j - i});
    product /= i++;
    product *= j++;
  }

  sort(ans.begin(), ans.end());
  auto final = ans.front();
  cout << final.len << endl;
  bool first = true;
  for (auto i = final.lefti, ie = final.lefti + final.len; i < ie; ++i) {
    if (first) {
      first = false;
    } else {
      cout << '*';
    }
    cout << i;
  }

  return 0;
}
} // namespace p1096

int main() { return p1096::main(), 0; }
