
#include <bits/stdc++.h>
using namespace std;

namespace p1132 {
int main() {
  int N;
  cin >> N;
  auto check = [](int64_t n, int64_t n1, int64_t n2) {
    auto tmp = n1 * n2;
    return tmp && n % tmp == 0;
  };
  while (N--) {
    string num;
    cin >> num;
    auto num1 = num.substr(0, num.size() / 2),
         num2 = num.substr(num.size() / 2);
    auto n = stoll(num), n1 = stoll(num1), n2 = stoll(num2);
    cout << (check(n, n1, n2) ? "Yes\n" : "No\n");
  }
  return 0;
}
} // namespace p1132

int main() { return p1132::main(), 0; }
