
#include <bits/stdc++.h>
using namespace std;

namespace p1082 {
const char *singles[] = {"ling", "yi",  "er", "san", "si",
                         "wu",   "liu", "qi", "ba",  "jiu"};
const char *bases[] = {"", "Wan", "Yi"};
const char *base4s[] = {"", "Shi", "Bai", "Qian"};
string toChineseGroup(long n) {
  vector<string> ans;
  string res;
  long divider = 1000;
  auto it = __make_reverse_iterator(end(base4s));
  bool zeros = false;
  while (divider) {
    if (auto m = n / divider) {
      if (zeros) {
        ans.push_back(singles[0]);
      }
      ans.push_back(singles[m]);
      ans.push_back(*it);
    } else {
      zeros = !ans.empty();
    }
    n %= divider;
    divider /= 10;
    ++it;
  }
  for (auto &&str : ans) {
    if (!str.empty()) {
      res += str;
      res += ' ';
    }
  }
  res.pop_back();
  return res;
}
string toChinese(long n) {
  if (n == 0) {
    return singles[0];
  }
  bool negative = false;
  if (n < 0) {
    n = -n;
    negative = true;
  }
  deque<long> groups; // 4 digits groups
  while (n) {
    groups.push_front(n % 10000);
    n /= 10000;
  }
  vector<string> ans;
  if (negative) {
    ans.push_back("Fu");
  }
  bool zeros = false;
  bool first = true;
  while (!groups.empty()) {
    n = groups.front();
    groups.pop_front();
    if (n == 0) {
      zeros = true;
      continue;
    }
    if (zeros || (!first && n < 1000)) {
      ans.push_back(singles[0]);
    }
    ans.push_back(toChineseGroup(n));
    ans.push_back(bases[groups.size()]);
    zeros = n % 10 == 0;
    first = false;
  }
  string res;
  for (auto &&str : ans) {
    if (!str.empty()) {
      res += str;
      res += ' ';
    }
  }
  res.pop_back();
  return res;
}
int main() {
  long n;
  cin >> n;
  cout << toChinese(n);
  return 0;
}
} // namespace p1082

int main() { return p1082::main(), 0; }
