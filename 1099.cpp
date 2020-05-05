
#include <bits/stdc++.h>
using namespace std;

namespace p1099 {
int N;
struct Node {
  Node *left, *right;
  int value;
};
int keys[105];
Node nodes[105];
Node *root = nodes;
Node *null = nodes - 1;
void inorder(Node *p, const function<void(Node &node)> &act) {
  if (p == null) {
    return;
  }
  inorder(p->left, act);
  act(*p);
  inorder(p->right, act);
}
void levelorder(Node *p, const function<void(Node &node)> &act) {
  queue<Node *> q;
  q.push(p);
  while (!q.empty()) {
    p = q.front();
    q.pop();
    if (p == null) {
      continue;
    }
    act(*p);
    q.push(p->left);
    q.push(p->right);
  }
}
int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    auto &node = nodes[i];
    int l, r;
    cin >> l >> r;
    node.left = &nodes[l];
    node.right = &nodes[r];
  }
  for (int i = 0; i < N; ++i) {
    cin >> keys[i];
  }
  sort(keys, keys + N);
  auto it = keys;
  inorder(root, [&it](Node &node) { node.value = *it++; });
  bool first = true;
  levelorder(root, [&first](Node &node) {
    if (first) {
      first = false;
    } else {
      cout << ' ';
    }
    cout << node.value;
  });
  return 0;
}
} // namespace p1099

int main() { return p1099::main(), 0; }
