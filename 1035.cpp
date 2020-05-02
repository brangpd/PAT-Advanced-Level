
#include <bits/stdc++.h>
using namespace std;

namespace p1035 {
struct Team {
  string name;
  string pass;
};
bool modify(string &pass) {
  bool changed = false;
  for (auto &c : pass) {
    switch (c) {
    case '1':
      c = '@';
      break;
    case '0':
      c = '%';
      break;
    case 'l':
      c = 'L';
      break;
    case 'O':
      c = 'o';
      break;
    default:
      continue;
    }
    changed = true;
  }
  return changed;
}
int main() {
  int N;
  cin >> N;
  vector<Team> teams(N);
  vector<Team> output;
  for (int i = 0; i < N; ++i) {
    auto &team = teams[i];
    cin >> team.name >> team.pass;
    if (modify(team.pass)) {
      output.push_back(team);
    }
  }
  if (output.empty()) {
    if (N == 1) {
      cout << "There is 1 account ";
    } else {
      cout << "There are " << N << " accounts ";
    }
    cout << "and no account is modified\n";
  } else {
    cout << output.size() << '\n';
    for (auto &elem : output) {
      cout << elem.name << ' ' << elem.pass << '\n';
    }
  }
  return 0;
}
} // namespace p1035

int main() { return p1035::main(), 0; }
