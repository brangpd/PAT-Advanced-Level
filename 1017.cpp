
#include <bits/stdc++.h>
using namespace std;

namespace p1017 {
int N;
int K;
enum { maxn = 10000 + 10 };
unordered_set<int> serving;
using dur = chrono::seconds;
struct Customer {
  dur arrive;
  dur P;
  dur starting;
};
Customer customers[maxn];
dur beginning = chrono::hours(8), ending = chrono::hours(17);
dur toDur(const string &time) {
  using namespace chrono;
  istringstream iss(time);
  int h, m, s;
  char c;
  iss >> h >> c >> m >> c >> s;
  return hours(h) + minutes(m) + seconds(s);
}
int main() {
  using namespace chrono;
  cin >> N >> K;
  for (int i = 1; i <= N; ++i) {
    string time;
    int P;
    cin >> time >> P;
    auto &c = customers[i];
    c.arrive = toDur(time);
    c.P = minutes(P);
  }
  auto cit = customers + 1, cite = customers + 1 + N;
  sort(cit, cite, [](Customer const &a, Customer const &b) {
    return a.arrive < b.arrive;
  });
  int id = 1;
  for (auto t = beginning;; t += seconds(1)) {
    vector<int> toRemove;
    for (auto i : serving) {
      auto &c = customers[i];
      if (c.starting + c.P == t) {
        toRemove.push_back(i);
      }
    }
    for (auto i : toRemove) {
      serving.erase(i);
    }
    if (id > N) {
      break;
    }
    if (customers[id].arrive > ending) {
      break;
    }
    while (id <= N && customers[id].arrive <= t && serving.size() != K) {
      serving.insert(id);
      customers[id].starting = t;
      ++id;
    }
  }
  dur final{};
  int num = id - 1;
  for (int i = 1; i < id; ++i) {
    auto &c = customers[i];
    final += c.starting - c.arrive;
  }
  using fpMinutes = duration<double, minutes::period>;
  cout << fixed << setprecision(1) << fpMinutes(final).count() / num << endl;
  return 0;
}
} // namespace p1017

int main() { return p1017::main(), 0; }
