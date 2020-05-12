
#include <bits/stdc++.h>
using namespace std;

namespace p1014 {
using my_time_point = chrono::minutes;
enum { maxk = 1005 };
enum { maxn = 25 };
int N, M, K, Q;
my_time_point length[maxk], beginAt[maxk];
bitset<maxk> sorry;
queue<int> outWaiting;
vector<queue<int>> inWaitings;
my_time_point beginning(chrono::hours(8)), ending(chrono::hours(17));
int main() {
  using namespace chrono;
  cin >> N >> M >> K >> Q;
  inWaitings.resize(N);
  for (int i = 1; i <= K; ++i) {
    int len;
    cin >> len;
    length[i] = minutes(len);
    outWaiting.push(i);
  }
  sorry.set();
  // This F**KING problem allows all customers coming BEFORE 17:00 to be served,
  // finishing the transaction after 17:00 is also accepted.
  for (auto t = beginning; t < ending; t += minutes(1)) {
    for (auto &&in : inWaitings) {
      if (!in.empty()) {
        auto id = in.front();
        if (beginAt[id] + length[id] == t) {
          in.pop();
          if (!in.empty()) {
            id = in.front();
            beginAt[id] = t;
            sorry[id] = false;
          }
        }
      }
    }
    while (!outWaiting.empty()) {
      auto it = min_element(inWaitings.begin(), inWaitings.end(),
                            [](queue<int> const &a, queue<int> const &b) {
                              return a.size() < b.size();
                            });
      if (it->size() == M) {
        break;
      }
      auto id = outWaiting.front();
      outWaiting.pop();
      it->push(id);
      if (it->size() == 1) {
        beginAt[id] = t;
        sorry[id] = false;
      }
    }
  }
  for (int i = 0; i < Q; ++i) {
    int id;
    cin >> id;
    if (sorry[id]) {
      cout << "Sorry\n";
    } else {
      auto t = beginAt[id] + length[id];
      auto h = duration_cast<hours>(t).count();
      auto min = duration_cast<minutes>(t).count() % 60;
      cout << setw(2) << setfill('0') << h << ':' << setw(2) << setfill('0')
           << min << '\n';
    }
  }
  return 0;
}
} // namespace p1014

int main() { return p1014::main(), 0; }
