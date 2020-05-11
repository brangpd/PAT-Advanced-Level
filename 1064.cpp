
#include <bits/stdc++.h>
using namespace std;

namespace p1064 {
int N;
enum { maxn = 5000 };
int arr[maxn];
int ans[maxn];
void inorder(int treeidx, int &arridx) {
  if (treeidx <= N) {
    inorder(treeidx * 2, arridx);
    ans[treeidx] = arr[arridx++];
    inorder(treeidx * 2 + 1, arridx);
  }
}
int main() {
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> arr[i];
  }
  sort(arr + 1, arr + N + 1);
  int arridx = 1;
  inorder(1, arridx);
  bool first = true;
  for (int i = 1; i <= N; ++i) {
    if (first) {
      first = false;
    } else {
      cout << ' ';
    }
    cout << ans[i];
  }
  return 0;
}
} // namespace p1064

int main() { return p1064::main(), 0; }
