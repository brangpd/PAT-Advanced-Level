
#include <bits/stdc++.h>
using namespace std;

namespace p1028 {
struct Record {
  string id;
  string name;
  int score;
};
int main() {
  int N, C;
  cin >> N >> C;
  vector<Record> rec(N);
  for (auto &r : rec) {
    cin >> r.id >> r.name >> r.score;
  }
  sort(begin(rec), end(rec), [C](Record const &a, Record const &b) {
    enum { ID = 1, NAME = 2, SCORE = 3 };
    switch (C) {
    case ID:
      return a.id < b.id;
    case NAME:
      return a.name == b.name ? a.id < b.id : a.name < b.name;
    case SCORE:
      return a.score == b.score ? a.id < b.id : a.score < b.score;
    default:
      throw;
    }
  });
  for (auto &r : rec) {
    cout << r.id << ' ' << r.name << ' ' << r.score << '\n';
  }
  return 0;
}
} // namespace p1028

int main() { return p1028::main(), 0; }
