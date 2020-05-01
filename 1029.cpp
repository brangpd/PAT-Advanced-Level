
#include <bits/stdc++.h>
using namespace std;

namespace p1029 {
int main() {
  ios::sync_with_stdio(false);
  int N1;
  cin >> N1;
  vector<long> seq1(N1);
  for (auto &n : seq1) {
    cin >> n;
  }
  int N2;
  cin >> N2;
  vector<long> seq2(N2);
  for (auto &n : seq2) {
    cin >> n;
  }
  vector<long> final;
  merge(seq1.begin(), seq1.end(), seq2.begin(), seq2.end(),
        back_inserter(final));
  cout << final[(final.size() - 1) / 2] << '\n';
  return 0;
}
} // namespace p1029

int main() { return p1029::main(), 0; }
