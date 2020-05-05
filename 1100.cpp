
#include <bits/stdc++.h>
using namespace std;

namespace p1100 {
enum { low, high };
vector<string> m[2] = {{"", "jan", "feb", "mar", "apr", "may", "jun", "jly",
                        "aug", "sep", "oct", "nov", "dec"},
                       {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei",
                        "elo", "syy", "lok", "mer", "jou"}};
int tomars(int n) {}
int frommars(int n) {

}
void tomars(string &line) {}
void frommars(string &line) {
  istringstream iss(line);
  string tmp[2];
  iss >> tmp[0];
  if (iss >> tmp[1]) {
    auto lowit = find(m[low].begin(), m[low].end(), tmp[1]);
    auto highit = find(m[high].begin(), m[high].end(), tmp[0]);
    auto res = (highit - m[high].begin()) * 10 + (lowit - m[low].begin());
    cout << frommars(res) << endl;
  } else {
    auto lowit = find(m[low].begin(), m[low].end(), tmp[0]);
    auto res = lowit - m[low].begin();
    cout << frommars(res) << endl;
  }
}
int main() {
  int N;
  cin >> N;
  while (N--) {
    string line;
    getline(cin, line);
    if (isdigit(line[0])) {
      tomars(line);
    } else {
      frommars(line);
    }
  }
  return 0;
}
} // namespace p1100

int main() { return p1100::main(), 0; }
