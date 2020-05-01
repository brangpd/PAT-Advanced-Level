
#include <bits/stdc++.h>
using namespace std;

namespace p1031 {
void calc(int N, int &outn1, int &outn2) {
  for (int n2 = 3;; ++n2) {
    int n1 = N + 2 - n2;
    if (n1 % 2) {
      continue;
    }
    n1 /= 2;
    if (n1 <= n2) {
      outn1 = n1;
      outn2 = n2;
      return;
    }
  }
}
enum { MATR = 85, MATC = 85 };
char mat[MATR][MATC];
void draw(const string &s, int n1, int n2) {
  auto it = s.begin();
  memset(mat, ' ', sizeof mat);
  for (int i = 0; i < n1; ++i) {
    mat[i][0] = *it++;
  }
  for (int i = 1; i < n2 - 1; ++i) {
    mat[n1 - 1][i] = *it++;
  }
  for (int i = n1 - 1; i >= 0; --i) {
    mat[i][n2 - 1] = *it++;
  }
  for (int i = 0; i < n1; ++i) {
    for (int j = 0; j < n2; ++j) {
      cout << mat[i][j];
    }
    cout << '\n';
  }
}
int main() {
  string s;
  cin >> s;
  int n1, n2;
  calc(s.size(), n1, n2);
  draw(s, n1, n2);
  return 0;
}
} // namespace p1031

int main() { return p1031::main(), 0; }
