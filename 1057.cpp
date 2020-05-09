
#include <bits/stdc++.h>
using namespace std;

namespace p1057 {
struct Stack {
  void adjust() {
    if (stk.size() >= 2) {
      while (true) {
        auto itg = setg.begin();
        auto itl = setl.begin();
        auto vg = *itg;
        auto vl = *itl;
        if (vg > vl) {
          setg.erase(itg);
          setl.erase(itl);
          setg.insert(vl);
          setl.insert(vg);
        } else {
          break;
        }
      }
    }
  }
  bool pop(int &k) {
    decltype(setg)::iterator it;
    if (stk.empty()) {
      return false;
    }
    k = stk.top();
    stk.pop();
    it = setg.find(k);
    if (it != setg.end()) {
      setg.erase(it);
    } else {
      it = setl.find(k);
      if (it != setl.end()) {
        setl.erase(it);
      }
    }
    adjust();
    return true;
  }
  bool peek(int &k) {
    if (!setg.empty()) {
      k = *setg.begin();
      return true;
    }
    return false;
  }
  void push(int k) {
    stk.push(k);
    if (stk.size() == 1) {
      setg.insert(k);
      return;
    }
    if (stk.size() % 2 == 1) {

    } else {

    }
    if (setg.size() == setl.size()) {
      setg.insert(k);
    } else {
      setl.insert(k);
    }
    if (setg.size() < setl.size()) {
      auto it = setl.begin();
      setg.insert(*it);
      setl.erase(it);
    }
  }
  stack<int, vector<int>> stk;
  multiset<int, greater<int>> setg; // smaller
  multiset<int, less<int>> setl;    // bigger
};
int main() {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  string op;
  Stack stk;
  while (N--) {
    cin >> op;
    int k;
    if (op[1] == 'u') {
      cin >> k;
      stk.push(k);
    } else if (op[1] == 'o') {
      if (stk.pop(k)) {
        cout << k << '\n';
      } else {
        cout << "Invalid\n";
      }
    } else {
      if (stk.peek(k)) {
        cout << k << '\n';
      } else {
        cout << "Invalid\n";
      }
    }
  }
  return 0;
}
} // namespace p1057

int main() { return p1057::main(), 0; }
