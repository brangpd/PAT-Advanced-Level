
#include <bits/stdc++.h>
using namespace std;

namespace p1130 {
enum { maxn = 30 };
struct Node {
  string data;
  Node *left, *right;
};
Node nodes[maxn];
Node *root;
void printer(Node &node) { cout << node.data; }
void inorder(Node *p, function<void(Node &node)> const &act) {
  if (!p) {
    return;
  }
  bool paren = p != root && (p->left || p->right);
  if (paren) {
    cout << '(';
  }
  inorder(p->left, act);
  act(*p);
  inorder(p->right, act);
  if (paren) {
    cout << ')';
  }
}
int main() {
  int N;
  cin >> N;
  bitset<maxn> hasParent{};
  for (int i = 1; i <= N; ++i) {
    auto &node = nodes[i];
    cin >> node.data;
    int l, r;
    cin >> l >> r;
    hasParent[l] = hasParent[r] = true;
    node.left = l == -1 ? nullptr : &nodes[l];
    node.right = r == -1 ? nullptr : &nodes[r];
  }
  for (int i = 1; i <= N; ++i) {
    if (!hasParent[i]) {
      root = &nodes[i];
      break;
    }
  }
  inorder(root, &printer);
  return 0;
}
} // namespace p1130

int main() { return p1130::main(), 0; }
