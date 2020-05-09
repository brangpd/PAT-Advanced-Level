
#include <bits/stdc++.h>
using namespace std;

namespace p1135 {
int K;
int N;
enum Color { BLACK, RED };
struct Node {
  using Ptr = shared_ptr<Node>;
  static Ptr create() { return make_shared<Node>(); }
  bool operator<(const Node &other) const { return value < other.value; }
  Color color;
  int value;
  Ptr left, right;
};
template <class It> Node::Ptr build(It it, It ite) {
  if (it == ite) {
    return nullptr;
  }
  auto root = *it++;
  auto itmid = it;
  while (itmid != ite && **itmid < *root) {
    ++itmid;
  }
  root->left = build(it, itmid);
  root->right = build(itmid, ite);
  return root;
}
Color color(Node::Ptr p) { return p ? p->color : BLACK; }
bool check2(Node::Ptr root) { return !root || root->color == BLACK; }
bool check4(Node::Ptr root) {
  struct Checker {
    bool check(Node::Ptr p) {
      if (p) {
        if (p->color == RED) {
          if (color(p->left) != BLACK || color(p->right) != BLACK) {
            return false;
          }
        }
        return check(p->left) && check(p->right);
      } else {
        return true;
      }
    }
  };
  return Checker().check(root);
}
bool check5(Node::Ptr root) {
  struct Checker {
    enum { UNKNOWN = -1 };
    int blacks = UNKNOWN;
    bool check(Node::Ptr p, int total = 0) {
      if (p) {
        return check(p->left, total + (color(p->left) == BLACK)) &&
               check(p->right, total + (color(p->right) == BLACK));
      } else {
        if (blacks == UNKNOWN) {
          blacks = total;
          return true;
        } else {
          return blacks == total;
        }
      }
    }
  };
  return Checker().check(root);
}
bool check(Node::Ptr root) {
  return check2(root) && check4(root) && check5(root);
}
int main() {
  cin >> K;
  while (K--) {
    vector<Node::Ptr> nodes;
    cin >> N;
    for (int i = 0; i < N; ++i) {
      auto node = Node::create();
      nodes.push_back(node);
      cin >> node->value;
      if (node->value < 0) {
        node->value = -node->value;
        node->color = RED;
      } else {
        node->color = BLACK;
      }
    }
    auto root = build(nodes.begin(), nodes.end());
    cout << (check(root) ? "Yes" : "No") << endl;
  }
  return 0;
}
} // namespace p1135

int main() { return p1135::main(), 0; }
