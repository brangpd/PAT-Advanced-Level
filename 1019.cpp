
#include <bits/stdc++.h>
using namespace std;

namespace p1019 {
int64_t N, b;
vector<string> result;
void translate() {
  while (N) {
    if (!result.empty()) {
      result.push_back(" ");
    }
    result.push_back(to_string(N % b));
    N /= b;
  }
}
bool palindromic() {
  auto &a = result;
  for (size_t i = 0, j = a.size() - 1; i < j; ++i, --j) {
    if (a[i] != a[j]) {
      return false;
    }
  }
  return true;
}
int main() {
  cin >> N >> b;
  translate();
  cout << (palindromic() ? "Yes\n" : "No\n");
  copy(result.rbegin(), result.rend(), ostream_iterator<string>(cout));
  return 0;
}
} // namespace p1019

int main() { return p1019::main(), 0; }
