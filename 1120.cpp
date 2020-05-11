
#include <bits/stdc++.h>
using namespace std;

namespace p1120 {
int N;
vector<string> inputs;
map<int /*id*/, int /*times*/> ids;
int toId(const string &str) {
  int res{};
  for (auto &&c : str) {
    res += c - '0';
  }
  return res;
}
struct Printer {
  bool first = true;
  void operator()(int v) {
    if (first) {
      first = false;
    } else {
      cout << ' ';
    }
    cout << v;
  }
};
int main() {
  cin >> N;
  inputs.resize(N);
  for (auto &input : inputs) {
    cin >> input;
  }
  for (auto &&id : inputs) {
    ids[toId(id)];
  }
  cout << ids.size() << '\n';
  Printer printer;
  for (auto &&[id, times] : ids) {
    printer(id);
  }
  return 0;
}
} // namespace p1120

int main() { return p1120::main(), 0; }
