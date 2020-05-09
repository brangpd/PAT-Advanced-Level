
#include <bits/stdc++.h>
using namespace std;

namespace p1116 {
bool isPrime(int n) {
  for (int i = 2, ie = sqrt(n); i <= ie; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  int N, K;
  enum { maxn = 10000 + 5 };
  cin >> N;
  map<int, int> rank;
  for (int i = 0; i < N; ++i) {
    int id;
    cin >> id;
    rank[id] = i + 1;
  }
  cin >> K;
  bitset<maxn> checked{};
  for (int i = 0; i < K; ++i) {
    int id;
    cin >> id;
    cout << setfill('0') << setw(4) << id << ": ";
    if (checked[id]) {
      cout << "Checked\n";
      continue;
    }
    auto it = rank.find(id);
    if (it == rank.end()) {
      cout << "Are you kidding?\n";
      continue;
    }
    checked[id] = true;
    if (it->second == 1) {
      cout << "Mystery Award\n";
      continue;
    }
    if (isPrime(it->second)) {
      cout << "Minion\n";
      continue;
    }
    cout << "Chocolate\n";
  }
  return 0;
}
} // namespace p1116

int main() { return p1116::main(), 0; }
