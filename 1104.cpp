
#include <bits/stdc++.h>
using namespace std;

namespace p1104 {
int N;
enum { maxn = 100000 + 10 };
double arr[maxn];
int main() {
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> arr[i];
  }
  int64_t l = 1, r = N;
  double sum{};
  for (int i = 1; i <= N; ++i) {
    sum += (l++ * r--) * arr[i];
  }
  cout << fixed << setprecision(2) << sum;
  return 0;
}
} // namespace p1104

int main() { return p1104::main(), 0; }
