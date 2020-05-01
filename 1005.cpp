
#include <bits/stdc++.h>
using namespace std;

namespace p1005 {
int main() {
  string s;
  cin >> s;
  string nums[] = {
      "zero", "one", "two",   "three", "four",
      "five", "six", "seven", "eight", "nine",
  };
  uint64_t sum{};
  for (auto c : s) {
    sum += c - '0';
  }
  bool first{true};
  for (auto c : to_string(sum)) {
    if (!first) {
      cout << ' ';
    }
    first = false;
    cout << nums[c - '0'];
  }

  return 0;
}
} // namespace p1005

int main() { return p1005::main(), 0; }
