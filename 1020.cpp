
#include <bits/stdc++.h>
using namespace std;

namespace p1020 {
int N;
int postorder[50];
int inorder[50];
struct Node {
  int i;
  Node *left, *right;
};
Node *newNode() { return new Node; }
Node *build(int *postbegin, int *postend, int *inbegin, int *inend) {
  if (postbegin == postend) {
    return nullptr;
  }
  int rootv = postend[-1];
  Node *root = newNode();
  root->i = rootv;
  for (auto it = inbegin; it != inend; ++it) {
    if (rootv == *it) {
      auto ldis = it - inbegin;
      root->left = build(postbegin, postbegin + ldis, inbegin, it);
      root->right = build(postbegin + ldis, postend - 1, it + 1, inend);
    }
  }
  return root;
}
void level(Node *root, void (*act)(Node &)) {
  queue<Node *> nodes;
  nodes.push(root);
  while (!nodes.empty()) {
    auto p = nodes.front();
    nodes.pop();
    act(*p);
    if (p->left) {
      nodes.push(p->left);
    }
    if (p->right) {
      nodes.push(p->right);
    }
  }
}
int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> postorder[i];
  }
  for (int i = 0; i < N; ++i) {
    cin >> inorder[i];
  }
  Node *root = build(postorder, postorder + N, inorder, inorder + N);
  level(root, [](Node &node) {
    static bool first = true;
    if (first) {
      first = false;
    } else {
      cout << ' ';
    }
    cout << node.i;
  });
  return 0;
}
} // namespace p1020

int main() { return p1020::main(), 0; }
