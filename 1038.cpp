
#include <bits/stdc++.h>
using namespace std;

namespace p1038 {
struct Comp {
  bool operator()(const string &na, const string &nb) const {
    static string s[2];
    s[0] = na + nb;
    s[1] = nb + na;
    return s[0] < s[1];
  }
};
int main() {
  int N;
  cin >> N;
  vector<string> inputs(N);
  for (int i = 0; i < N; ++i) {
    cin >> inputs[i];
  }
  sort(inputs.begin(), inputs.end(), Comp());
  string output;
  for (auto &num : inputs) {
    if (output.empty()) {
      auto it = num.begin();
      while (it != num.end() && *it == '0') {
        ++it;
      }
      while (it != num.end()) {
        output += *it++;
      }
    } else {
      output += num;
    }
  }
  if (output.empty()) {
    cout << "0\n";
  } else {
    cout << output;
  }
  return 0;
}
} // namespace p1038

int main() { return p1038::main(), 0; }
