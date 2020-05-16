
#include <bits/stdc++.h>
using namespace std;

namespace p1066 {
struct AVL {
  struct Node {
    using Ptr = shared_ptr<Node>;
    Ptr left = nullptr, right = nullptr;
    int value;
    int height;
    static Ptr create() { return make_shared<Node>(); }
  };
  using node_t = Node::Ptr;
  node_t _r{};
  node_t root() { return _r; }
  void insert(int value) { insert(_r, value); }
  void insert(node_t &parent, int value) {
    if (parent == nullptr) {
      parent = Node::create();
      parent->value = value;
      updateheight(parent);
      return;
    }
    if (value < parent->value) {
      insert(parent->left, value);
      if (deltaheight(parent->left, parent->right) == 2) {
        if (auto dh = deltaheight(parent->left->left, parent->left->right)) {
          if (dh == -1) {
            zag(parent->left);
          }
          zig(parent);
        }
      }
    } else {
      insert(parent->right, value);
      if (deltaheight(parent->left, parent->right) == -2) {
        if (auto dh = deltaheight(parent->right->left, parent->right->right)) {
          if (dh == 1) {
            zig(parent->right);
          }
          zag(parent);
        }
      }
    }
    updateheight(parent);
  }
  int deltaheight(node_t l, node_t r) { return (height(l) - height(r)); }
  int height(node_t node) { return node ? node->height : 0; }
  void updateheight(node_t &node) {
    node->height = max(height(node->left), height(node->right)) + 1;
  }
  void zig(node_t &node) {
    auto p = node;    // to be the right child
    auto q = p->left; // to be the root
    node = q;
    p->left = q->right;
    q->right = p;
    updateheight(p);
    updateheight(q);
  }
  void zag(node_t &node) {
    auto p = node;     // to be the left child
    auto q = p->right; // to be the root
    node = q;
    p->right = q->left;
    q->left = p;
    updateheight(p);
    updateheight(q);
  }
};
int main() {
  int N;
  AVL avl;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int v;
    cin >> v;
    avl.insert(v);
  }
  cout << avl.root()->value << endl;
  return 0;
}
} // namespace p1066

int main() { return p1066::main(), 0; }
