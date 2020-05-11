
#include <bits/stdc++.h>
using namespace std;

namespace p1119 {
int N;
enum { maxn = 40 };
int preorder[maxn];
int postorder[maxn];
using it_t = int *;
struct Node {
  Node *left, *right;
  int value;
  static Node *create() { return new Node; }
};
bool unique = true;
Node *tryRebuild(it_t preit, it_t preite, it_t postit, it_t postite) {
  if (preit == preite) {
    return nullptr;
  }
  auto rootv = *preit;
  auto root = Node::create();
  root->value = rootv;
  ++preit;
  --postite;
  if (preit == preite) {
    return root;
  }
  if (preit[0] == postite[-1]) {
    unique = false;
    root->left = tryRebuild(preit, preite, postit, postite);
    root->right = nullptr;
  } else {
    auto preit2 = find(preit, preite, postite[-1]);
    auto dis = preit2 - preit;
    root->left = tryRebuild(preit, preit2, postit, postit + dis);
    root->right = tryRebuild(preit2, preite, postit + dis, postite);
  }
  return root;
}
void inorder(Node *p, function<void(Node &)> const &act) {
  if (p) {
    inorder(p->left, act);
    act(*p);
    inorder(p->right, act);
  }
}
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
int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> preorder[i];
  }
  for (int i = 0; i < N; ++i) {
    cin >> postorder[i];
  }
  Node *root = tryRebuild(preorder, preorder + N, postorder, postorder + N);
  if (unique) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  inorder(root, Printer());
  cout << endl; // F**KING PE
  return 0;
}
} // namespace p1119

int main() { return p1119::main(), 0; }
