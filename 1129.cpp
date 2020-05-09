
#include <bits/stdc++.h>
using namespace std;

namespace p1129 {
enum { maxn = 50000 + 10 };
int K, N;
int seq[maxn];
struct Item {
  int id;
  int times;
  using Ptr = Item *;
  struct PtrComp {
    bool operator()(const Ptr &a, const Ptr &b) const {
      return a->times != b->times ? a->times > b->times : a->id < b->id;
    }
  };
};
Item items[maxn];
set<Item::Ptr, Item::PtrComp> itemset;
int main() {
  ios::sync_with_stdio(false);
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    auto &id = seq[i];
    cin >> id;
    items[id].id = id;
  }
  for (int i = 0; i < N; ++i) {
    auto id = seq[i];
    if (i) {
      cout << id << ':';
      int cnt{};
      auto it = itemset.begin(), ite = itemset.end();
      while (it != ite && cnt++ < K) {
        cout << ' ' << (**it++).id;
      }
      cout << '\n';
    }
    auto pitem = &items[id];
    auto it = itemset.find(pitem);
    if (it != itemset.end()) {
      itemset.erase(it);
    }
    ++pitem->times;
    itemset.insert(pitem);
  }
  return 0;
}
} // namespace p1129

int main() { return p1129::main(), 0; }
