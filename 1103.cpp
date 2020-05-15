
#include <bits/stdc++.h>
using namespace std;

namespace p1103 {
using Int = int64_t;
Int N, K, P;
enum { maxn = 405, maxk = 405 };
Int f[maxn][maxk]; // f[i][j] => fact with n=i and k=j
Int s[maxn][maxk]; // s[i][j] => max sum of fact with n=i and k=j, 0 for not yet
                   // reached and -1 for not possible solution
/// DP routine.
/// \param n the sum of all terms.
/// \param k the number of terms left.
/// \param p the power.
/// \return true if the search with specified n and k is reachable.
bool dfs(Int n, Int k, const Int &p) {
  if (n < 0 || n < k) {
    return false;
  }
  if (k == 0) {
    return n == 0;
  }
  if (s[n][k] != 0) {
    return s[n][k] != -1;
  }
  s[n][k] = -1;
  for (Int fact = pow(n - k + 1, 1.0 / p); fact > 0; --fact) {
    Int m = pow(fact, p);
    if (dfs(n - m, k - 1, p)) {
      if (s[n - m][k - 1] + fact > s[n][k]) {
        s[n][k] = s[n - m][k - 1] + fact;
        f[n][k] = fact;
      }
    }
  }
  return s[n][k] != -1;
}
int main() {
  cin >> N >> K >> P;
  if (!dfs(N, K, P)) {
    cout << "Impossible\n";
  } else {
    vector<Int> ans;
    Int n = N, k = K;
    Int fact = f[n][k];
    while (fact) {
      Int m = pow(fact, P);
      ans.push_back(fact);
      fact = f[n -= m][--k];
    }
    cout << N;
    for (int i = 0, ie = ans.size(); i < ie; ++i) {
      cout << (i == 0 ? " = " : " + ") << ans[i] << '^' << P;
    }
  }

  return 0;
}
} // namespace p1103

int main() { return p1103::main(), 0; }
