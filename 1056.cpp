
#include <bits/stdc++.h>
using namespace std;

/**
 * What is the f**king problem description saying???
 */
namespace p1056 {
int np, ng;
enum { maxn = 1005 };
int w[maxn * 2];
int order[maxn];
int main() {
  cin >> np >> ng;
  for (int i = 0; i < np; ++i) {
    cin >> w[i];
  }
  for (int i = 0; i < np; ++i) {
    cin >> order[i];
  }

  return 0;
}
} // namespace p1056

int main() { return p1056::main(), 0; }
