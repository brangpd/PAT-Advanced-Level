
#include <bits/stdc++.h>
using namespace std;

namespace p1055 {
int N, K;
struct People {
  string name;
  int age;
  int worth;
  using Ptr = People *;
  static Ptr create() { return new People; }
  struct PtrComp {
    bool operator()(const Ptr &a, const Ptr &b) const {
      if (a->worth != b->worth) {
        return b->worth < a->worth;
      }
      if (a->age != b->age) {
        return a->age < b->age;
      }
      return a->name < b->name;
    }
  };
};
int main() {
  ios::sync_with_stdio(false);
  cin >> N >> K;
  vector<People::Ptr> peoples(N);
  for (int i = 0; i < N; ++i) {
    auto &p = peoples[i] = People::create();
    cin >> p->name >> p->age >> p->worth;
  }
  auto allComp = People::PtrComp();
  sort(peoples.begin(), peoples.end(), allComp);
  for (int i = 1; i <= K; ++i) {
    cout << "Case #" << i << ":\n";
    int amin, amax, M;
    cin >> M >> amin >> amax;
    int cnt{};
    for (auto &&p : peoples) {
      if (p->age >= amin && p->age <= amax) {
        ++cnt;
        --M;
        cout << p->name << ' ' << p->age << ' ' << p->worth << '\n';
        if (M == 0) {
          break;
        }
      }
    }
    if (cnt == 0) {
      cout << "None\n";
    }
  }
  return 0;
}
} // namespace p1055

int main() { return p1055::main(), 0; }
