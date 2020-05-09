
#include <bits/stdc++.h>
using namespace std;

namespace p1127 {
int N;
enum { maxn = 35 };
int inorder[maxn];
int postorder[maxn];
using it_t = int *;
struct Node {
  Node *left, *right;
  int value;
  static Node *create() {
    static Node nodes[maxn];
    static Node *cur = nodes;
    return cur++;
  }
};
Node *build(it_t init, it_t inite, it_t postit, it_t postite) {
  if (init == inite) {
    return nullptr;
  }
  Node *node = Node::create();
  node->value = postite[-1];
  for (auto it = init; it != inite; ++it) {
    auto dis = it - init;
    if (*it == node->value) {
      node->left = build(init, it, postit, postit + dis);
      node->right = build(it + 1, inite, postit + dis, postite - 1);
      break;
    }
  }
  return node;
}
void zigzag(Node *p, function<void(Node &)> const &act) {
  enum { ZIG, ZAG, INITFLAG = ZIG } flag = INITFLAG;
  stack<Node *> stk[2];
  stk[INITFLAG].push(p);
  while (!stk[flag].empty()) {
    if (flag == ZIG) {
      while (!stk[ZIG].empty()) {
        p = stk[ZIG].top();
        stk[ZIG].pop();
        if (p) {
          stk[ZAG].push(p->right);
          stk[ZAG].push(p->left);
          act(*p);
        }
      }
    } else {
      while (!stk[ZAG].empty()) {
        p = stk[ZAG].top();
        stk[ZAG].pop();
        if (p) {
          stk[ZIG].push(p->left);
          stk[ZIG].push(p->right);
          act(*p);
        }
      }
    }
    flag = flag == ZIG ? ZAG : ZIG;
  }
}
int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> inorder[i];
  }
  for (int i = 0; i < N; ++i) {
    cin >> postorder[i];
  }
  auto root = build(inorder, inorder + N, postorder, postorder + N);
  struct Printer {
    bool first = true;
    void operator()(Node &node) {
      if (first) {
        first = false;
      } else {
        cout << ' ';
      }
      cout << node.value;
    }
  };
  zigzag(root, Printer());
  return 0;
}
} // namespace p1127

int main() { return p1127::main(), 0; }
