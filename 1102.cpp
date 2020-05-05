
#include <bits/stdc++.h>
using namespace std;

namespace p1102 {
struct Node {
  Node *left, *right;
  int value;
};
enum { maxn = 15 };
Node nodes[maxn];
Node *root;
int indegree[maxn];
void inorder(Node *p, function<void(Node &)> const &act) {
  if (p != nullptr) {
    inorder(p->left, act);
    act(*p);
    inorder(p->right, act);
  }
}
void levelorder(Node *p, function<void(Node &)> const &act) {
  queue<Node *> q;
  q.push(p);
  while (!q.empty()) {
    p = q.front();
    q.pop();
    if (p != nullptr) {
      act(*p);
      q.push(p->left);
      q.push(p->right);
    }
  }
}
int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    auto *node = &nodes[i];
    node->value = i;
    string l, r;
    cin >> l >> r;
    if (l == "-") {
      node->left = nullptr;
    } else {
      int li = stoi(l);
      node->left = &nodes[li];
      ++indegree[li];
    }
    if (r == "-") {
      node->right = nullptr;
    } else {
      int ri = stoi(r);
      node->right = &nodes[ri];
      ++indegree[ri];
    }
  }
  for (int i = 0; i < N; ++i) {
    if (indegree[i] == 0) {
      root = &nodes[i];
      break;
    }
  }
  levelorder(root, [](Node &node) { swap(node.left, node.right); });
  struct Output {
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
  levelorder(root, Output());
  cout << endl;
  inorder(root, Output());
  cout << endl;

  return 0;
}
} // namespace p1102

int main() { return p1102::main(), 0; }
