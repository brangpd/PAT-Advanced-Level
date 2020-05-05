
#include <bits/stdc++.h>
using namespace std;

namespace p1052 {
using addr_t = int;
struct Node {
  addr_t addr;
  int key;
  Node *next;
};
int N;
Node *nodeAt(addr_t addr) {
  static Node m[100000 + 5];
  if (addr == -1) {
    return nullptr;
  }
  return &m[addr];
}
addr_t rootaddr;
Node *root;
const char *toaddr(addr_t addr) {
  static char buf[10];
  if (addr == -1) {
    return "-1";
  }
  sprintf(buf, "%05d", addr);
  return buf;
}
int main() {
  cin >> N;
  cin >> rootaddr;
  root = nodeAt(rootaddr);
  for (int i = 0; i < N; ++i) {
    addr_t addr;
    cin >> addr;
    auto node = nodeAt(addr);
    node->addr = addr;
    cin >> node->key;
    addr_t next;
    cin >> next;
    node->next = nodeAt(next);
  }

  vector<Node *> vec;
  for (auto node = root; node; node = node->next) {
    vec.push_back(node);
  }
  sort(vec.begin(), vec.end(),
       [](Node *a, Node *b) { return a->key < b->key; });
  // this F**KING problem allows given nodes to be absent in the linked list.
  // (you happy OK)
  // assert(vec.size() == N);
  if (vec.empty()) {
    cout << "0 -1\n";
    exit(0);
  }

  auto it1 = vec.begin();
  auto it2 = it1 + 1;
  while (it2 != vec.end()) {
    (**it1).next = (*it2);
    ++it1;
    ++it2;
  }
  vec.back()->next = nullptr;

  cout << vec.size() << ' ' << toaddr(vec.front()->addr) << '\n';
  for (auto node : vec) {
    cout << toaddr(node->addr) << ' ' << node->key << ' ';
    if (node->next) {
      cout << toaddr(node->next->addr);
    } else {
      cout << "-1";
    }
    cout << '\n';
  }
  return 0;
}
} // namespace p1052

int main() { return p1052::main(), 0; }
